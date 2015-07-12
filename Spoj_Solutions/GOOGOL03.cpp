#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pii pair<int,int>
const int INF=99999999;
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


vector<vector<pii > >g;
int dist[200001];
int parent[200001];
bool visited[200001];
int cnt[200001];
struct cmp1{
	
	bool operator()(pii a,pii b)
	{
		return a.first>b.first;
	}
};

bool cmp(int  a,int b)
{
	return cnt[a]>cnt[b];
}
int main()
{
	int n,m,c,i,j,k,u,v,sz,r;
	rd(n);
	rd(r);
	g.resize(n+1);
	
	for(i=0;i<r;i++)
	{
		rd(u);
		rd(v);
		u--,v--;
		rd(c);
		g[u].push_back(pii(c,v));
		g[v].push_back(pii(c,u));
		
	}
	fill(dist,dist+n+1,INF);
	priority_queue<pii,vector<pii>,cmp1>q;
	q.push(pii(0,0));
	dist[0]=0;
	parent[0]=0;
	while(!q.empty())
	{
		u=q.top().second;
	
		q.pop();
		if(visited[u])
		continue;
		visited[u]=true;
		sz=g[u].size();
		for(i=0;i<sz;i++)
		{
			v=g[u][i].second;
			c=g[u][i].first;
			if(!visited[v] && c<dist[v])
			dist[v]=c,q.push(pii(c,v)),parent[v]=u;
		}
	}
	
	for(i=1;i<=n;i++)
	{
		dist[i]=i;
		cnt[parent[i]]++;
	}
	cnt[0]--;
	for(i=0;i<n;i++)
	
	sort(dist,dist+n,cmp);
	for(i=0;i<n;i++)
	pd(dist[i]+1);
}
