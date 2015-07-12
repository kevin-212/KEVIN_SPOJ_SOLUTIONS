#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pii pair<int,int>
using namespace std;
inline void rdl( int &x)
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
inline void pdl( int x)
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
vector< vector < int > >graph;
int parent[100001],n;
int add[100001];
bool visited[100001];
void dfs(int i)
{
	visited[i]=true;
	int sz=graph[i].size();
	int x;
	for(int j=0;j<sz;j++)
	{
		x=graph[i][j];
		if(!visited[x])
		{
			parent[x]=i;
			dfs(x);
		}
	}
}
int find(int x,int y)
{
	fill(visited,visited+n+1,false);
		int match=y;
		int match1=x;
		int temp=0;
	while(x!=1)
	{
		visited[x]=true;
		temp+=add[x];
		x=parent[x];
		
	}
	visited[1]=true;
	temp+=add[1];
	while(y!=1)
	{

		if(visited[y]==true)
		{
			break;
		}
		y=parent[y];
	}
	vector<int>vec,vec1;
	int mx=INT_MIN;
	while(match1!=y)
	{
		vec.push_back(add[match1]);
		match1=parent[match1];
	}
	vec.push_back(add[y]);
	
	while(match!=y)
	{
		vec1.push_back(add[match]);
		match=parent[match];
	}
	vec1.push_back(add[y]);
	int sz=vec.size();
	int ans1=0;
	for(int i=sz-1;i>=0;i--)
	{
		ans1+=vec[i];
		mx=max(mx,ans1);
	}
	temp-=ans1;
	sz=vec1.size();
	ans1=0;
	for(int i=sz-1;i>=0;i--)
	{
		ans1+=vec1[i];
		mx=max(mx,ans1);
	}
	return mx+temp;
}
int main()
{
	int i,j,k,x,y,q;
	rd(n);
	graph.resize(n+1);
	char s[10];
	parent[1]=1;
	for(i=1;i<n;i++)
	{
		rd(x);
		rd(y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for(i=1;i<=n;i++)
	{
		if(!visited[i])
		dfs(i);
	}
	rd(q);
	
	for(i=0;i<q;i++)
	{
		scanf("%s",s);
		
		rdl(x);
		rdl(y);
		if(s[0]=='a')
			add[x]+=y;
			else
			pd(find(x,y));
		
	}
}
