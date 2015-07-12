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
string arr[2000];
int dist[10010];
int n;
int assign[3000];
vector<vector <int> >g;
const int INF=9999999;
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
	return dist[0]!=INF;
}

bool dfs(int u)
{
	int v,i,sz;
	if(u==0)
	return true;
	sz=g[u].size();
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

void hopkroft()
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
	
	pd(n-matching/2);
}
int main()
{
	int i,j,k,lo,high,l;

	while(scanf("%d",&n)==1)
	{
	
	memset(assign,0,sizeof assign);
	g.clear();
	g.resize(2*n+10);
	for(i=1;i<=n;i++)
	cin>>arr[i];
	string a;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			
			a=arr[i]+arr[j];
			l=a.length();
			lo=0,high=l-1;
			while(lo<=high)
			{
				if(a[lo]!=a[high])
				break;
				lo++,high--;
			}
			if(lo>high)
			g[i].push_back(j+n),g[j].push_back(i+n);
			else
			{
				a=arr[j]+arr[i];
				lo=0,high=l-1;
				while(lo<=high)
				{
					if(a[lo]!=a[high])
					break;
					lo++,high--;
				}
			if(lo>high)
			g[i].push_back(j+n),g[j].push_back(i+n);
				
			}
		}
	}
	
	hopkroft();
	}
}
