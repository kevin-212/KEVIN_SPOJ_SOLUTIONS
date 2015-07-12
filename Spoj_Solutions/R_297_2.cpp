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
char s[200001];
char ans[200001];
	int arr[200001];
int main()
{
	
	scanf("%s",s);
	 
	int n,i,j,k,l,l1;
	rd(n);
	l=strlen(s);
	for(i=0;i<n;i++)
	{
		rd(j);
		j--;
		arr[j]++;
	}
	l1=(l+1)/2;
	k=0;
	for(i=0;i<l1;i++)
	{
		if((k+arr[i])&1)
		{
			ans[i]=s[l-i-1];
			ans[l-i-1]=s[i];
		}
		else
		ans[i]=s[i],ans[l-i-1]=s[l-i-1];
		
		k+=arr[i];
	}
	for(i=0;i<l;i++)
	pc(ans[i]);
}
