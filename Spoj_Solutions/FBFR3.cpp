#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	char s[101];
	int l,i,j,k;
	string ans;
	cin>>t;
	bool check,add;
	while(t--)
	{
		cin>>s;
		ans="";
		l=strlen(s);
		check=add=false;
		for(i=0;i<l;i--)
		{
			if(check){
			if(add)
			{
				
			}
			else{
			
			if(arr[i]<='5')
			{
				arr[i]='5';
			}
			else
			arr[i]='9';
			}
		}
			else
			{
				if(arr[i]<'5')
				arr[i]='5',check=true;
				else if(arr[i]<'9')
				arr[i]='9',check=true;
				if(arr[i]=='9')
				{
					arr[i]=='9';
					check=true;
					add=true;
				}
				
			}
		}
		if(i>=0)
		{
			for(j=0;j<i;j++)
			ans+=s[j];
			ans+='9';
			for(j=i+1;j<l;j++)
			ans+='5';
			
		}
		else
		{
			for(i=0;i<=l;i++)
			ans+='5';
			
		}
		cout<<ans<<endl;
	}
}
