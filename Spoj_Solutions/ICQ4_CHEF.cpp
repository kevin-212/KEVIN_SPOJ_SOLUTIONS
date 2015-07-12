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
char c3[1000001];
char c1[1000001];
char c2[1000001];
int main()
{
	int t,i,j,k,l;
	char c;
	rd(t);
	while(t--)
	{
		i=j=k=0;
		c=gc();
		for(;c<48 && c>57;c=gc());
		for(;c>47;c=gc())
		{
			c3[k++]=c;
			if(c<58)
			c1[i++]=c;
			else
			c2[j++]=c;	
		}
		sort(c1,c1+i);
		sort(c2,c2+j);
		l=j=0;
		for(i=0;i<k;i++)
		{
			if(c3[i]<58)
			pc(c1[l++]);
			else
			pc(c2[j++]);
		}
		pc('\n');
	}
}
