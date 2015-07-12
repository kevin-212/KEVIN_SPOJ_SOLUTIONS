#include<bits/stdc++.h>
using namespace std;
int main()
{
	char str[20];
	int i;
	cin>>str;
	int l1=strlen(str);
	string ans="";
	for(i=0;i<l1;i++)
	{
		if(str[i]-'0'<5)
		ans+=str[i];
		else
		ans+=('9'-str[i]+'0');
	}
	i=0;
	while(ans[i]=='0')
	i++;
	for(;i<l1;i++)
	cout<<ans[i];
}
