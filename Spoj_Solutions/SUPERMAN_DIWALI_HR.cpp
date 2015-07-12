#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pii pair<int,int>
using namespace std;
inline void rdl(long long int &x)
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
inline void pd(long long int x)
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
int arr[1901][1901];
int dp[1901][1901];
int mx[1901];
int main()
{
	
	int n,h,H,u,i,j,k;
	rd(n);
	rd(h);
	rd(H);
	

	
	for(i=1;i<=n;i++)
	{
		rd(u);
		for(j=0;j<u;j++)
		{
		rd(k);
		arr[i][k]++;
		}
	}
	
	
	
	for(i=1;i<=n;i++)
	{
		j=0;
		for(k=1;k<=H;k++)
		{
		j+=arr[i][k];
		dp[i][k]=j;
		mx[k]=max(mx[k],j);
		}
	}
	for(j=H+1;j<=h;j++)
	{
	
	for(i=1;i<=n;i++)
	{
		dp[i][j]=arr[i][j]+max(dp[i][j-1],mx[j-H]);
		mx[j]=max(mx[j],dp[i][j]);
	}
	}
	pd(mx[h]);
}
