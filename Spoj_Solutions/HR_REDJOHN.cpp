#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pii pair<int,int>
#define MOD 1000000007
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
int dp[41];
bool check[700000];
int cnt[700000];
int main()
{
		int i,j,k,t,n,sum,l;
		dp[0]=dp[1]=dp[2]=dp[3]=1;
		for(i=4;i<=40;i++)
		dp[i]=dp[i-1]+dp[i-4];
			
			check[0]=check[1]=true;
			k=0;
			for(i=2;i<=700000;i++)
			{
				if(!check[i])
				{

					k++;
					for(j=i;j<=700000;j+=i)
						check[j]=true;
				}
				cnt[i]=k;
			}
			rd(t);
			while(t--)
			{
				rd(n);	
				pd(cnt[dp[n]]);
				
			}
			
	
}
