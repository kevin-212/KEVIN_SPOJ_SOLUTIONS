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
int to[60010];
int prev[60010];
int flow[60010];
int cap[60010];
int last[30010];
int pos[30010];
int n,m,u,v,c;
int INF=1000000009;
int Q[60010];
int dist[30001];
int baby[16];
int queen[16];
bool bfs()
{
	int start=0,end=0,u,v,i;
	fill(dist,dist+n+1,-1);
	dist[1]=0;
	Q[end++]=1;
	while(start<end)
	{
		u=Q[start++];
		for(i=last[u];i>=0;i=prev[i])
		{
			v=to[i];
			if(dist[v]<0 && flow[i]<cap[i])
			dist[v]=dist[u]+1,Q[end++]=v;	
		}
	}
	for(i=1;i<=n;i++)
	cout<<dist[i]<<" ";
	cout<<endl;
	return dist[n]>=0;
	
}

int dfs(int u,int lim)
{
	if(u==n)
	return lim;
	int v,f,f1;
	for(int&i=pos[u];i>=0;i=prev[i])
	{
		v=to[i];
		if(dist[v]==dist[u]+1)
		{
			f=cap[i]-flow[i];
			if(f)
			{
				if(f>lim)
				f=lim;
				f1=dfs(v,f);
				if(f1)
				{
				flow[i]+=f1,flow[i^1]-=f1;	
				return f1;
				}
			}
		}
		
	}
	
	return 0;
}
void maxflow()
{
	long long int ans=0;
	int f,i;
while(bfs())
{
	for(i=1;i<=n;i++)
	pos[i]=last[i];
	while((f=dfs(1,INF)))
	ans+=f;
}	

	pdl(ans);
	
}
int main()
{
	int i,no;
	int k;
	while(true){
	no=0;
	rd(n);
	if(n==0)
	break;
	for(i=0;i<n;i++)
	rd(baby[i]);
	for(i=0;i<n;i++)
	rd(queen[i]);
	fill(last,last+2*n+1,-1);
	k=2*n-1;
	for(i=1;i<=n;i++)
	{
		
		
		flow[no]=0;
		to[no]=i;
		cap[no]=k;
		prev[no]=last[0];
		last[0]=no++;
		
		flow[no]=0;
		to[no]=2*n+1;
		cap[no]=k;
		prev[no]=last[v];
		last[v]=no++;
		
		
	}
	
	for(i=0;i<m;i++)
	{
		rd(u);
		rd(v);
		rd(c);
		if(u==v)
		continue;
		flow[no]=0;
		to[no]=v;
		cap[no]=c;
		prev[no]=last[u];
		last[u]=no++;
		
		flow[no]=0;
		to[no]=u;
		cap[no]=c;
		prev[no]=last[v];
		last[v]=no++;
	}
	maxflow();
	
}
