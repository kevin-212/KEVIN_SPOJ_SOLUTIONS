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

char s[100001];
int z[100001];
void solve()
{
	int i,j,k,l,L,R;
	long long int ans=0;
	scanf("%s",s);
	l=strlen(s);
	z[0]=l;
	ans+=l;
	L=R=0;
	
	for(i=1;i<l;i++)
	{
		if(i>R)
		{
			L=R=i;
			while(R<l && s[R-L]==s[R])R++;
			z[i]=R-L,R--;
			
		}
		else
		{
			k=i-L;
			if(z[k]<R-i+1)z[i]=z[k];
			else
			{
				L=i;
				while(R<l && s[R-L]==s[R])R++;
				z[i]=R-L,R--;
			}
		}
		ans+=z[i];
	}
	pdl(ans);
}
int main()
{
	int t;
	
	rd(t);
	while(t--)
	{
	
	 solve();
	}
}
