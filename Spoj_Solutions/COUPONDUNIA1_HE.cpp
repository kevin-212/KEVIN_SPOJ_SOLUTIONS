#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pii pair<int,int>
using namespace std;
inline void rd(long long int &x)
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
	int t;
	long long int l,r,sq1,sq2,ans;
	scanf("%d",&t);
	while(t--)
	{
		rd(l);
		rd(r);
		sq1=(long long int)ceil(sqrt(l));
		sq2=(long long int)floor(sqrt(r));
		pd(sq2-sq1+1);
	
	}
}
