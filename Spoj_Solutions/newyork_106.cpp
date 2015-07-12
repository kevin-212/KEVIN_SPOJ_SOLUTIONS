#include<iostream>
#include<queue>
#include<vector>
#include<iomanip>
using namespace std;

#define pif pair<int,double>
struct cmp{
	bool operator()(pif a,pif b)
	{
	return a.second<b.second;	
	}
};
int  main()
{
	int n,m;
	cout<<fixed;
	while(true)
	{
		cin>>n;
		if(n==0)
		break;
		cin>>m;
		int u,v;
		double w;
		vector<pif>graph[101];
		double D[100];
		bool visited[101];
		for(int i=1;i<=n;i++)
		D[i]=0.0,visited[i]=false;
		for(int i=0;i<m;i++)
		{
			cin>>u>>v>>w;
			graph[u].push_back(pif(v,w));
			graph[v].push_back(pif(u,w));
		}
		
		priority_queue<pif,vector<pif>,cmp>Q;
		Q.push(pif(1,100.0));
		D[1]=100.0;
		while(!Q.empty())
		{
			int u=Q.top().first;
			Q.pop();
			if(visited[u])continue;
			if (u==n)
			break;
			
			visited[u]=true;
			for(int i=0;i<graph[u].size();i++)
			{
				int v=graph[u][i].first;
				int w=graph[u][i].second;
				if(!visited[v] && (w*D[u]/100.0)>D[v])
				{
					D[v]=(w*D[u]/100.0);
					Q.push(pif(v,D[v]));
				}
			}
		}
		cout<<setprecision(6)<<D[n]<<" percent"<<endl;
	}
}
