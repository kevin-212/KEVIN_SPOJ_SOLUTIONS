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
	int t,c;
	int a,b;
	int first;
	char sign;
	bool check=false;
	rd(t);
	while(t--)
	{
		c=gc();
		a=b=0;
		for(;(c<48 || c>57) &&(c!='x') && (c!='-');c=gc());
//		cout<<c<<endl;
		if(c=='x')
		{
		sign=gc();
		first=1;
		c=gc();
		if(c=='-')
		check=true,c=gc();
		for(;c>47 && c<58;c=gc())
		{
			a=(a<<1)+(a<<3)+c-48;
		}
		if(check)
		a=-a,check=false;
		c=gc();
		if(c=='-')
		check=true,c=gc();
		for(;c>47 && c<58;c=gc())
		{
			b=(b<<1)+(b<<3)+c-48;
		}
		if(check)
		b=-b,check=false;
		}
		else{
			
			if(c=='-')
			check=true,c=gc();
		for(;c>47 && c<58;c=gc())
		{
			a=(a<<1)+(a<<3)+c-48;
		}
		if(check)
		a=-a,check=false;
		sign=c;
		first=2;
		c=gc();
		c=gc();
		c=gc();
		if(c=='-')
		check=true,c=gc();
		for(;c>47 && c<58;c=gc())
		{
			b=(b<<1)+(b<<3)+c-48;
		}
			if(check)
			b=-b,check=false;
			
		}
		//cout<<a<<sign<<b<<endl;
		if(sign=='+')
		{
			printf("%.7f\n",1.00*b-a);
			
		}
		else if(sign=='-')
			printf("%.7f\n",1.00*b+a);
			else if(sign=='/')
			{
				if(first==1)
					printf("%lld\n",1LL*b*a);
					else
						printf("%.7f\n",(1.00*a)/b);
			}
			else
			{
					printf("%.7f\n",(1.00*b)/a);
				
			}
		
	}
}
