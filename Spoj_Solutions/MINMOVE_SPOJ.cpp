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
char s[100001];
int i,j,k,a,b,l,temp;

int main()
{
scanf("%s",&s);
	
l=strlen(s);
temp=2*l;
i=k=0;
j=1;
while(i+k<temp && j+k< temp)
{
if(i+k>=l)
a=s[i+k-l];
else
a=s[i+k];
if(j+k>=l)
b=s[j+k-l];
else
b=s[j+k];
if(a==b)k++;
else if(a>b)
{
i=i+k+1;
if(i<=j)
i=j+1;
k=0;
}
else
{
	j=j+k+1;
	if(j<=i)
	j=i+1;
	k=0;
}
	
}
	pd(min(i,j));
}
