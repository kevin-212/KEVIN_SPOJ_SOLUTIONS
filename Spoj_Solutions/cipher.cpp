#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,i,j,sz=1,a,b;
	cin>>n>>k;
	char str[2000001];
	cin>>str;
	string ans;
	ans="";
	ans=str[0]+ans;
	if(n>k){
	
	for(i=1;i<k;i++)
	{
		a=str[i]-'0';
		b=str[i-1]-'0';
		ans=ans+char((a^b)+'0');
		sz++;
	}
	string ans1="";
	ans1=str[n+k-2]+ans1;
	sz++;
	i=n+k-3;
	while(sz<n)
	{
		a=str[i]-'0';
		b=str[i+1]-'0';
	
		ans1=char((a^b)+'0')+ans1;
		i--;
		sz++;
	}
	ans=ans+ans1;
	}
	else
	{
		for(i=1;i<n;i++)
		{
			a=str[i]-'0';
		b=str[i-1]-'0';
		ans=ans+char((a^b)+'0');
		
		}
		
	}
	cout<<ans<<endl;
}
