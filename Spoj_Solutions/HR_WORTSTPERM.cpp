#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pii pair<int,int>
using namespace std;
inline void rd(int &x)
{
	x=0;
	register int c=gc();
	for(;c<48 || c>57;c=gc());
	for(;c>47 && c<58;c=gc()){
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
	pc(c[k--]);
	pc('\n');
}
bool cmp(int  a,int b)
{
	return a>b;
}
int main()
{
	int n,k,temp,temp1;
	int arr[100001];
	int loc[100001];
	rd(n);
	rd(k);
	int i,j;
	for(i=0;i<n;i++)
	{
		rd(j);
		arr[j]=i;
		loc[i]=j;
	}
	if(k>=n-1)
	{
		for(i=0;i<n;i++)
		printf("%d ",n-i);
	}
	else
	{
		j=n;
		for(i=0;i<n && k;i++)
		{
			temp=loc[i];
			if(temp!=j)
			{
				
				loc[i]=j;
				temp1=arr[j];
				loc[temp1]=temp;
				arr[temp]=temp1;
				k--;
				
			}
			j--;
		}
		for(i=0;i<n;i++)
		printf("%d ",loc[i]);
	
	}
	
}
