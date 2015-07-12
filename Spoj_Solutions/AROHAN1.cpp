#include<bits/stdc++.h>
using namespace std;

int main()
{
	int x,y,z,a,b;
	while(true)
	{
		scanf("%d %d %d",&x,&y,&z);
		{
			if(x||y||z)
			{
				a=y-x;
				b=z-y;
				if(a==b)
				{
					printf("AP %d\n",z+a);
				}
				else
				printf("GP %d\n",(z*(y/x)));
			}
			else
			break;
		}
	}
}
