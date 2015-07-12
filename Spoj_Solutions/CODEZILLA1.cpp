#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,k,sum;
	bool check;
	cin>>t;
	while(t--)
	{
		check=false;
		cin>>n>>k;
		if(n<2)
		cout<<-1<<endl;
		
		else{
		
		sum=(n*(n+1))/2;
		sum=sum-k;
		if(sum>(2*n-1)|| sum<3)
		cout<<-1<<endl;
		else{
		
		if(sum>n)
		cout<<n*(sum-n)<<endl;
		else
			cout<<sum-1<<endl;
		}
		
		}
		
	}
	
}
