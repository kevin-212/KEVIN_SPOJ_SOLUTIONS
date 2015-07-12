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
	
	int t,n,k,i,j,l,a,b,z,ans,c;
	string str;
	char s[10001][21];
	rd(t);
	while(t--)
	{
		
		rd(n);
		rd(k);
		str="";
		for(i=0;i<n;i++)
		scanf("%s",s[i]);
		
		for(i=0;i<k;i++)
		{
			ans=1000000000;
			for(z=0;z<26;z++)
			{
				l=0;
			for(j=0;j<n;j++)
				{
					a=s[j][i]-97;
					l+=abs(a-z);
				}
				if(l<ans)
				ans=l,c=z;
				
			}
			str+=(char)(c+'a');		
		}
		
		cout<<str<<endl;
		
	}
	
}
