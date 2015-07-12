#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int tc,n,a;
	 int temp,temp1;
	bool chek=false;
	scanf("%d",&tc);
	while(tc--)
	{
		temp=0;
		chek=false;
		scanf("%d",&n);
		temp1=n;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			if(a==0)
			temp1--;
			if(a>100)
			chek=true;
			temp+=a;
		}
		if(chek)
		printf("NO\n");
		else if(temp<100)
			printf("NO\n");
		else if(temp>=(100+temp1))
			printf("NO\n");
		else
			printf("YES\n");
			
	}
}
