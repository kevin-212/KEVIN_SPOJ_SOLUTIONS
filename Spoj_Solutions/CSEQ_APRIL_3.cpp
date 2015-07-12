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
	int t,n,l,r,cnt[2],i,j,k,z;
	vector<int>v[2];
	rd(t);
	while(t--)
	{
		rd(n);
		cnt[0]=cnt[1]=0;
		rd(l);
		rd(r);
		k=r-l+2;
		v[0].resize(k);
		v[1].resize(k);
	

		for(i=1;i<k;i++)
		{
			v[0][i]=i;
			cnt[1]+=i;
		}
		z=1;
		for(j=1;j<n;j++)
		{
			v[z][k-1]=cnt[z];
			cnt[z^1]+=cnt[z];
			for(i=k-2;i>0;i--)
			{
				cnt[z]-=v[z^1][i+1];	
				v[z][i]=cnt[z];	
				cnt[z^1]+=cnt[z];
			}
			cnt[z]=0;
			z^=1;
		}
		pd(v[z^1][k-1]);
	}
}
