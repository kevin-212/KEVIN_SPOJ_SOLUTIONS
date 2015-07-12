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
vector<vector <int > >graph;
int  visited[10001];


bool dfs(int u)
{
	int sz=graph[u].size(),v;
	for(int i=0;i<sz;i++)
	{
		v=graph[u][i];
		if(visited[v]==0)
		{
			visited[v]=-visited[u];
			dfs(v);
		}
		else if(visited[v]==visited[u])
		return false;
	}
	return true;
}
int main()
{
	int t,n,e,u,v,i,j,k;
	rd(t);
	while(t--)
	{
		graph.clear();
		rd(n);
		fill(visited,visited+n,0);
		graph.resize(n);
		rd(e);
		for(i=0;i<e;i++)
		{
			rd(u);
			rd(v);
			graph[u].push_back(v);
			graph[v].push_back(u);
			
		}
		for(i=0;i<n;i++)
		{
			if(visited[i]==0)
			{
				visited[i]=1;
				if(!dfs(i))
				break;
			}
		}
		if(i==n)
		printf("BICOLORABLE.\n");
		else
		printf("NOT BICOLORABLE.\n");
	}
}
