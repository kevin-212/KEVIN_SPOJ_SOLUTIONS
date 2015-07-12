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
	int v1,v2,t,d,ans,i,j,k,k1;
	rd(v1);
	rd(v2);
	rd(t);
	rd(d);
	if(d==0)
	{
		pd(v1*t);
	}
	else if(t==2)
	{
		pd(v1+v2);
	}
	else
	{
		if(v1>v2)
		{
			i=v1;
			v1=v2;
			v2=i;
		}
		i=v2-v1;
		j=((t-1)*d+i)/2;
		k=j/d;
		k++;
		ans=((2*v1+((k-1)*d))*k)/2;
		k=t-k;
		
		ans+=((2*v2+((k-1)*d))*k)/2;
		pd(ans);
	}
}
