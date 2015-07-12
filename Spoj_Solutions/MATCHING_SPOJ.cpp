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
vector< vector <int > >g;
int assign[50001];


bool func(bool *visited,int u)
{
	
	int sz=g[u].size();
	int i,v;
	for(i=0;i<sz;i++)
	{
		
		v=g[u][i];
		if(!visited[v])
		{
		
		visited[v]=true;
		
		if(assign[v]==0 || func(visited,assign[v]))
		{
			assign[v]=u;
			
			return true;
		}
		
		}
	}
	
	return false;
}
int main()
{
	int i,j,k,u,v,result=0;
	
	cin>>n>>m>>p;
	g.resize(n+1);
	
	for(i=0;i<p;i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
	}
	for(i=1;i<=n;i++)
	{
		bool visited[m+1];
		memset(visited,false,sizeof visited);
		if(g[i].size()>0)
		{
			if(func(visited,i))
			result++;	
		}
			
		
	}

	cout<<result<<endl;
}
