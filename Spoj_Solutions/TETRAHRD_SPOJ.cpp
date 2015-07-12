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
int T[5][5];
int M[31][5][5];
int T1[5][5];
int T2[5][5];
int F[5];
const int MOD=1000000007;
void preprocess()
{
	int i,j,ind=0,k;
	
		

	while(ind<31)
	{
		for(i=0;i<5;i++)
		for(j=0;j<5;j++)
		M[ind][i][j]=T2[i][j]=T1[i][j],T1[i][j]=0;
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				for(k=0;k<5;k++)
				{
					T1[i][j]=(T1[i][j]+1LL*T2[i][k]*T2[k][j])%MOD;
				}
			}
		}				
		ind++;
	}
	
	
}
int sum(int n)
{
	int i,j,k,ind;
	if(n<3)
	return 0;
	if(n==3)
	return 1;
	n-=4;
		memset(T1,0,sizeof T1);
		memset(T2,0,sizeof T2);
		for(i=0;i<5;i++)
		T1[i][i]=1;
		ind=0;
	while(n)
	{
		
		if(n&1)
		{
			for(i=0;i<5;i++)
			{
				for(j=0;j<5;j++)
				{
					
					for(k=0;k<5;k++)
					{
						T2[i][j]=(T2[i][j]+1LL*T1[i][k]*M[ind][k][j])%MOD;
					}
				}
			}
			for(i=0;i<5;i++)
			for(j=0;j<5;j++)
			T1[i][j]=T2[i][j],T2[i][j]=0;
		}
		n>>=1;
		ind++;
	}
	k=0;
	for(i=0;i<5;i++)
	k=(k+T1[4][i]*F[i])%MOD;
	return k;
}
int main()
{
	
	int t,n,m,i,j;
	
	F[0]=0;
	F[1]=0;
	F[2]=1;
	F[3]=1;
	F[4]=2;
	long long int ans;
	T[4][0]=1;
	T[4][1]=1;
	T[4][2]=1;
	T[4][3]=1;
	T[4][4]=1;
	T[3][1]=1;
	T[3][2]=1;
	T[3][3]=1;
	T[3][0]=1;
	T[2][3]=1;
	T[1][2]=1;
	T[0][1]=1;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		T1[i][j]=T[i][j];
	}
	preprocess();
	rd(t);
	while(t--)
	{
		rd(m);
		rd(n);
		ans=MOD+sum(n);
		ans-=sum(m-1);
		pdl(ans%MOD);
	}
}
