#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,index,e,temp,temp1;
	double x,y;
	scanf("%d",&n);
	double l1,l2;
	for(index=1;index<=n;index++){
		scanf("%lf %lf",&x,&y);
		temp1=y;
	while(true){
		e=(int)(log10(y)/(log10(x)));
		printf("%d\n",e);
		temp=pow(x,e);	
		if(temp>=temp1)
		break;
		temp1*=10;
		y*=10;
		y+=9;
		}
	
	printf("%d\n",e);
	}
}
	

