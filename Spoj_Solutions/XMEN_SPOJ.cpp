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

int wolv[100001];
int magn[100001];
int temp[100001];
int n;
int lis[100001];
int func()
{
	lis[0]=0;
	int lo,high,mid,len=0;
	for(int i=0;i<=n;i++)
	{
		lo=1;
		high=len;
		while(lo<=high)
		{
			mid=(lo+high)/2;
			if(wolv[lis[mid]]<wolv[i])
			lo=mid+1;
			else
			high=mid-1;
		}
		lis[lo]=i;
		if(lo>len)
		len=lo;
		
	}
	
	return len;
	
}
int  main()
{
	int t,i,j,k;
	
	rd(t);
	while(t--)
	{
		
		rd(n);
		
		for(i=0;i<n;i++)
		{
			rd(wolv[i]);
			temp[wolv[i]]=i;
		}
		for(i=0;i<n;i++)
		{
			rd(magn[i]);
			wolv[i]=temp[magn[i]];
		}
		pd(func());
	}
	
}
