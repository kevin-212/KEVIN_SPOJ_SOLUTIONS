#include<bits/stdc++.h>
using namespace std;
/*inline void rd(int &x)
{
	x=0;
	register int c=getchar_unlocked();
	for(;c<48 || c>57;c=getchar_unlocked());
	for(;c>47 && c<58;c=getchar_unlocked()){
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
	putchar_unlocked(c[k--]);
	putchar_unlocked('\n');
}
bool cmp(int  a,int b)
{
	return a>b;
}*/
int main()
{
	int t;
	int arr[91];
	scanf("%d",&t);
	int i,j,k;


	
	memset(arr,0,sizeof arr);
		arr['A']=1;
		arr['B']=2;
		arr['D']=1;
		arr['O']=1;
		arr['P']=1;
		arr['Q']=1;
		arr['R']=1;
register int c;
	while(t--)
	{
		j=0;
		c=getchar();
	for(;c<65||c>90;c=getchar_unlocked());
	for(;c>=65 && c<=90;c=getchar_unlocked())
	{
		j+=arr[c];
		
	}
	
	
	
	printf("%d\n",j);
	}
	
	
	
	
}
