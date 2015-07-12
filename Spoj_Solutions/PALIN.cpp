#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;


int main()
{
	
	int tc,len;
	string str;
	bool check;
	char c;
	scanf("%d",&tc);
	scanf("%c",&c);
	while(tc--)
	{
		getline(cin,str);
		len=str.length();
		check=false;
		
		
			if(len&1)
			{
				int i=len/2;
				int j=i+1;
				i--;
				while(i>=0)
				{
					if(check==false)
					{
						if(str[i]<str[j])
						break;
						
						if(str[i]>str[j])
						check=true;
					}
				
					str[j]=str[i];
					i--;
					j++;
				}
				if(check==false)
				{
					i=len/2;
					if(str[i]=='9')
					{
						str[i]='0';
						j=i+1;
						i--;
						while(true)
						{
							if(i<0)
							{
								str[len-1]='1';
								str="1"+str;
								break;
							}
							if(str[i]=='9')
							{
								str[i]='0';
								str[j]='0';
								i--;
								j++;
								
							}
							else
							{
								str[i]+=1;
								str[j]=str[i];
								i--;
								j++;
								break;
							}
						}
						
					}
					else
						{
							str[i]+=1;
							j=i+1;
							i--;
						}
					
					while(i>=0)
					str[j++]=str[i--];
					
				}
			}
			else
			{
				
				int i=len/2-1;
				int j=i+1;
				while(i>=0)
				{
					if(check==false)
					{
						if(str[i]<str[j])
						break;
						if(str[i]>str[j])
						{
							check=true;
						}
					}
					str[j]=str[i];
					i--;
					j++;
				}
				if(check==false)
				{
					i=len/2;
					if(str[i]=='9' && str[i-1]=='9')
					{
						str[i]='0';
						str[i-1]='0';
						j=i+1;
						i-=2;
						while(true)
						{
							if(i<0)
							{
								str[len-1]='1';
								str="1"+str;
								break;
							}
							if(str[i]=='9')
							{
								str[i]='0';
								str[j]='0';
								i--;
								j++;
								
							}
							else
							{
								str[i]+=1;
								str[j]=str[i];
								i--;
								j++;
								break;
							}
						}
						
					}
					else
					{
						
						str[i-1]+=1;
						str[i]=str[i-1];
						j=i+1;
						i-=2;;
					
					}
					while(i>=0)
					{
						str[j]=str[i];
						i--;
						j++;
					}

					
					
				}
				
			}
		cout<<str<<endl;
	}
}
