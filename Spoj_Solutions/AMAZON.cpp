#include<bits/stdc++.h>
using namespace std;
#define maX 10000000
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int S,n;
	scanf("%d %d",&S,&n);
	int arr[100];
	int sum[100001];
	for(int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for(int i=0;i<100001;i++)
	sum[i]=maX;
	sum[0]=0;

	for(int i=0;i<n ;i++)
	{
		
		for(int j=arr[i];j<=S;j++)
		{
			
			if(sum[j-arr[i]]!=maX)
			{
				sum[j]=min(sum[j],1+sum[j-arr[i]]);
		
			}
			
		}
	}
	if(sum[S]!=maX)
	printf("%d",sum[S]);
	else
	printf("NO");
}
