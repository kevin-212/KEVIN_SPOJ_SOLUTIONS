#include<bits/stdc++.h>
using namespace std;
int arr[100000];
int pre;
int tc,n,k,i,j;
bool find(int v)
{
	pre=arr[0];
	j=0;
	for(i=1;i<n;i++)
	{
		if(arr[i]-pre>=v)
		{
			j++;
			pre=arr[i];	
		}
	}
	if(j>=k)
	return true;
	return false;
}
int main()
{
	int left,right,mid;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d %d",&n,&k);
		k--;
		for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
		
		sort(arr,arr+n);
		left=0;
		right=arr[n-1];
		while(left<=right)
		{
			mid=(left+right)/2;
			if(find(mid))left=mid+1;
			else
			right=mid-1;
			
		}
		printf("%d\n",left-1);
		
	}
}
