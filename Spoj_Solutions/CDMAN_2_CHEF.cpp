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
int arr[101][3];
double dis[101][101];
 bool visited[101];
vector<vector<int > >graph(101);
void dfs(int u)
{
	visited[u]=true;
	
	int sz=graph[u].size();
for(int i=0;i<sz;i++)
{
	int j=graph[u][i];
	if(!visited[j])
	dfs(j);
	
	
}	
	
} 
 
 
int main()
{
int t,n,d,num,i,j;
double dist;

rd(t);
while(t--)
{
	rd(n);
	rd(d);
	for(i=0;i<n;i++)
	{
		rdl(arr[i][0]);
		rdl(arr[i][1]);
		rdl(arr[i][2]);
		
	}
for(i=0;i<n;i++)
{
	for(j=i+1;j<n;j++)
	{
		dist=double(sqrt(1LL*(arr[i][0]-arr[j][0])*(arr[i][0]-arr[j][0])+1LL*(arr[i][1]-arr[j][1])*(arr[i][1]-arr[j][1])+1LL*(arr[i][2]-arr[j][2])*(arr[i][2]-arr[j][2])));
		dis[i][j]=dist;
		dis[j][i]=dist;
		//cout<<dist<<endl;
		if(dist<=d)
		{
			graph[i].push_back(j);
			graph[j].push_back(i);
		}
	}
	
}	
	
num=0;
for(i=0;i<n;i++)
{
	if(!visited[i])
	num++,dfs(i);
}

	pd(num);

	
}	

}
