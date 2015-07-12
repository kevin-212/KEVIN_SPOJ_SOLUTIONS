#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str,ans;
	int tc,l1,l2,i,j,k,carry,s;
	char c;
	scanf("%d",&tc);
	while(tc--)
	{
		cin>>str;
		l1=str.length();
		ans="";
		l2=str.find('+');
		
		if(l2>0)
		{
			i=l2-1;
			j=l1-1;
			carry=0;
			while(i>=0 && j>l2)
			{
				s=str[i]-'0'+str[j]-'0'+carry;
				carry=s/10;
				s=s%10;
				c=s+'0';
				ans=c+ans;
				i--;
				j--;
			}
			while(i>=0)
			{
				s=str[i]-'0'+carry;
				carry=s/10;
				s=s%10;
				c=s+'0';
				ans=c+ans;
				i--;
				
			}
			while(j>l2)
			{
				s=str[j]-'0'+carry;
				carry=s/10;
				s=s%10;
				c=s+'0';
				ans=c+ans;
				j--;
			}
			if(carry>0)
			{
				c=carry+'0';
				ans=c+ans;
			}
			cout<<ans<<endl;
		}
		else
		{
			l2=str.find('-');
		
			j=l1-1;
			s=('9'-str[j]+1);
			carry=s/10;
			s=s%10;
			str[j]=(s+'0');
			
			j--;
			while(j>l2)
			{
				s=('9'-str[j]+carry);
				carry=s/10;
				s=s%10;
				str[j]=s+'0';
				
				j--;
			}
			j=l1-1;
			i=l2-1;
			carry=0;
			while(i>=0 && j>l2)
			{
				s=str[i]-'0'+str[j]-'0'+carry;
				carry=s/10;
				s=s%10;
				c=s+'0';
			
				ans=c+ans;
				i--;
				j--;
			}
	
			while(i>=0)
			{
				s=str[i]-'0'+carry+9;
				carry=s/10;
				s=s%10;
				c=s+'0';
				ans=c+ans;
				i--;
				
			}

			while(j>l2)
			{
				s=str[j]-'0'+carry;
				carry=s/10;
				s=s%10;
				c=s+'0';
				ans=c+ans;
				j--;
			}
			if(carry>0)
			{
				
				i=0;
				l1=ans.size();
				while(ans[i]=='0')
					i++;
					if(i==l1)
					cout<<"0"<<endl;
					else
			cout<<ans.substr(i)<<endl;
			
			}
			else
			{
				l1=ans.size();
				s='9'-ans[l1-1]+1;
				carry=s/10;
				s=s%10;
				ans[l1-1]=s+'0';
				for(i=l1-2;i>=0;i--)
				{
					s='9'-ans[i]+carry;
					carry=s/10;
					s=s%10;
					ans[i]=s+'0';
				}
				i=0;
				while(ans[i]=='0')
				i++;
				cout<<'-'<<ans.substr(i)<<endl;
			}
			
			
		}
	}
}
