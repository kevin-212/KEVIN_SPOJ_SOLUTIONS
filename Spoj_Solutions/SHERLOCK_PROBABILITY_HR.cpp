#include<bits/stdc++.h>
using namespace std;
int main()
{
	char str[100001];
	int arr[100001];
	int t,k,i,K,j;
	int len;
	long long int one,n,N,temp,on1;
	cin>>t;
	while(t--)
	{
		one=0;
		cin>>n>>k;
		cin>>str;
		len=strlen(str);
	
		
		arr[len]=0;
		for(i=len-1;i>=0;i--)
		{
			arr[i]=arr[i+1];
			if(str[i]=='1')
			{
				one++;
				K=i+k+1;
					if(K>=len)
						one=one+1LL*2*arr[i+1];
						else
						one=one+1LL*2*(arr[i+1]-arr[K]);
					arr[i]++;
			}
			
		}
		n=n*n;
		N=n;
		on1=one;
		while(n)
		{
			temp=one;
			one=n;
			n=temp%n;
		}
		on1/=one;
		N/=one;
		cout<<on1<<"/"<<N<<endl;
		
	}
}
