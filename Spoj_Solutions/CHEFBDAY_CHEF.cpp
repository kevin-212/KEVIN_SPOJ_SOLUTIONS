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
pii arr[100001];
int dp[100001];
int main()
{
	int t,i,j,a,l,n,q,till;
	dp[0]=0;
	rd(t);
	while(t--)
	{
		rd(n);
		rd(q);
		for(i=0;i<n;i++)
		rd(a),rd(l),arr[i]=pii(a,l);
		
		sort(arr,arr+n);
		till=arr[n-1].second;
		j=0;
		fill(dp,dp+till+1,0);
		for(i=1;i<=till;i++)
		{
			dp[i]+=dp[i-1];
			while(arr[j].first==i)
			{
				dp[i]++;
				dp[(arr[j].second)+1]--;
				//cout<<i<<" "<<dp[i]<<" "<<arr[j].second+1<<" "<<dp[arr[j].second+1]<<endl;
				j++;
				//if(j==n)
				//break;
			}
			
		}
	while(q--)
	{
		rd(a);
		if(a>till)
		pd(0);
		else
		pd(dp[a]);
	}
	}
}
