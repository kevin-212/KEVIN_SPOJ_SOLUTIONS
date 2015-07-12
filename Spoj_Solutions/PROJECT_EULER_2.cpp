#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pii pair<int,int>
using namespace std;
inline void rdl(long long int &x)
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
bool check[1000001];
vector<int>prime;
	vector<long long int>sum;
int main()
{
	int t;
	
	int i,j,k;
	long long int summ=0;
for(i=2;i<=1000;i++)
{
	if(!check[i])
	{
		prime.push_back(i);
		summ+=i;
		sum.push_back(summ);
		for(j=i*i;j<=1000000;j+=i)
		check[j]=true;
	}
}
for(i=1001;i<=1000000;i+=2)
if(!check[i])
{
	summ+=i;
	prime.push_back(i);
	sum.push_back(summ);
}
int sz=prime.size(),left,right,mid,n;
rd(t);
while(t--)
{
	rd(n);
	if(n<2)
	pd(0);
	


	else{
	
	left=0;
	right=sz-1;
	while(left<=right)
	{
		mid=(left+right)/2;
		if(prime[mid]==n)
		break;
		if(prime[mid]<n)
		left=mid+1;
		else
		right=mid-1,mid=right;
	}
	pdl(sum[mid]);
	}
	
}


}
