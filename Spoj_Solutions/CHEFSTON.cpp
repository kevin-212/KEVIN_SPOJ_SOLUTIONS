#include<iostream>
using namespace std;

int main()
{
	int tc,n,a;
	unsigned long long int k;
	double ans=0,temp;
	cin>>tc;
	double arr[100000];
	int arr1[100000];
	while(tc--)
	{
		cin>>n>>k;
		ans=0;
	for(int i=0;i<n;i++)
	cin>>arr[i];
	for(int i=0;i<n;i++)
	{
		cin>>arr1[i];
		temp=double(arr1[i])/arr[i];
		
		if(temp>ans)
			{
				a=i;	
				ans=temp;
			
			}
		
		
	}
	k/=int(arr[a]);
	k*=arr1[a];
	cout<<k<<endl;
	}
}
