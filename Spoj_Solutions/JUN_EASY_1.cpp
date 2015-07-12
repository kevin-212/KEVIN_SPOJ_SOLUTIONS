#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pii pair<int,int>
using namespace std;
inline void rdl(int &x)
{
	x=0;
	bool check=false;
	register int c;
	do{
		c=gc();
		if(c=='-')
		check=true;
	}while(c<48 || c>57);
	for(;c>47 && c<58;c=gc()){
		x=(x<<1)+(x<<3)+c-48;
	}
	if(check)
	x=-x;
}
inline void rd(int &x)
{
	x=0;
	bool check=false;
	register int c=gc();
	for(;c<48 || c>57;c=gc());
	for(;c>47 && c<58;c=gc()){
		x=(x<<1)+(x<<3)+c-48;
	}

}
inline void pd(int x)
{
	char c[11];
	bool check=false;
	int k=-1;
	if(x<0)
	check=true,x=-x;
	do
	{
		c[++k]=x%10+48;
		x/=10;
	}while(x);
	if(check)
	c[++k]='-';
	while(k>=0)
	pc(c[k--]);
	pc('\n');
}
inline void pdl(long long int x)
{
	char c[21];
	bool check=false;
	int k=-1;
	if(x<0)
	check=true,x=-x;
	do
	{
		c[++k]=x%10+48;
		x/=10;
	}while(x);
	if(check)
	c[++k]='-';
	while(k>=0)
	pc(c[k--]);
	pc('\n');
}
bool cmp(int  a,int b)
{
	return a>b;

}
int arr[100001];
int main()
{
	int t,n,k,i,j,l,a;
	bool f1,f2,f3;
	rd(t);
	for(int b=1;b<=100000;b++)
	{
		n=b;
		while(n>=5)
		{
			i=n;
			j=n>>1;
			k=n>>2;
			if((i&1)  && (!(j&1)) && (k&1))
			{
				arr[b]++;
				n>>=2;
			}
			else
			n>>=1;
		}
	}
	
	while(t--)
	{
		l=0;
		rd(n);
		rd(a);
		for(i=1;i<=n;i++)
		if(arr[i]>=a)
		l++;
		pd(l);
		
		
	}
	
}

