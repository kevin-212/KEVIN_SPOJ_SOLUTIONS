#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*void lps(int prev,int end)
{
	int len=pat[prev-1];
	int i=prev;
	while(i<end)
	{
		if(str[i]==str[prev])
		{
			len++;
			pat[i]=len;
			i++;
		}
		else
		{
			if(len!=0)
			{
				len=pat[len-1];
			}
			else
			{
				pat[i]=0;
				i++;
			}
		}
	}
	
}*/
int main()
{
	string str;	
	int l1,t,l2,i,prev,j,k;
	while(true)
	{
		t=1;
		getline(cin,str);
		if(str[0]=='*')
		break;
		l1=str.size();
		
		for(i=1;i<=l1;i++)
		{
			
			if(l1%i==0)
			{
				for(j=i;j<l1;j+=i)
				{
					for(k=0;k<i;k++)
					{
						if(str[k]!=str[j+k])
						break;
					}

					if(k<i)
					break;
				}	
					if(j==l1){
					t=l1/i;
					break;
					}

			}
			
			
		}
	
		printf("%d\n",t);
	}
	
}

