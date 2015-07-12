#include<bits/stdc++.h>
using namespace std;

int main()
{
	char arr[8]={'\0','d','h','a','p','u','s','v'};
	int tc,carry;
	string ans;
	unsigned long long int n;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%llu",&n);
		ans="";
		while(n)
		{
			carry=n%7;
			n/=7;
			if(carry==0)
			carry=7,n--;
			ans=arr[carry]+ans;
			
		}
		cout<<ans<<endl;
	}
}
