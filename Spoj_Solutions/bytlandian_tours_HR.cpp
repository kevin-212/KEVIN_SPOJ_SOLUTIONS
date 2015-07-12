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
vector< vector<int > >graph;
bool visited[10001];
int parent[10001];
int ans=0,n;
const int MOD =1000000007;
void dfs(int u)
{
	int i,v,sz,p;
	visited[u]=true;
	if(parent[u]>0)
	{
	p=parent[parent[u]];
	sz=graph[p].size();
	for(i=0;i<sz;i++)
	graph[p].push_back(u),graph[u].push_back(p);
	}
	sz=graph[u].size();
	for(i=0;i<sz;i++)
	{
		v=graph[u][i];
		if(!visited[v])
		parent[v]=u,dfs(v);
	}
		
	
	
}

void func(int u,int count)
{
	if(count==n)
	{
		if(u==0)
		{
			ans++;
			if(ans>=MOD)
			ans-=MOD;
		}
		
		return;
	}
	int sz=graph[u].size();
	int v;
	for(int i=0;i<sz;i++)
	{
		v=graph[u][i];
		if(v==0 && count!=n-1)
		continue;
		
		if(!visited[v])
		{
			visited[v]=true;
			func(v,count+1);
			visited[v]=false;
			
		}
	}
	
}
int main()
{
	int t,i,u,v,j,sz;
	rd(t);
	
	while(t--)
	{
		rd(n);
		graph.clear();
		graph.resize(n);
		for(i=1;i<n;i++)
		{
			rd(u);
			rd(v);
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		parent[0]=-1;
		
		dfs(0);
		fill(visited,visited+n,false);
		for(i=0;i<n;i++)
		{
			sz=graph[i].size();
			for(j=0;j<sz;j++)
			cout<<graph[i][j]<<" ";
			cout<<endl;
		}
		func(0,0);
		pd(ans);
		ans=0;
		
		
		
	}
}
