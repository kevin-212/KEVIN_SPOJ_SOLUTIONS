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
long long int dp[100020][11];
int main()
{
	int n,q;
	int arr[100001];
	
	rd(n);
	rd(q);
	int i,j,k;
	for(i=1;i<=n;i++)
	rd(arr[i]);
	long long int sum;
	for(i=1;i<=10;i++)
	{
		
		for(j=n;j>0;j--)
		{
			
			dp[j][i]=arr[j]+dp[j+i][i];
		}
		
	}
	int temp;
	while(q--)
	{
		rd(i);
		rd(j);
		rd(k);
		temp=j;
		temp-=i;
		temp=(int)ceil((1.00*temp)/k);
		temp=(i+(k*temp));
		if(temp!=j)
		pd(dp[i][k]-dp[temp][k]);
		else
		pd(dp[i][k]-dp[j+k][k]);
		
		
	}
	
}
