#include<iostream>
#include<deque>
using namespace std;

int main()
{
	int n,k;
	int *arr;
	scanf("%d",&n);
	arr=new int[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	scanf("%d",&k);
	deque<int>DQ(k);
	int i;
	for(i=0;i<k;i++)
	{
		while((!DQ.empty()) && arr[i]>=arr[DQ.back()])
		DQ.pop_back();
		
		DQ.push_back(i);
	}
	
	printf("%d ",arr[DQ.front()]);
	
	for(;i<n;i++)
	{
		while((!DQ.empty()) && DQ.front()<=i-k)
		DQ.pop_front();
		
		while((!DQ.empty())&& arr[i]>=arr[DQ.back()])
		DQ.pop_back();
		DQ.push_back(i);
		printf("%d ",arr[DQ.front()]);
	}
}
