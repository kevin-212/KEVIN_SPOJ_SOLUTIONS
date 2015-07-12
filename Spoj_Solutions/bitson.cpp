#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,i,j,sz,u;
	char str[1001];
	int in[1001];
	cin>>t;
	priority_queue<int>Q;
	vector<int>ans;
	vector<int>graph[1001];
	while(t--)
	{
		cin>>n;
		ans.clear();
			memset(in,0,sizeof in);
		for(i=0;i<n;i++)
		{
			graph[i].clear();
			cin>>str;
			for(j=n-1;j>=0;j--)
			{
				if(str[j]=='1')
				{
				graph[i].push_back(j);
				in[j]++;
				}
				
				
			}
		}
		for(i=0;i<n;i++)
		{
			if(in[i]==0)
			Q.push(-i);
		}
		while(!Q.empty())
		{
			i=-Q.top();
		
			Q.pop();
			ans.push_back(i+1);
			sz=graph[i].size();
			for(j=0;j<sz;j++)
			{
				u=graph[i][j];
				in[u]--;
				if(in[u]==0)
				Q.push(-u);
			}
		}
		
		for(i=0;i<n;i++)
		cout<<ans[i]<<" ";
		cout<<endl;
	}
	
}

