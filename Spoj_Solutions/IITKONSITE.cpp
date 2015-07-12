#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	
	int t,l1,l2;
	int arr[101][101];
	char str1[1001];
	char str2[1001];
	scanf("%d",&t);
	int index=0;
	while(t--)
	{
		index++;
		scanf("%d",&l1);
		scanf("%d",&l2);
		scanf("%s",str1);
		scanf("%s",str2);
		l1=strlen(str1);
		l2=strlen(str2);
		
		for(int i=0;i<=l1;i++)
		for(int j=0;j<=l2;j++)
		arr[i][j]=0;
		
		for(int i=1;i<=l1;i++)
		{
			for(int j=1;j<=l2;j++)
			{
				if(str1[i-1]==str2[j-1])
				arr[i][j]=arr[i-1][j-1]+1;
				else
				arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
			}
		}
		int temp=max(l1,l2);
		if(arr[l1][l2]==temp)
		printf("Case %d:%d\n",index,temp);
		else
		printf("Case %d:%d",index,l1+l2-arr[l1][l2]);
	}
	
}
