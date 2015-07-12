#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,i,j,k,n,c1,c2,sum1,sum2;
	int arr[100000];
	bool check;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
		c1=c2=0;
		i=0,j=n-1;
	sum1=sum2=0;
		
		
		while(i<j)
		{
			
			if(sum1==sum2)
			{
				sum1=arr[i++];
				c1++;
				sum2=arr[j--];
				c2++;
		
			}
			else if(sum1<sum2)
			{
				sum1+=arr[i++];
				c1++;
		
			}
			else
			sum2+=arr[j--],c2++;
		}
		if(i==j)
		{
			
			if(sum1<=sum2)
			c1++;
			else
			c2++;
			
		}
		printf("%d %d\n",c1,c2);
		}
	}
