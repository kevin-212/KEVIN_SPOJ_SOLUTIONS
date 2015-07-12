#include<bits/stdc++.h>
using namespace std;

int main()
{
	int arr[10001];

	char arr1[20];
	int  n,m,i,j;
	arr[0]=0;
	scanf("%d %d",&n,&m);
	
	for(i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
		arr[i]+=arr[i-1];
	}
	for(int k=1;k<=m;k++)
	{
		scanf("%s %d %d",arr1,&i,&j);
		printf("%d\n",arr[j]-arr[i-1]);
	}
}
