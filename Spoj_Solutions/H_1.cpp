#include<stdio.h>
int arr[100001];
int main()
{
	
	int n,q;
	int check=0;
	long long int divider=1LL;
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	
	scanf("%d",&q);
	for(i=0;i<q;i++)
	{
		scanf("%d",&j);
		divider*=j;
		if(divider>1000000)
		check=1;
	}
	if(check)
	for(i=0;i<n;i++)
	printf("0 ");
	else
	for(i=0;i<n;i++)
		printf("%d ",arr[i]/divider);
		
	
	return 0;
}
