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
int indexx[100001];
int mx[100001];
int ans[100001];
bool cmp(int  a,int b)
{
	return mx[a]>mx[b];
}

int main()
{
	int t,n,m,i,j,k,x,y;
	rd(t);
	while(t--)
	{
		rd(n);
		for(i=0;i<n;i++)
		{
			indexx[i]=i;
			mx[i]=0;
			rd(m);
			for(j=0;j<m;j++)
			{
				rd(x);
				rd(y);
				mx[i]=max(mx[i],x);
			}
		}
		sort(indexx,indexx+n,cmp);
		k=n-1;
		for(i=0;i<n;i++)
		ans[indexx[i]]=k--;
		for(i=0;i<n;i++)
		pd(ans[i]),pc(' ');
		pc('\n');
	}
	
	
}
