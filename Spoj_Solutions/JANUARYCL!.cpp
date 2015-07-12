#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	
	int tc,k1,k2;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d %d",&k1,&k2);
		if((k1==1 && k2==2) ||(k1==2 && k2==1))

			printf("Don't Play\n");
			
			
	
		else
				printf("Play\n");
	}
}
