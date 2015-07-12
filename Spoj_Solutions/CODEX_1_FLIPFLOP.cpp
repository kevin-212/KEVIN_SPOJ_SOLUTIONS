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
	
	int t,i,j,k,l,ans,ans1;
	char s[100001];
	rd(t);
	while(t--)
	{
		scanf("%s",s);
		ans=0;
		l=strlen(s);
		k=0;
		ans=ans1=0;
		for(i=0;i<l;i++)
		{
			if(k==0)
			{
				if(s[i]!='X')
				ans++;
				else
				k^=1;
			}
			else 
			{
				if(s[i]!='Y')
				ans++;
				else
				k^=1;
				
			}
		}
		k=0;
		
		for(i=0;i<l;i++)
		{
			if(k==0)
			{
				if(s[i]!='Y')
				ans1++;
				else
				k^=1;
			}
			else 
			{
				if(s[i]!='X')
				ans1++;
				else
				k^=1;
				
			}
			
		}
	
		ans=min(ans,ans1);
		pd(ans);
	}

	
}
