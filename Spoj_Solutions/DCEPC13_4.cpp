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
int gcd(int a,int b)
{
	if(b==0)
	return a;
	return gcd(b,a%b);
}
int main()
{
	int n,ans;
	int arr[101];
	rd(n);
	int i,j,k;
	int dp[n+1][n+1];
	int gcdp[n+1][n+1];
	memset(dp,1,sizeof dp);
	memset(gcdp,0,sizeof gcdp);
	for(i=1;i<=n;i++)
	{
		rd(arr[i]);
		gcdp[i][i]=arr[i];
	}
	ans=1;
	for(k=2;k<=n;k++)
	{
		for(i=1;i<=n-k+1;i++)
		{
			j=i+k-1;
			if(dp[i][j-1] && dp[i+1][j]){
			gcdp[i][j]=gcd(arr[i],arr[j]);
			if(gcdp[i][j]==1)
			ans=max(ans,j-i+1);
			else
			dp[i][j]=0;
			}
			else
			dp[i][j]=0;
		
		}
		
	}
	pd(ans);

	
}
