#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
unsigned long long int arr[100000];

int n,a;
unsigned long long int ans=0;

void backtrack(int index,unsigned long long int temp)
{
	
	if(index==n)
	{
		ans=max(ans,temp);
		return;
	}
	unsigned long long int temp1;
	temp1=temp;
	temp^=arr[index];
	if(temp>temp1)
	backtrack(index+1,temp);
	temp=temp1;
	backtrack(index+1,temp);
}
int main()
{
	
	
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%llu",&arr[i]);
	backtrack(0,0);
	printf("%llu",ans);
}
