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
char s[4][1001];
typedef  vector< vector<long long int > >matrix;
const int MOD =1000000007;
matrix I(4,vector<long long int>(4,0));

matrix mul(matrix a,matrix b)
{
	matrix ret(4,vector<long long int>(4,0));
	int i,j,k;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			
			for(k=0;k<4;k++)
			{
				ret[i][j]=(ret[i][j]+1LL*a[i][k]*b[k][j])%MOD;
					
			}
		}
	}
	return ret;
}
matrix powe(matrix T,int n)
{
	if(n==0)
	return I;
	if(n==1)
	return T;
	matrix a=powe(T,n/2);
	matrix b=mul(a,a);
	if(n&1)
	return mul(b,T);
	return b;
	
	
}
int main()
{
	int a,b,c,d,n,t;
	int f[4];
	matrix T(4,vector<long long int>(4));
	rd(t);
	while(t--)
	{
	
	
	rd(a);
	rd(b);
	rd(c);
	rd(d);
	rd(f[0]);
	rd(f[1]);
	rd(f[2]);
	f[3]=d;
	rd(n);
	
	
	int i,j,k;
	for(i=0;i<4;i++)
	{
	I[i][i]=1;
	for(j=0;j<4;j++)
	T[i][j]=0;
	}
	T[0][1]=1LL;
	T[1][2]=1LL;
	T[2][3]=1LL;
	T[2][2]=a;
	T[2][1]=b;
	T[2][0]=c;
	T[3][3]=1LL;
	matrix ans=powe(T,n-1);
	long long int ans2=0;
	for(i=0;i<4;i++)
	{
		
			ans2=(ans2+1LL*ans[0][i]*f[i])%MOD;
		
	}
	pdl(ans2);
	}
}
