#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int s;
	int arr[100001];
	cin>>s;
	int a;
	
	for(int i=0;i<s;i++)
	{
		cin>>arr[i];
		
	}
	sort(arr,arr+s);
	int count=0;
	
	for(int i=0;i<s;i++)
		cout<<arr[i]-i<<" ";
		
	
	
}   

