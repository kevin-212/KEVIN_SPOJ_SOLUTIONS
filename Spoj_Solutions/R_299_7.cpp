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
long long int arr[2000001];
long long int sum[2000001];
int main()
{
	int a,b,n,l,t,k,lo,high,mid;
	int i,j;
	long long int t1,t2,t3;
	rd(a);
	rd(b);
	rd(n);
	sum[0]=0;
	sum[1]=arr[1]=a;
	for(i=2;i<=2000000;i++)
	{
		arr[i]=arr[i-1]+b;
		sum[i]=sum[i-1]+arr[i];
	}
	while(n--)
	{
		rd(l);
		rd(t);
		rd(k);
		lo=l;
		high=t+l;
		t1=1LL*t*k;
		while(lo<=high)
		{
			mid=(lo+high)/2;
			t2=sum[mid]-sum[l-1];
			if(arr[mid]==t && t2==t1)
			break;
			if(arr[mid]>t  || t2>t1)
			high=mid-1,mid=high;
			else
			lo=mid+1;
		}
		if(mid<l)
		printf("-1\n");
		else
		printf("%d\n",mid);
	}
}
