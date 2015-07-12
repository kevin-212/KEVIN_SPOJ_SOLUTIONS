#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pii pair<int,int>
#define MOD 1000000007
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
	
	long long int t,T1,T2,t1,t2,i,j,k,l;
	long long int num,den,a,b;
	double ans;
	rdl(t);
	while(t--)
	{
		rdl(T1);
		rdl(T2);
		rdl(t1);
		rdl(t2);
		if(T1>T2)
		{
			i=T1;
			j=t1;
			T1=T2;
			t1=t2;
			T2=i;
			t2=j;
			
		}
		//t1=min(t1,T1);
		//t2=min(t2,T2);
		
		 if(t1==0 && t2==0)
		{
			k=1;
			j=0;
		}
	
		else if(t1==0)
		{
			k=1LL*T1*T2;
			
			
			
		}
		else{
		i=T1/t1;
		l=T1%t1;
		j=(t1+t2)/t1;
		i-=j;
		j=1LL*t1*(1LL*j*(j+1)/2LL);
		j+=(1LL*(t1+t2)*i);
		if(l>0)
		j+=(t2+l);
		j*=t1;
		k=1LL*T1*T2;
		}
		cout.precision(9);
		cout<<fixed<<(1.00*j/k)<<endl;
		
		
	}
}
