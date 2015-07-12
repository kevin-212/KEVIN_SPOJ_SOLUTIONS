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
int arr[500][500];
	int cnt[500];
int main()
{
	int t,n,m,q,i,j,k,a,b,c;
	int mx;
	
		rd(n);
		rd(m);
		rd(q);
		
		mx=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				rd(arr[i][j]);	
		}
		
		for(i=0;i<q;i++)
		{
			rd(a);
			rd(b);
			a--;
			b--;
			arr[a][b]^=1;
			mx=0;
			for(k=0;k<n;k++)
			{
			cnt[k]=0;
			c=0;
			for(j=0;j<m;j++)
			{
				if(arr[k][j]==0)
				cnt[k]=max(c,cnt[k]),c=0;
				else
				c++;
			}
			cnt[k]=max(c,cnt[k]);
			mx=max(mx,cnt[k]);
			}
			pd(mx);
		}
		
}
