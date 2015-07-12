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
	pc('\n');
}
bool cmp(int  a,int b)
{
	return a>b;
}
vector<int>vec;
int main()
{
	int n,i,j,k;
	rd(n);
	if(n==1 || n==2)
	{
		pd(1);
		pc('\n');
		pd(1);
		pc('\n');
	}
	else if(n==3)
	{
		pd(2);
		pc('\n');
		pc('1');
		pc(' ');
		pc('3');
		pc('\n');
	}
	else{
		
		pd(n);
		pc('\n');
		vec.push_back(3);
		vec.push_back(1);
		vec.push_back(4);
		vec.push_back(2);
	
		for(i=5;i<=n;)
		{
			vec.push_back(i++);
			if(i<=n)
			vec.insert(vec.begin(),i++);
		}
		k=vec.size();
		for(i=0;i<k;i++)
		pd(vec[i]),pc(' ');
		pc('\n');
		
	}
	
	
}
