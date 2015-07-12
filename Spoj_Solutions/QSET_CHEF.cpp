#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pii pair<int,int>
using namespace std;
inline void rd(int &x)
{
	x=0;
	register int c=gc();
	for(;c<48 || c>57;c=gc());
	for(;c>47 && c<58;c=gc()){
		x=(x<<1)+(x<<3)+c-48;
	}
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
	pc(c[k--]);
	pc('\n');
}
bool cmp(int  a,int b)
{
	return a>b;
}
struct node{
	int countp[3];
	int counts[3];
	int total,ans;
	
	
};
node st[400004];
int arr[100001];
void build(int sl,int sr,int ind)
{
	if(sl==sr)
	{
		int n=arr[sl];
		st[ind].countp[n]=1;
		st[ind].counts[n]=1;
		st[ind].total=n;
		st[ind].ans+=(n==0);
		return;
	}
	int m=(sl+sr)/2;
	build(sl,m,2*ind+1);
	build(m+1,sr,2*ind+2);
	node left=st[2*ind+1];
	node right=st[2*ind+2];
	st[ind].total=(left.total+right.total)%3;
	st[ind].countp[0]=left.countp[0]+right.countp[(3-left.total)%3];
	st[ind].countp[1]=left.countp[1]+right.countp[(4-left.total)%3];
	st[ind].countp[2]=left.countp[2]+right.countp[(5-left.total)%3];
	st[ind].counts[0]=right.counts[0]+left.counts[(3-right.total)%3];
	st[ind].counts[1]=right.counts[1]+left.counts[(4-right.total)%3];
	st[ind].counts[2]=right.counts[2]+left.counts[(5-right.total)%3];
	int ans=left.ans+right.ans;
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	if((i+j)%3==0)
	ans+=(left.counts[i]*right.countp[j]);
	st[ind].ans=ans;
}

node find(int sl,int sr,int l,int r,int ind)
{
	if(sl==l && sr==r)
	return st[ind];
	int m=(sl+sr)/2;
	if(r<=m)
	return find(sl,m,l,r,2*ind+1);
	if(l>m)
	return find(m+1,sr,l,r,2*ind+2);
	node left=find(sl,m,l,m,2*ind+1);
	node right=find(m+1,sr,m+1,r,2*ind+2);
	node temp;
	
		temp.total=(left.total+right.total)%3;
	temp.countp[0]=left.countp[0]+right.countp[(3-left.total)%3];
	temp.countp[1]=left.countp[1]+right.countp[(4-left.total)%3];
	temp.countp[2]=left.countp[2]+right.countp[(5-left.total)%3];
	temp.counts[0]=right.counts[0]+left.counts[(3-right.total)%3];
	temp.counts[1]=right.counts[1]+left.counts[(4-right.total)%3];
	temp.counts[2]=right.counts[2]+left.counts[(5-right.total)%3];
	int ans=left.ans+right.ans;
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	if((i+j)%3==0)
	ans+=(left.counts[i]*right.countp[j]);
	temp.ans=ans;
	return temp;
}
void update(int sl,int sr,int l,int val,int ind)
{
	if(sl==l && sr==l)
	{
		
		st[ind].countp[0]=st[ind].countp[1]=st[ind].countp[2]=st[ind].counts[0]=st[ind].counts[1]=st[ind].counts[2]=0;
		st[ind].countp[val]=1;
		st[ind].counts[val]=1;
		st[ind].total=val;
		st[ind].ans=(val==0);
		return;
	}
	int m=(sl+sr)/2;
if(l<=m)
update(sl,m,l,val,2*ind+1);
else
update(m+1,sr,l,val,2*ind+2);
	
node left=st[2*ind+1];
	node right=st[2*ind+2];
	st[ind].total=(left.total+right.total)%3;
	st[ind].countp[0]=left.countp[0]+right.countp[(3-left.total)%3];
	st[ind].countp[1]=left.countp[1]+right.countp[(4-left.total)%3];
	st[ind].countp[2]=left.countp[2]+right.countp[(5-left.total)%3];
	st[ind].counts[0]=right.counts[0]+left.counts[(3-right.total)%3];
	st[ind].counts[1]=right.counts[1]+left.counts[(4-right.total)%3];
	st[ind].counts[2]=right.counts[2]+left.counts[(5-right.total)%3];
	int ans=left.ans+right.ans;
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	if((i+j)%3==0)
	ans+=(left.counts[i]*right.countp[j]);
	st[ind].ans=ans;	
	
	
	
}
int main()
{
	
	int n,m,i,j,k,l,r;
	
	rd(n);
	rd(m);
	for(i=0;i<n;i++)
	rd(j),arr[i]=j%3;
	build(0,n-1,0);
	while(m--)
	{
		rd(k);
		rd(l);
		rd(r);
		if(k==1){
		
		l--,r--;
		node ans=find(0,n-1,l,r,0);
		pd(ans.ans);
		}
		else
		{
			l--;
			r%=3;
			update(0,n-1,l,r,0);
		}
	}
}
