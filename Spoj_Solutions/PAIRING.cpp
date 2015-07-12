#include<iostream>
using namespace std;
#define pii pair<int,int>
int main()
{
	int tc,n,m;
	pii arr[10000];
	bool check[1000];
	cin>>tc;
	while(tc--)
	{
		cin>>n>>m;
		int a,b;
		for(int i=0;i<n;i++)
		check[i]=true;
		for(int i=0;i<m;i++)
		{
			cin>>a>>b;
			arr[i]=pii(a,b);
		}
		for(int i=m-1;i>=0;i--)
		{
			if(check[arr[i].first] && check[arr[i].second])
			{
				check[arr[i].first]=false;
				 check[arr[i].second]=false;
				 cout<<i<<" ";
			}
		}
		cout<<endl;
	}
}
