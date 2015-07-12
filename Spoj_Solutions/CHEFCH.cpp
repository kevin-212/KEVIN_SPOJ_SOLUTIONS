#include<bits/stdc++.h>
using namespace std;
int main()
{
	char str[100001];
	int tc,i,j,k,l,count1,count2;
	char cur1,cur2;
	scanf("%d",&tc);


	while(tc--)
	{
		scanf("%s",str);
		l=strlen(str);
		count1=count2=0;
		cur1=44;
		j=1;
		k=-1;
		for(i=0;i<l;i++)
		{
			if(str[i]==cur1+k)
			{
				k=-k;
			}
			else
			{
				count1++;
				k=-k;
			}
			
			if(str[i]==cur1+j)
			{
				j=-j;
			}
			else
			{
				count2++;
				j=-j;
			}
		}
		printf("%d\n",min(count1,count2));
		
	}
}
