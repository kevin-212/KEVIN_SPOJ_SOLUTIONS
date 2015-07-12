#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pii pair<int,int>
#define MOD 1000000007
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
int N[50001];
int M[50001];
int mer[100010];
int main()
{
	int t,n,m,i,j,k;
	rd(t);
	while(t--)
	{
	rd(n);
	rd(m);
	for(i=0;i<n;i++)
	rd(N[i]);
	for(i=0;i<m;i++)
	rd(M[i]);
	i=0,j=0;
	k=0;
	while(i<n && j<m)
	{
		if(N[i]<=M[j])
		pd(M[j++]),pc(' ');
		else 
		pd(N[i++]),pc(' ');
	}
	while(i<n)
	pd(N[i++]),pc(' ');
	while(j<m)
	pd(M[j++]),pc(' ');
	pc('\n');
	}
	
}
