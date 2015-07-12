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

int main()
{
	
	int n;
	
	long long int mul1[10];
	long long int mul2[10];
	rd(n);
	int i,j,ind1=0,ind2=0,sz1,sz2,mnp=1000;
	for(i=0;i<n;i++)
	{
	
	rdl(j);
	if(j<0)
	mul1[ind1++]=j;
	else if(j>0)
	mul2[ind2++]=j,mnp=min(mnp,j);
	}
long long int ans=1LL;
	if(ind1==0)
	{
		if(ind2!=n)
		pd(0);
		else
		pd(mnp);
	}
	
	else
	{
		if(ind1&1)
		{
			for(i=0;i<ind1;i++)
			ans=1LL*ans*mul1[i];
			for(i=0;i<ind2;i++)
			ans=1LL*ans*mul2[i];
			
		}
		else
		{
			sort(mul1,mul1+ind1);
			for(i=0;i<ind1-1;i++)
			ans=1LL*ans*mul1[i];
			for(i=0;i<ind2;i++)
			ans=1LL*ans*mul2[i];
			
		}
		pdl(ans);
	}
	
}
