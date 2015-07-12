#include<bits/stdc++.h>
using namespace std;
inline void rd(int &x)
{
	x=0;
	bool neg=false;
	register int c;
	do{
		c=getchar_unlocked();
		if(c=='-')
		neg=true;
	}while(c<48 || c>57);
	
	for(;c>47 && c<58;c=getchar_unlocked()){
		x=(x<<1)+(x<<3)+c-48;
	}
	if(neg)
	x=-x;
}

inline void pd(int x)
{
	char c[11];
	int k=-1;
	do
	{
		c[++k]=x%10+48;
		x/=10;
	}while(x);
	while(k>=0)
	putchar_unlocked(c[k--]);
	putchar_unlocked('\n');
}
bool cmp(int  a,int b)
{
	return a>b;
}
struct node{
	int lfrq,mfrq,rfrq;
};

node st[400004];
int arr[100001];
void build(int sl,int sr,int ind)
{
	if(sl==sr)
	{
			st[ind].lfrq=st[ind].mfrq=st[ind].rfrq=1;
			return;
	}
	int m=(sl+sr)/2;
	build(sl,m,2*ind+1);
	build(m+1,sr,2*ind+2);
	if(arr[m]==arr[m+1])
	{
		st[ind].lfrq=st[2*ind+1].lfrq+st[2*ind+2].lfrq*(arr[sl]==arr[m]);
		st[ind].rfrq=st[2*ind+2].rfrq+st[2*ind+1].rfrq*(arr[sr]==arr[m]);
		st[ind].mfrq=max(st[2*ind+1].mfrq,max(st[2*ind+2].mfrq,st[2*ind+1].rfrq+st[2*ind+2].lfrq));
	}
	else
	{
		st[ind].lfrq=st[2*ind+1].lfrq;
		st[ind].rfrq=st[2*ind+2].rfrq;
		st[ind].mfrq=max(st[2*ind+1].mfrq,st[2*ind+2].mfrq);
	}
}
int query(int sl,int sr,int l,int r,int ind)
{

	if(l==sl && r==sr)
	return st[ind].mfrq;
	int m=(sl+sr)/2;
	if(r<=m)
	return query(sl,m,l,r,2*ind+1);
	if(l>m)
	return query(m+1,sr,l,r,2*ind+2);
	
	int left=query(sl,m,l,m,2*ind+1);
	int right=query(m+1,sr,m+1,r,2*ind+2);
	if(arr[m]==arr[m+1])
	{
		int temp=min(st[2*ind+1].rfrq,m-l+1)+min(st[2*ind+2].lfrq,r-m);
		return max(temp,max(left,right));
	}
	else
	return max(left,right);
}
int main()
{
	int n,q;
	
	//rd(n);
	
	while(scanf("%d",&n)==1 && n){
	//scanf("%d",&q);
	rd(q);
	int i,j,k;
	for(i=0;i<n;i++)
	rd(arr[i]);
	//scanf("%d",&arr[i]);
	build(0,n-1,0);
	while(q--)
	{
		//scanf("%d%d",&j,&k);
		rd(j);
		rd(k);
		j--,k--;
		//printf("%d\n",query(0,n-1,j,k,0));
		pd(query(0,n-1,j,k,0));
	}
	}
}
