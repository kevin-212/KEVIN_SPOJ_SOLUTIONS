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
vector< vector<pii > >graph;
bool visited[50001];
int temp[50001];

void dfs(int u,int sum)
{
	visited[u]=true;
	temp[u]=sum;
	int sz=graph[u].size();
	int v;
	
	for(int i=0;i<sz;i++)
	{
		v=graph[u][i].first;
		if(!visited[v])
		dfs(v,sum+graph[u][i].second);
	}
	visited[u]=false;
}

int main()
{
	
	int t,n,i,j,k,u,v,l,mx;
	rd(t);
	while(t--)
	{
		
		rd(n);
		graph.clear();
		graph.resize(n+1);
		fill(temp,temp+n+1,0);
		mx=0;
		for(i=1;i<n;i++)
		{
			rd(u);
			rd(v);
			rd(l);
			graph[u].push_back(pii(v,l));
			graph[v].push_back(pii(u,l));
		}
		dfs(1,0);
		for(i=1;i<=n;i++)
		{
			if(mx<temp[i])
			mx=temp[i],j=i;	
		}	
		dfs(j,0);	
		for(i=1;i<=n;i++)
		{
			if(mx<temp[i])
			mx=temp[i];	
		}	
		pd(mx);
	}
}
