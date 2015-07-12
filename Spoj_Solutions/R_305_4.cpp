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
int ans[100001];
int st[400004];
void build(int sl,int sr,int  ind,int size)
{
	if(sl==sr)
	{
	ans[size]=max(ans[size],arr[sl]);
	st[ind]=arr[sl];
	return ;
	}
	int mid=(sl+sr)/2;
	build(sl,mid,2*ind+1,size/2+((size%2)!=0));
	build(mid+1,sr,2*ind+2,size/2);
	st[ind]=min(st[2*ind+1],st[2*ind+2]);
	ans[size]=max(ans[size],st[ind]);

}


int main()
{
	int n,i,j,k;
	rd(n);
	for(i=0;i<n;i++)
	rd(arr[i]);
	memset(st,1000000001,sizeof(st));
	build(0,n-1,0,n);
	for(i=1;i<=n;i++)
	pd(ans[i]),pc(' ');
	pc('\n');
	
}
