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
int n,m,p;
vector<vector<int> >g;
int assign[100004];
int dist[100004];
const int INF=99999999;
queue<int>Q;
bool bfs()
{
	int u,v,i,sz;
	for(i=1;i<=n;i++)
	{
		if(assign[i]==0)
		Q.push(i),dist[i]=0;
		else
		dist[i]=INF;
	}
	dist[0]=INF;
	while(!Q.empty())
	{
		u=Q.front();
		Q.pop();
		sz=g[u].size();
		for(i=0;i<sz;i++)
		{
			v=g[u][i];
			if(dist[assign[v]]==INF)
			dist[assign[v]]=dist[u]+1,Q.push(assign[v]);
		}
		
	}
	return (dist[0]!=INF);
}
bool dfs(int u)
{
	if(u==0)
	return true;
	int sz=g[u].size();
	int i,v;
	for(i=0;i<sz;i++)
	{
		v=g[u][i];
		if(dist[assign[v]]==dist[u]+1)
		{
			
			if(dfs(assign[v]))
			{
				assign[v]=u;
				assign[u]=v;		
				return true;
			}
		}
		
		
	}
	dist[u]=INF;
	return false;
	
}

void hopkraft()
{
	int matching=0,i;
	while(bfs())
	{
		
		for(i=1;i<=n;i++)
		{
			if(assign[i]==0 && dfs(i))
			matching++;
		}
	}
	pd(matching);
	
}
int main()
{
	int i,u,v;
	
	rd(n);
	rd(m);
	rd(p);
	g.resize(n+m+1);
	for(i=0;i<p;i++)
	{
		rd(u);
		rd(v);
		g[u].push_back(v+n);
		
		
	}
	hopkraft();
}
