#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
inline void rd(int &x)
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
	putchar(c[k--]);
	putchar('\n');
}
bool cmp(int  a,int b)
{
	return a>b;
}
int main()
{
	int t,x,y,n,k,i,j,p,c;
	pii arr[100001];
	rd(t);
	while(t--)
	{
		rd(x);
		rd(y);
		rd(k);
		rd(n);
		j=x-y;
		i=-1;
		while(n--)
		{
			rd(p);
			rd(c);
			if(p>=j)
			arr[++i]=pii(c,p);
		}
		if(i>=0)
		{
			sort(arr,arr+i+1);
			if(arr[0].first<=k)
			printf("LuckyChef\n");
			else
			printf("UnluckyChef\n");
		}
		else
		printf("UnluckyChef\n");
	}
}
