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
int main()
{
	int n,r,avg;
	rd(n);
	rd(r);
	rd(avg);
	long long int total=1LL*n*avg;
	long long int sum=0;
	vector<pii>arr;
	int i,j,k;
	for(i=0;i<n;i++)
	{
		rd(j);
		rd(k);
		if(j<r)
		arr.push_back(pii(k,r-j));
		sum+=j;
	}
	sort(arr.begin(),arr.end());
	long long int ans=0;
	int sz=arr.size();
	sum=total-sum;
	if(sum>0){
	
	for(i=0;i<sz;i++)
	{
		j=arr[i].second;
		k=arr[i].first;
		if(j>=sum)
		{
			ans+=(1LL*sum*k);
			break;
		}
		ans+=(1LL*j*k);
		sum-=j;	
	}
	
	}
	pdl(ans);
}
