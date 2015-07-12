#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main()
{
	int tc,len;
	
	string str1;
	char c;
	scanf("%d",&tc);
	scanf("%c",&c);
	while(tc--){
	
	string str;
	getline(cin,str);
	len=str.length();
	bool check1;
	if(len&1)
	{
		int i=len/2,j;
		
			
			if(str[i]!='9')
			{
				str[i]+=1;
				
			}
			else
			{
				str[i]='0';
				j=i+1;
				i--;
				check1=true;
				while(check1)
				{
					
					if(i<0)
					{
						str[len-1]='1';
						str="1"+str;
						
						break;
					}
					if(str[i]!='9' && str[j]!='9')
					{
						str[i]+=1;
						str[j]+=1;
						check1=false;
					}
					else
					{
						str[i--]='0';
						str[j++]='0';
					}
				}
			}
		
		
	}
	else
	{
		
			int i=len/2,j;
		
			
			if(str[i]!='9')
			{
				str[i]+=1;
				str[i-1]+=1;
				
			}
			else
			{
				str[i]='0';
				str[i-1]='0';
				j=i+1;
				i-=2;
				check1=true;
				while(check1)
				{
					if(i<0)
					{
						str[len-1]='1';
						
						str="1"+str;
						
						break;
					}
					if(str[i]!='9' && str[j]!='9')
					{
						str[i]+=1;
						str[j]+=1;
						check1=false;
					}
					else
					{
						str[i--]='0';
						str[j++]='0';
					}
				}
			}	
	
	}
		cout<<str<<endl;
	}
}
