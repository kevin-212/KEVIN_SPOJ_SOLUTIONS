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
	
}
bool cmp(int  a,int b)
{
	return a>b;
}

int  main()
{
	int n,n1,n2,i,j,k;
	long long int ans=0;
	string a,b,d,e;
	char c;
	rd(n);
	rd(n1);
	for(i=0;i<n1;i++)
	{
		rd(j);
		c=(char)(j-'0');
		a+=c;
	}
	
	rd(n2);
	for(i=0;i<n2;i++)
	{
		rd(j);
		c=(char)(j-'0');
		b+=c;
		
	}
	d=a;
	e=b;
	if(a[0]>b[0])
	{
		a+=b[0];
		a+=a[0];
		a=a.substr(1,a.length()-1);
		b=b.substr(1,b.length()-1);
	}
	else
	{
		b+=a[0];
		b+=b[0];
		b=b.substr(1,b.length()-1);
		a=a.substr(1,a.length()-1);
	}
	bool check=false;
	ans++;
	while((a!=d) && (b!=e))
	{
		if(a.length()==0 || b.length()==0)
		{
		check=true;
		if(a.length()==0)
		j=2;
		else
		j=1;
		break;
		}
		ans++;
		if(a[0]>b[0])
	{
		a+=b[0];
		a+=a[0];
		a=a.substr(1,a.length()-1);
		b=b.substr(1,b.length()-1);
	}
	else
	{
		b+=a[0];
		b+=b[0];
		b=b.substr(1,b.length()-1);
		a=a.substr(1,a.length()-1);
	}
		
		
	}
	if(check)
	pdl(ans),pc(' '),pd(j);
	else
	pd(-1),pc('\n');
	
}
