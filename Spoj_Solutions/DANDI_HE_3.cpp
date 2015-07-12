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
const long long int MOD=1000000007;


int main()
{
	int t,n,i,j,k,x;
	long long int ans,temp;
	rd(t);
	while(t--)
	{
		rd(n);
		ans=0;
		rd(x);
		for(i=1;i<n;i++)
		{
			rd(j);
			k=j/x;
			x=j;
			if(k&1)
			{
				temp=1LL*(k+1)/2LL;
				temp=(1LL*temp*k)%MOD;
			}
			else
			{
				temp=1LL*k/2;
				temp=(1LL*temp*(k+1))%MOD;
			}
			
			ans=(ans+temp)%MOD;
		}
		if(ans&1)
		{
			temp=(ans+1)/2LL;
			temp=(1LL*temp*ans)%MOD;
			
		}
		else
		{
			temp=ans/2LL;
			temp=(1LL*temp*(ans+1))%MOD;
			
		}
		
		pdl(temp);
	}
}

