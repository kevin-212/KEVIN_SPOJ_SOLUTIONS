#include<bits/stdc++.h>
using namespace std;

int main()
{
	unsigned long long int sum=0;
	int arr[16];
	arr[0];
	int n;
	scanf("%d",&n);

		
		if(n==1)
		printf("1\n");
		else if(n==2)
		printf("3\n");
		else if(n==3)
		printf("10");
		else
		{
				for(int i=1;i<=n;i++)
					arr[i]=(i*(i+1))/2;
			for(int i=1;i<=n;i++)
			{
				sum=sum+(arr[n-i+1]*i);
			}
			printf("%llu\n",sum);
			
		}
		
}
