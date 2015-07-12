#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
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
inline void pd(long long int x)
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
	
	int n,l;
	rd(n);
	rd(l);
	set<int>s;
	int i,j,k;
	for(i=0;i<n;i++)
	rd(j),s.insert(j);
	 double a,b;
	a=0;
	k=0;
	set<int>::iterator it=s.begin();
	set<int>::iterator iend=s.end();
	if(*it!=0)
	{
		a=*it;
		it++;
		k=a;
		i=a;
	}
	while(it!=iend)
	{
		i=*it;
		b=(i-k)/2.00;
		a=max(a,b);
		k=i;	
		it++;
	}
	if(i!=l)
		b=(l-i);
		a=max(a,b);
		printf("%.9lf",a);
}
