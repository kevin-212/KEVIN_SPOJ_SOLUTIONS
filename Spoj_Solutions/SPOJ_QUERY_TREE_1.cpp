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
int in[10001];
int out[10001];
int cost[10001];
int anc[10001][15];
int timer,logn,mx;
pii edges[10001];
vector<vector<pii> >g;
void dfs(int u,int p)
{
	int v,w;
	in[u]=++timer;
	anc[u][0]=p;
	for(int i=1;i<=logn;i++)
	{
		if(anc[u][i-1]==-1)break;
		anc[u][i]=anc[anc[u][i-1]][i-1];
	}
	int sz=g[u].size();
	for(int i=0;i<sz;i++)
	{
		v=g[u][i].first;
		w=g[u][i].second;
		
		if(v!=p)
		dfs(v,u),cost[v]=w;;
	}
	out[u]=timer;
}

bool upper(int p,int q)
{
	return (in[q]>=in[p] && out[q]<=out[p]);
}


int lca(int a,int b)
{
	if(upper(a,b))return a;
	else if(upper(b,a))return b;
	for(int i=logn;i>=0;i--)
	{
		if(anc[a][i]>0)
		{
			if(!upper(anc[a][i],b))
			a=anc[a][i];
		}
		
	}
	return anc[a][0];
}
bool dfs1(int l,int u,int p)
{
	if(l==u)
	return true;
	int sz,v;
	sz=g[l].size();
	for(int i=0;i<sz;i++)
	{
		v=g[l][i].first;
		if(v!=p)
		{
	
			if(dfs1(v,u,l))
			{
				mx=max(mx,cost[v]);
				return true;
			}
		}
	}
	return false;
}
int main()
{
	int t,n,m,i,j,k,l,u,v,w;
	char str[10];
	rd(t);
	while(t--)
	{
		
		rd(n);
		logn=1;
		timer=0;
		memset(anc,-1,sizeof(anc));
		
		while((1<<logn)<=n)logn++;
		g.clear();
		g.resize(n+1);
		for(i=1;i<n;i++)
		{
			rd(u);
			rd(v);
			rd(w);
			g[u].push_back(pii(v,w));
			g[v].push_back(pii(u,w));
			edges[i]=pii(u,v);
		}
		dfs(1,-1);
		while(true)
		{
			scanf("%s",str);
			if(str[0]=='D')
			break;
			if(str[0]=='C')
			{
				rd(i);
				rd(w);
				u=edges[i].first;
				v=edges[i].second;
				if(upper(u,v))
				cost[v]=w;
				else
				cost[u]=w;
			}
			else
			{
				rd(u);
				rd(v);
				l=lca(u,v);
				mx=0;
				dfs1(l,u,anc[l][0]);
				dfs1(l,v,anc[l][0]);
				pd(mx);
			}
		}
	}
}
