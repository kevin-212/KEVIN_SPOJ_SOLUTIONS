#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,n,m,i;
	float temp,temp1,temp2;
	float ans;
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d %d",&n,&m);
		
		ans=0.0;
	
	
		temp1=1.0;
		if(m>1){
		
		for(i=1;i<n;i++){
		ans+=temp1;
		temp1/=2.0;
		}
		temp=ans;
		temp1*=m;
		ans+=temp1;
		}
		
		
		for(i=2;i<m;i++)
		{	temp/=2;
			ans+=temp;
		}
		temp=0;
		temp1=1.0;
		if(n>1){
		temp1=.5;
		for(i=2;i<m;i++)
		{
			temp1/=2.0;
			temp+=temp1;
			
		}
		temp1*=n;
		ans+=temp1;
		ans+=temp;
	}
		for(i=2;i<n;i++)
		{
			temp/=2;
			ans+=temp;
		}
		
		printf("%.06f\n",ans);
	}
	
}
