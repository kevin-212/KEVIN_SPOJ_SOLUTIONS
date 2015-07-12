#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pii pair<int,int>
#define MOD 1000000000
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
int ncr[2002][2002];
int dp[2002][2002];
int main()
{
	int i,j,k,l,n,m,t,a,b;
	for(i=0;i<=2001;i++)
	ncr[i][0]=1;
	for(i=1;i<=2001;i++)
	for(j=1;j<=2001;j++)
	ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%MOD;
	dp[1][0]=1;
	dp[1][1]=1;
	for(i=2;i<=2001;i++)
	{
		a=0;
		for(j=0;j<i;j++)
			{
			for(k=0;k<=j;k++)
			dp[i][j]=(dp[i][j]+dp[i-1][j-k])%MOD;
			a=(a+dp[i][j])%MOD;
			}
			dp[i][i]=a;
	
	}
	rd(t);
	long long int ans;
	while(t--)
	{
		ans=0;
		rd(n);
		rd(m);
		for(i=0;i<=)
		
		
	}
	
	
	
}
