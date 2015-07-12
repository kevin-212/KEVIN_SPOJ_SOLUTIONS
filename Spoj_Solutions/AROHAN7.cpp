#include<bits/stdc++.h>
using namespace std;
#define GROUP_A(x) x, x+1, x+1, x+2
#define GROUP_B(x) GROUP_A(x), GROUP_A(x+1), GROUP_A(x+1), GROUP_A(x+2)
#define GROUP_C(x) GROUP_B(x), GROUP_B(x+1), GROUP_B(x+1), GROUP_B(x+2)

#define META_LOOK_UP(PARAMETER)\
GROUP_##PARAMETER(0),\
GROUP_##PARAMETER(1),\
GROUP_##PARAMETER(1),\
GROUP_##PARAMETER(2)

int main()
{
	 static unsigned char lookup[]={ META_LOOK_UP(C) };

	
	int n,maX,count;
	unsigned long long int l,r;
	unsigned long long int ans;
	unsigned char*ptr=NULL;
	unsigned char*ptr1=NULL;
	scanf("%d",&n);
	while(n--)
	{
		
		scanf("%llu %llu",&l,&r);
		cout<<sizeof(l)<<endl;
	maX=0;
		for(;l<=r;l++){
			ptr=(unsigned char*)&l;
			count=0;
		for(int i=0;i<8;i++)
		{
		
			count+=lookup[ptr[i]];
		
		}	
		if(count>maX)
		{
			ans=l;
			maX=count;
		}
		
	}

	
	printf("%llu\n",ans);
}
}
