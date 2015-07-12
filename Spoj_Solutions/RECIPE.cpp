#include<iostream>
using namespace std;
int gcd(int a,int b)
{
	if(b==0)
	return a;
	return gcd(b,a%b);
}
int main()
{
	int tc,n;
	int arr[50];
	cin>>tc;
	while(tc--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		cin>>arr[i];
		
		int a=arr[0];
		for(int i=1;i<n;i++)
		{
			if(arr[i]% a)
			a=gcd(a,arr[i]);
		}
		
		
		for(int i=0;i<n;i++)
		cout<<arr[i]/a<<" ";
		cout<<endl;
	}
}
