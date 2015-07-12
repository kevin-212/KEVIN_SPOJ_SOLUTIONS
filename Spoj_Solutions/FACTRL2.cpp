
#include<bits/stdc++.h>
using namespace std;
inline void rd(int &x)
{
	x=0;
	register int c=getchar();
	for(;c<48 || c>57;c=getchar());
	for(;c>47 && c<58;c=getchar()){
		x=(x<<1)+(x<<3)+c-48;
	}
}

inline void pd(int x)
{
	char c[11];
	int k=-1;
	do
	{
		c[++k]=x%10+48;
		x/=10;
	}while(x);
	while(k>=0)
	putchar(c[k--]);
	putchar('\n');
}
bool cmp(int  a,int b)
{
	return a>b;
}

int main()
{
	 int tc,i,j,k,num,temp;
	int arr[200000];
	rd(tc);
	
	while(tc--)
	{
		arr[0]=1;
		temp=0;
		k=0;	
		rd(num);
		for(i=1;i<=num;i++)
		{
			for(j=0;j<=k;j++)
			{
				temp=arr[j]*i+temp;
				arr[j]=temp%10;
				temp/=10;	
			}
			while(temp)
			{
				k++;
				arr[k]=temp%10;
				temp/=10;
			}
		}
		pd(k);
		for(i=k;i>=0;i--)
		putchar(arr[i]+48);
		putchar('\n');
	
	}
}
