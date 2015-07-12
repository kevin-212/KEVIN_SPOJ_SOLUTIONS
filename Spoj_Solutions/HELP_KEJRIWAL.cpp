#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pii pair<int,int>
#define MOD 1000000007
using namespace std;
const long long int MAX=(1LL<<32)-1;
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
	pc('\n');
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
int n,cnt,m;
//int h[MAX];
 int arr[501];
int dp[500][1001];
int dp1[500][1001];
/*int func(int start,int sum)
{
	if(sum<0)
	return 0;
	if(start==n)
	{
		if(sum==0)
		return 1;
		return 0;
	}
	if(dp[start][sum]!=0)
	return dp[start][sum];
	int temp=0;
	for(int i=0;i<31;i++)
		{
		temp+=func(start+1,sum);
		if(temp>=MOD)
		temp-=MOD;
		temp+=func(start+1,sum-(arr[start]^(1<<i)));
		if(temp>=MOD)
		temp-=MOD;
		}
	return dp[start][sum]=temp;
}*/
int main()
{
	int t,i,j,k,temp;

	rd(t);
	long long int sum=0,k1;
	while(t--)
	{
		memset(dp,0,sizeof dp);
	
		cnt=0;
		sum=0;
		rd(n);	
		rd(m);
		for(i=1;i<=n;i++)
		rd(arr[i]);
		//arr[i]=i;
		//pd(func(0,m));
	
		for(j=1;j<=n;j++){
			dp[j][0]=32;
		for(i=0;i<32;i++){
			k1=(arr[j]^(1LL<<i));
			if(k1<=m)
			dp[j][k1]++;
			sum+=k1;
		}	
	}
	for(j=0;j<=m;j++)
	dp1[1][j]=dp[1][j];
	
	for(i=2;i<=n;i++)
	{
		
		for(j=0;j<=m;j++)
		{
			temp=0;
			for(k=0;k<=j;k++)
			{
			//	cout<<i<<" "<<j<<" "<<k<<" "<<dp1[i-1][j-k]<<" "<<dp[i][k]<<endl;
				temp=(temp+1LL*dp[i][k]*dp1[i-1][j-k])%MOD;
			}
			dp1[i][j]=temp;
			
		}
	}
	
		pd(dp1[n][m]);
		printf("%.07f\n",(sum/64.00));
	}
}
