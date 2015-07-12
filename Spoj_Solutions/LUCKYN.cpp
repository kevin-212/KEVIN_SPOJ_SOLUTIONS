#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int comp;

int powof2(int n)
{
	comp=1;
	int temp=0;
	while(n>1)
	{
		temp++;
		comp*=2;
		n=n>>1;
	}
	return temp;
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int tot=powof2(n+1);
		int diff=n+1-comp;
	
		if(!diff)
		{
			for(int i=0;i<tot;i++)
			{
				printf("3");
			}
			printf("\n");
			continue;
		}
		if(diff+1==comp)
		{
			
			for(int i=0;i<tot;i++)
			printf("5");
			
			printf("\n");
			continue;
		}
		diff++;
		while(tot--)
		{
			if(diff<=comp/2)
			printf("3");
			else
			printf("5");
			comp=comp>>1;
			if(diff>comp)
			diff%=comp;
			
			if(!diff)
			diff=comp;
		}
		printf("\n");
	}
}
