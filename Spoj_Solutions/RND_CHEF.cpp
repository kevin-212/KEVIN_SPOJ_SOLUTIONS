#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define mod 104857601
#define pii pair<int,int>
using namespace std;
inline void rd(int &x)
{
	x=0;
	register int c=gc();
	for(;c<48 || c>57;c=gc());
	for(;c>47 && c<58;c=gc()){
		x=(x<<1)+(x<<3)+c-48;
	}
}
inline void rdl(long long int &x)
{
	x=0;
	register int c=gc();
	for(;c<48 || c>57;c=gc());
	for(;c>47 && c<58;c=gc()){
		x=(x<<1)+(x<<3)+c-48;
	}
}
inline void pdl(long long int x)
{
	char c[21];
	int k=-1;
	do
	{
		c[++k]=x%10+48;
		x/=10;
	}while(x);
	while(k>=0)
	pc(c[k--]);
	pc('\n');
}
bool cmp(int  a,int b)
{
	return a>b;
}

typedef  vector< vector <long long int> > matrix;
matrix I;
matrix mul(matrix a,matrix b)
{
	int i,j,z;
	int K=a.size();
	matrix ret(K,vector< long long int >(K));
	for(i=1;i<K;i++)
	{
		for(j=1;j<K;j++)
		{
			for(z=1;z<K;z++)
			{
				ret[i][j]=ret[i][j]+(1LL*a[i][z]*b[z][j])%mod;
				if(ret[i][j]>=mod)
				ret[i][j]-=mod;
			}
		}
	}
	return ret;
}
matrix powe(matrix a,long long int power)
{
	if (power==0)
	return I;
	if(power==1)
	return a;
	matrix temp=powe(a,power>>1);
	matrix ret=mul(temp,temp);
	if(power%2==1)
	return mul(ret,a);
	else
	return ret;
}
int main()
{
	long long int n;
	int i,k;
	long long int j;

	scanf("%d",&k);
	scanf("%lld",&n);
	I.resize(k+1);
	vector<long long int >a(k+1);
	vector<long long int>c(k+1);
	matrix  matrix1( k+1,vector<long long int >(k+1));
	matrix ans( k+1,vector<long long int >(k+1));

	for(i=1;i<k;i++)
	{
		scanf("%lld",&a[i]);
		matrix1[i][i+1]=1;
		
	}
	scanf("%lld",&a[k]);
	
	for(i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		matrix1[k][k-i+1]=c[i];
		I[i].resize(k+1);
		I[i][i]=1;
		
	}
	
	if(n<=k)
	printf("%lld\n",a[n]);
		else{
		
		ans=powe(matrix1,n-1);

		j=0;
		for(i=1;i<=k;i++)
		{
			j=j+(1LL*ans[1][i]*a[i])%mod;
			if(j>=mod)
			j-=mod;
		}
		printf("%lld\n",j);
		}
}
