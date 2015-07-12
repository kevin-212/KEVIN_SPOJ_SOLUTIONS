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
//	pc('\n');
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
int n,i,j,k,temp,temp1,mx,cnt;
pii dp[1<<16][16];
int arr[16];
void solve()
{
	for(i=0;i<1<<n;i++)
	for(j=0;j<16;j++)
	dp[i][j]=pii(-1000000,0);
	mx=0,cnt=0;
	for(i=0;i<n;i++)
	{
		dp[1<<i][i]=pii(2*arr[i],1);
	}
	for(i=0;i<1<<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(dp[i][j].first==-1000000)
			continue;
			
			for(k=0;k<n;k++)
			{
				if((i>>k)&1)
				continue;
				temp=2*arr[k]-2*min(arr[j],arr[k]);
				if(dp[i|(1<<k)][k].first<dp[i][j].first+temp)
				dp[i|(1<<k)][k]=pii(dp[i][j].first+temp,dp[i][j].second);
				else if(dp[i|(1<<k)][k].first==dp[i][j].first+temp)
				dp[i|(1<<k)][k].second+=dp[i][j].second;
				
			}
		}
	}
	temp=(1<<n)-1;
	for(i=0;i<n;i++)
	{
		if(mx<dp[temp][i].first)
		mx=dp[temp][i].first,cnt=dp[temp][i].second;
		else if(mx==dp[temp][i].first)
		cnt+=dp[temp][i].second;
	}
	pd(mx+2*n);
	pc(' ');
	pd(cnt);
	pc('\n');
}
int main()
{
	while(true){
	rd(n);
	if(n==0)
	break;
	for(i=0;i<n;i++)
	rd(arr[i]);
	solve();
	
	}
	
	
}
