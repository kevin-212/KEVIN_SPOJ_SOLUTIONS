#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n,m,x,y;
	 long long int temp,temp1;
	int arr[20000];
	char c;
	int count;
	int maX;
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	
	
	for(int i=0;i<m;i++)
	{
		count=0;
		scanf("%c",&c);
		scanf("%c %d %d",&c,&x,&y);
		x--;	
	
		if(c=='U')
		arr[x]=y;
		else if(c=='Q')
		{
			if(y<0)
			printf("-1 -1\n");
			else
			{
			
				temp=arr[x]+y;
				temp1=arr[x]-y;
				maX=arr[x];
				for(int j=x;j<n;j++)
				{
					if(arr[j]>=temp1 && arr[j]<=temp)
					{
						count++;
						if(arr[j]>maX)
						maX=arr[j];
					}
					else
					break;
				}	
				printf("%d %d\n",count,maX-arr[x]);
			
			}
		}
	}
}
