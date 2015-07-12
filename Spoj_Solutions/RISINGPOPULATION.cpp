#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc,i;
	scanf("%d",&tc);
	char c;
	int arr[123];
	scanf("%c",&c);
	while(tc--)
	{
		memset(arr,0,sizeof(arr));
		
		do{
			scanf("%c",&c);
			
			if(c>=67 && c<=122)
			arr[c]++;
			else
			break;
		}while(true);
	
		do{
			gets(&c);
			
			if(c>=67 && c<=122)
			arr[c]--;
			else
			break;
		}while(true);
		
		for(i=97;i<=122;i++)
		{
			if(arr[i]!=0)
			break;
			
		}
	
	if(i==123)
	printf("YES\n");
	else
	printf("NO\n");
	}
}
