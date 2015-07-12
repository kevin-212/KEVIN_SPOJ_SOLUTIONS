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
vector<int>prime(1000000);
bool check[1000000001];
int main()
{
	long long int i,j;
	int t,k,m,n,sz=0,lo,high,mid;
	
	k=sqrt(1000000000);
	for(i=2;i<=k;i++)
	{
		if(!check[i])
		{
			sz++;
			prime.push_back(i);
			for(j=i*i;j<1000000001;j+=i)
			{
				check[j]=true;
			}
		}
	}
	for(i=k+1;i<1000000001;i++)
	if(!check[i])
	prime.push_back(i),sz++;
	rd(t);
	while(t--)
	{
		rd(m);
		rd(n);
		lo=0;
		high=sz;
		while(lo<=high)
		{
			mid=(lo+high)/2;
			k=prime[mid];
			if(k==m)
			break;
			if(k<m)
			lo=mid+1;
			else
			high=mid-1,mid=high;
			
		}
		while(prime[mid]<=n)
		pd(prime[mid++]);
	}
}
