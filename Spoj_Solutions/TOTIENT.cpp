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
vector<int> prime;

int check[1000001];
int phi[1000001];
int main()
{
	int t,n,temp;
	rd(t);
	phi[1]=1;
int i,j,k,num;	
	for(i=2;i<=1000000;i++)
	{
		
		if(check[i]==0)
		{
			prime.push_back(i);
			phi[i]=i-1;
			if(i<=1000)
			for(j=i*i;j<=1000000;j+=i)	
			check[j]=i;
		}
		else
		{
			temp=i,num=0;
			while(temp%check[i]==0)
			temp/=check[i],num++;
			phi[i]=1;
			for(k=0;k<num;k++)
			phi[i]*=check[i];
			phi[i]-=phi[i]/check[i];
			phi[i]*=phi[temp];
			
		}
		
		
	}
	
	
	while(t--)
	{
		rd(n);
		pd(phi[n]);
	}
}
