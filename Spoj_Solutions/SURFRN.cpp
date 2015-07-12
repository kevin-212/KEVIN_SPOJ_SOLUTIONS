#include<bits/stdc++.h>
#define gc getchar
#define pii pair<int,int>
using namespace std;
void sd(int &x)
{
	 int c=gc();
	x=0;
	for(;c<48 || c>57;c=gc());
	for(;c>47 && c<58;c=gc()){
		x=(x<<1)+(x<<3)+c-48;
	}
	
	
}
int main()
{
	int t,n,s,d,u,v,i,j,k,count;
	scanf("%d",&t);
	vector< vector<int > >graph;
	int arr[101];
	bool visited[101];
	while(t--)
	{
	
		queue<int>Q;			
		scanf("%d%d%d",&n,&s,&d);
		graph.clear();
		graph.resize(n+1);
		for(i=1;i<=n;i++)
		{
			visited[i]=false;
		}	
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&u,&v);
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
			Q.push(s);
			arr[s]=0;
			while(!Q.empty())
			{
				u=Q.front();
				count=arr[u];
				Q.pop();
				visited[u]=true;
				k=graph[u].size();
				for(i=0;i<k;i++)
				{
					v=graph[u][i];
					if(!visited[v])
					Q.push(v),arr[v]=count+1;
				}
			}
		cout<<arr[d]<<endl;
	}
}

