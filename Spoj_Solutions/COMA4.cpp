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
	return a<b;
}
int main()
{
	int t,n,m,o,i,j,count,count1;
	bool check;
	
	rd(t);
	while(t--)
	{
		count=count1=0;
		rd(n);
		check=false;
		rd(m);
		rd(o);
		rd(i);
		if(i<o)
		check=true;
		
		n--;
		if(check)
		{
		while(n--)
			rd(j);
				printf("-1\n");
		}
			
		else
		{
			while(n--)
			{
			
				rd(j);
				if(j>i)
				count++;
				if(j>=o)
				count1++;
			}
				if(count>=m)
				printf("-1\n");
				else
				pd(min(m,count1+1));
		}
	
		
		
		
	}
}
