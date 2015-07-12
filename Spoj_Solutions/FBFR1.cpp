#include<bits/stdc++.h>
using namespace std;
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
	putchar_unlocked(c[k--]);
	putchar_unlocked('\n');
}
bool cmp(int  a,int b)
{
	return a>b;
}

int main()
{
	int n,m;
	rd(n);
	rd(m);
	int i;
	int arr[201];
	for(i=0;i<n;i++)
	{
		rd(arr[i]);
	}
	sort(arr,arr+n,cmp);
	
	pd(arr[m-1]);
}
