#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int main()
{
	int n,xo,yo;
	cin>>n>>xo>>yo;
	int i,x,y,num,dem,temp1,temp2,temp;
	map<pii,int>mp;
	for(i=0;i<n;i++)
	{
		cin>>x>>y;
		dem=(x-xo);
		num=(y-yo);
		if(dem<0 && num<0)
		dem*=-1,num*=-1;
		
		temp=num;
		 temp2=dem;
		while(temp2)
		{
			temp1=temp;
			temp=temp2;
			temp2=temp1%temp2;
				
		}
		mp[pii(num/temp,dem/temp)]++;
	}
	cout<<mp.size()<<endl;
	
}
