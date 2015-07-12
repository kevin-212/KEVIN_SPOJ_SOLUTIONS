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

inline void pd(long long int x)
{
	char c[21];
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
	int t,n;
	long long int ans,i;
	rd(t);
	while(t--)
	{
		rd(n);
		ans=0;
		if(n&1)
		{
			ans=(n>>1);
			i=(ans*(ans-1));
			ans+=i;
			pd(ans);
			
		}
		else
		printf("-1\n");
	}
}
