#include<bits/stdc++.h>
#define gc getchar_unlocked
#define pc putchar_unlocked
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
	int t;
	int l,a,b,ans,temp,i,j,k,counta,countb;
	rd(t);
	char s[1010];
	while(t--)
	{
		ans=0;
		scanf("%s",s);
		l=strlen(s);
		temp=(int)ceil(l/9.00);
		a=4*temp;
		b=5*temp;
		counta=0;
		countb=0;
		temp*=9;
		for(i=0;i<l;i++)
		{
			if(s[i]=='a')
			counta++;
		}
		if(counta>a)
		ans=counta-a;
		countb=l-counta;
		
		if(countb>b)
		ans+=(countb-b);
		ans+=(temp-l);
	pd(ans);	
	}
	
}
