#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

struct comp{
bool operator()(const pii a,const pii b)
{
	return a.second>b.second;
}
};

int main()
{
	int n,m,i,j,k,d,q,src,dst,u,v;
	scanf("%d %d",&n,&m);
	map<string,int>mp;
	vector<pii>graph[100];
	int D[101];
	bool f[101];
	string s,s1;
	for(i=0;i<n;i++)
	{
		cin>>s;
		mp[s]=i;
	}
	for(i=0;i<m;i++)
	{
		cin>>s>>s1>>d;
		graph[mp[s]].push_back(pii(mp[s1],d));
		graph[mp[s1]].push_back(pii(mp[s],d));
	
	}
	cin>>q;
	while(q--)
	{
		cin>>s>>s1;
		src=mp[s];
		dst=mp[s1];
		for(i=0;i<n;i++)
		D[i]=INT_MAX,f[i]=false;
		D[src]=0;
		
		
			priority_queue<pii,vector<pii>,comp>Q;
		Q.push(pii(src,0));
		while(!Q.empty()){
			
			u=Q.top().first;
			Q.pop();
			if(u==dst)
			{
				f[u]=true;
				break;
				
			}
			if(f[u])continue;
			int sz=graph[u].size();
			for(i=0;i<sz;i++)
			{
				v=graph[u][i].first;
				d=graph[u][i].second;
				if(!f[v] && d+D[u]<D[v])
				{
				
				D[v]=d+D[u];
				Q.push(pii(v,D[v]));
			}
			}
			f[u]=true;
			
		}
		cout<<D[dst]<<endl;
		
	}
}
