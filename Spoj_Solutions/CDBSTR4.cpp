#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc,i,j,k,count;
	int prime[9593];
	prime[0]=2;
	prime[1]=3;
	prime[2]=5;
	for(i=7;i<=100000;i+=2)
	{
		for(j=0;j<=count;j++)
		{
			if(i%prime[j]==0)
			break;
		}
		if(j>count)
		{
			prime[++count]=i;
		}
	}
	scanf("%d",&tc)
	while(tc--)
	{
		scanf("%d %d %d",&i,&j,&k);
		
		
		
	}
	cout<<count<<" "<<prime[count]<<endl;
	

}
