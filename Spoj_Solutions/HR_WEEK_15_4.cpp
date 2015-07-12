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

long long int sum[200001];
long long int ans[200001];
int main()
{
	
	int n,m,q,i,j,k,col,row,d,x1,y1,x2,y2;
	long long int  a,b;
	char c;
	
	rd(n);
	rd(m);
	rd(q);
	while(q--)
	{
		c=gc();
		for(;c!='Q';c=gc());
		c=gc();
		if(c=='c')
		{
			rd(col);
			rd(d);
			sum[col]+=d;
			sum[col+n]-=d;;
			
		}
		else if(c=='r')
		{
			rd(row);
			rd(d);
			sum[n-row+1]+=d;
			sum[n-row+1+m]-=d;
			
		}
		else if(c=='s')
		{
			rd(x1);
			rd(y1);
			rd(x2);
			rd(y2);
			rd(d);
			for(i=x1;i<=x2;i++)
			{
				sum[n-i+y1]+=d;
				sum[n-i+y2+1]-=d;
			}
		}
		else
		{
			a=b=0;
			rd(row);
			rd(col);
			
			
			for(i=1;i<=col;i++)
			{
				a=(a+sum[i])%MOD;
				ans[i]=(a+ans[i-1])%MOD;
			}
			pdl(ans[col]-ans[row-1]);
		}
	}
}
