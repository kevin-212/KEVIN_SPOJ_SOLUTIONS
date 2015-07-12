#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pii pair<int,int>
using namespace std;
inline void rdl(int &x)
{
	x=0;
	bool check=false;
	register int c;
	do{
		c=gc();
		if(c=='-')
		check=true;
	}while(c<48 || c>57);
	for(;c>47 && c<58;c=gc()){
		x=(x<<1)+(x<<3)+c-48;
	}
	if(check)
	x=-x;
}
inline void rd(int &x)
{
	x=0;
	bool check=false;
	register int c=gc();
	for(;c<48 || c>57;c=gc());
	for(;c>47 && c<58;c=gc()){
		x=(x<<1)+(x<<3)+c-48;
	}

}
inline void pd(int x)
{
	char c[11];
	bool check=false;
	int k=-1;
	if(x<0)
	check=true,x=-x;
	do
	{
		c[++k]=x%10+48;
		x/=10;
	}while(x);
	if(check)
	c[++k]='-';
	while(k>=0)
	pc(c[k--]);
	//pc('\n');
}
inline void pdl(long long int x)
{
	char c[21];
	bool check=false;
	int k=-1;
	if(x<0)
	check=true,x=-x;
	do
	{
		c[++k]=x%10+48;
		x/=10;
	}while(x);
	if(check)
	c[++k]='-';
	while(k>=0)
	pc(c[k--]);
	pc('\n');
}
bool cmp(int  a,int b)
{
	return a>b;
}
int arr[100001];
struct node{
	int mn,mx;
};
node st[400004];

int gcd(int a,int b)
{
	if(b==0)
	return a;
	return gcd(b,a%b);
}

void build(int sl,int sr,int ind)
{
	if(sl==sr)
	{
		st[ind].mn=st[ind].mx=arr[sl];
		return;
	}
	int mid=(sl+sr)/2;
	build(sl,mid,2*ind+1);
	build(mid+1,sr,2*ind+2);
	
	st[ind].mx=max(st[2*ind+1].mx,st[2*ind+2].mx);
	st[ind].mn=gcd(st[2*ind+1].mn,st[2*ind+2].mn);
	
}
node query(int sl,int sr,int l,int r,int ind)
{
	if(sl==l && sr==r)
	return st[ind];
	int mid=(sl+sr)/2;
	
	if(r<=mid)
	return query(sl,mid,l,r,2*ind+1);
	if(l>mid)
	return query(mid+1,sr,l,r,2*ind+2);
	node temp,left,right;
	left=query(sl,mid,l,mid,2*ind+1);
	right=query(mid+1,sr,mid+1,r,2*ind+2);
	
	temp.mx=max(left.mx,right.mx);
	temp.mn=gcd(left.mn,right.mn);
	return temp;
}
int main()
{
	int n,q,l,r,i;
	rd(n);
	rd(q);
	for(i=0;i<n;i++)
	rd(arr[i]);
	build(0,n-1,0);
	while(q--)
	{
		rd(l);
		rd(r);
		l--,r--;
		node temp=query(0,n-1,l,r,0);
		pd(temp.mx);
		pc(' ');
		pd(temp.mn);
		pc('\n');
		
	}
	
}
