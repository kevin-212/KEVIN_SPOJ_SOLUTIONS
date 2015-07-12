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
	int t,n,i,j,k;
	string s,a,b,c;
	char c1,c2;
	rd(t);
	while(t--)
	{
		rd(n);
		cin>>s;
		a=s;
		cout<<a<<endl;
		for(i=0;i<n;i++)
		{
			
			for(j=0;j<n;j++)
			{
				if(i==j)
				continue;
				b="";
				if(i<j)
				{
					b+=s.substr(0,i);
					b+=s.substr(i+1,j-i);
					b+=s[i];
					b+=s.substr(j+1,n-j-1);
				}
				else
				{
					b+=s.substr(0,j);
					b+=s[i];
					b+=s.substr(j,i-j);
					b+=s.substr(i+1,n-i-1);
					
				}
				
				
				a=min(a,b);
				//cout<<a<<endl;	
			}
		}
		cout<<a<<endl;
	}
}
