#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	char s[10001] ;
	int i,j,k;
bool arr[10001];
memset(arr,true,sizeof arr);
arr[0]=false;
arr[1]=false;

for(i=2;i<=100;i++)
{
	if(arr[i])
	{
		for(j=i*i;j<=10000;j+=i)
		arr[j]=false;
	}
}	
cin>>n;
int count[123];
int mx=0;
int prm,com,tmp;

while(n--)
{
	cin>>s;
	memset(count,0,sizeof count);
	prm=com=0;
	mx=0;
	k=strlen(s);
	for(j=0;j<k;j++)
		count[s[j]]++;
		
		
		for(i=65;i<=122;i++)
		{
			tmp=count[i];
			if(tmp>mx)
			mx=tmp;
		}
	
	
	
	if(arr[mx])
	{
		for(i=65;i<=122;i++)
		{
		tmp=count[i];
		if(arr[tmp])
		prm+=(tmp+1)/2;
		else
		prm+=tmp;
		}
		cout<<prm<<endl;
	}
	else
	{
		for(i=65;i<=122;i++)
		{
		tmp=count[i];
		if(arr[tmp])
		prm+=tmp;
		else
		prm+=(tmp+1)/2;
		}
		cout<<prm<<endl;
	}
}
}
