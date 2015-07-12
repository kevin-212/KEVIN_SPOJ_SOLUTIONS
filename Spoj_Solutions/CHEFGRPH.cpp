#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pii pair<long long int,long long int>
#define piii pair<long long int,pii>
struct cmp{
	bool operator()(const piii a,const piii b)
	{
		return a.first>b.first;
	}
};
int main()
{
	long long int m,k,sum_arr,j,a,b,c,d,sz;
	long long int n,i;
	piii temp;
	scanf("%lld %lld %lld",&n,&m,&k);
	long long int arr[m];
	sum_arr=1;
	vector<vector<long long int> >graph(k,vector<long long int>(4));
	n+=2;
	for(i=0;i<k;i++)
	{
		scanf("%lld %lld %lld %lld",&graph[i][0],&graph[i][1],&graph[i][2],&graph[i][3]);
		
	}
	sort(graph.begin(),graph.end());
	
	
	
	
	priority_queue<piii,vector<piii>,cmp>Q;
	
	int f1=0;
	while(f1<k && graph[f1][0]==0)
		{
			a=graph[f1][2];
			b=graph[f1][3];
			
			Q.push(piii(a,pii(b,1)));
			f1++;
		}
	for(i=1;i<n-1;i++)
	{
		for(j=0;j<m;j++)
		arr[j]=sum_arr;
	
		sum_arr=(m*sum_arr)%mod;
		
	
		while(!Q.empty())
		{
			 temp=Q.top();
			if(temp.first==i)
			{
				a=temp.second.first;
				b=temp.second.second;
				arr[a]+=b;
				sum_arr+=b;
				Q.pop();
			}
			else
			break;
		}		
		while(f1<k && graph[f1][0]==i)
		{
			a=graph[f1][2];
			b=graph[f1][3];
			c=graph[f1][1];
			Q.push(piii(a,pii(b,arr[c])));
			f1++;
		}
	
		

	
	}
	
	
	while(!Q.empty())
		{
			temp=Q.top();
			Q.pop();
			{
				
				b=temp.second.second;
				sum_arr+=b;
			}
		}
		sum_arr%=mod;
		cout<<sum_arr<<endl;
}
