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
char s[54][54];
map<char,int>check;
int main()
{
	
	int n,m,i,j,k;
	char a,b,c,d;
	
	rd(n);
	rd(m);
	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	cin>>s[i][j];
	int ans=0;
	for(i=0;i<n-1;i++)
	for(j=0;j<m-1;j++)
	{
		a=s[i][j];
		b=s[i][j+1];
		c=s[i+1][j];
		d=s[i+1][j+1];
		check[a]++;
		check[b]++;
		check[c]++;
		check[d]++;
		if(check['f']==1 && check['a']==1 && check['c']==1 && check['e']==1)
		ans++;
		check.clear();
		
	}
	pd(ans);
	
}
