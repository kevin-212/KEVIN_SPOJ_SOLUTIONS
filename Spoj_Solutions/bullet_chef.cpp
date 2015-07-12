#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	 long double x;
	while(n--)
	{
		cin>>x;

		if(x<=100)
		cout<<"0.000000"<<endl;
		else
		{
		
		 x-=100.000000;
		 x=x/(double)200;
		 
		printf("%.8llf\n",x);
	}
	
	}
}
