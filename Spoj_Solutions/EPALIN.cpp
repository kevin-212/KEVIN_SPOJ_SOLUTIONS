#include<bits/stdc++.h>
using namespace std;
int main()
{
	char str1[200005];
	int l1,i,j,len,index;
	while(gets(str1))
	{
		l1=strlen(str1);
		i=0;
		j=l1-1;
		len=0;
		for(i=0;i<j;i++)
		{
			if(str1[i]==str1[j])
			j--,len++;
			else
			j=l1-1,len=0;	
			
		}
		len*=2;
		if(j==i)
		len++;
		index=l1-len;
		for(i=index-1;i>=0;i--)
		str1[l1++]=str1[i];
		str1[l1]='\0';
		puts(str1);
	}
}
