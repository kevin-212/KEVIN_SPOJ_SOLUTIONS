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
int f[100001];
int p[100001];
int n;
bool visited[100001];
void dfs(int u,long long int& sum)
{
	visited[u]=true;
	sum+=p[u];
	if(!visited[f[u]])
	dfs(f[u],sum);
	
	if(sum<=0)
	visited[u]=false;
	
}
long long int func()
{
	int i;
	long long int sum,ans=0;
	for(i=0;i<n;i++)
	{
		if(!visited[i])
		{
			sum=0;
			dfs(i,sum);
			cout<<sum<<endl;
			if(sum>0)
			ans+=sum;		
		}
		
		
		
	}
	return ans;
	
}
int main()
{
	int i,j,k,t;
	rd(t);
	while(t--)
	{
		rd(n);
		fill(visited,visited+n,false);
		for(i=0;i<n;i++)
		rd(j),f[i]=j-1;
		for(i=0;i<n;i++)
		rdl(p[i]);
		pdl(func());
	}
}
