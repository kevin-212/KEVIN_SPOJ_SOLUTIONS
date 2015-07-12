#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,l1,l2,count;
	char str1[1005];
	char str2[1005];
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",str1);
		scanf("%s",str2);
		l1=strlen(str1);
		l2=strlen(str2);
		if(l1!=l2){
		
		printf("-1\n");
		continue;
		}
		count=0;
		for(int i=0;i<l1;i++)
		{
			if(str1[i]!=str2[i])
			count++;
		}
		printf("%d\n",count);
	}
}
