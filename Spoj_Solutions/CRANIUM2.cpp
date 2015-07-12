#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int main()
{
	int n,k;
	char str[5001];
	char str1[5001];
	int l1,l2;
	cin>>n>>k;
	cin>>str;
	cin>>str1;
	l1=strlen(str);
	l2=strlen(str1);
	int i,j,z;
	l1=l1-k;
	l2=l2-k;
	int count;
	int ans=0;
	int mul=0;
	for(i=0;i<=l1;i++)
	{
	
		for(j=0;j<=l2;j++)
		{count=0;
		mul++;
			for(z=0;z<k;z++)
			{
				if(str[i+z]==str1[j+z])
				count++;
			}
			ans+=(mul*count);
			if(ans>=mod)
			ans-=mod;
		}
	}
	cout<<ans<<endl;
}
