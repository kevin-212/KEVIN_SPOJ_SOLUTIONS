#include<bits/stdc++.h>
using namespace std;
bool find(int v)
{
 
}
int main()
{
	int t;
	long long int n,left,right,mid;
	long long int s,temp;
	scanf("%d",&t);
	while(t--)
	{
		
		scanf("%lld %lld",&n,&s);
		left=1;
		right=n;
		while(left<=right)
		{
			mid=(left+right)/2;
			temp=((mid*(mid+1))/2)+(n-mid);
			
			if(temp==s)
			{
				left=mid+1;
				break;
			}
			if(temp<s)
			left=mid+1;
			else
			right=mid-1;
		}
		printf("%d\n",n-left+1);
	}
}
