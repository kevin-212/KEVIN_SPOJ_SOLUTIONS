#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,i,l1,prv;
	bool check1,check2,br;
	string str1;
	char str[101];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",&str);
		l1=strlen(str);
		prv=-1;
		str1="";
		check1=check2=br=false;
		i=0;
		while(str[i]=='5')
		{
			str1=str1+'5';
			i++;
		}
		
		if(i<l1){
		
		for(;i<l1;i++)
		{
			if(str[i]<'3')
			{
				str1=str1+'3';
				check1=true;
				break;
			}
			else if(str[i]=='3')
			{
				str1=str1+'3';
				prv=i;
			}
			else if(str[i]<'5')
			{
				str1=str1+'5';
				check1=true;
				break;
			}
			else
			{
				if(prv==-1)
				{
				check2=true;
				break;
				}
				else
				{
					str1[prv]='5';
					str1=str1+'3';
					check1=true;
					break;
				
				}
			}
		}
		i++;
		if(check2){
		str1="";
		for(i=0;i<=l1;i++)
		str1=str1+'3';
		}
		else if(check1)
		for(;i<l1;i++){
		str1=str1+'3';
		}
		else
		str1[l1-1]='5';
		}
		else{
			str1="";
			for(i=0;i<=l1;i++)
			str1=str1+'3';
		}
		cout<<str1<<endl;
		
	}
}
