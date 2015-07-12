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
typedef vector< vector <long long int > > matrix;
matrix T;
matrix inv;
matrix I;
 long long int f[51];
int n;
const int MOD=1000000007;
matrix mul(matrix a,matrix b)
{
	matrix c(n+1,vector<long long int>(n+1,0));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			
			for(int k=1;k<=n;k++)
			{
				c[i][j]=(c[i][j]+1LL*a[i][k]*b[k][j])%MOD;;
				
			}
			while(c[i][j]<0)
			c[i][j]+=MOD;
		}
	}
	return c;
	
}
matrix powe(matrix a,int n)
{
	if(n==0)
	return I;
	if(n==1)
	return a;
	matrix b=powe(a,n/2);
	matrix c=mul(b,b);
	if(n&1)
	return mul(c,T);
	else
	return c;
	
}
 long long int powee(  long long int a,int b)
{
 long long int ans=1LL;
	while(b)
	{
		if(b&1)
		ans=(1LL*ans*a)%MOD;
		
		a=(1LL*a*a)%MOD;
		b>>=1;
	}
	return ans;
}
void inverse(matrix e)
{
	
	
	vector< vector<long long int> >a(n+1,vector<long long int> (2*n+1,0));
	int i,j,k,b,fi;
	long long int  d,c;
	
	
	
	b=2*n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		a[i][j]=e[i][j];	
		a[i][i+n]=1LL;
		
	}
	
	
		
		for(i=1;i<n;i++)
		{
			
			fi=i;
			for(j=i+1;j<=n;j++)
			{
				if(a[j][i]>a[fi][i])
				fi=j;
				
			}
			if(fi>i){				
				for(j=1;j<=b;j++)
				{
					d=a[i][j];
					a[i][j]=a[fi][j];
					a[fi][j]=d;
					
				}
				
			
			}
			
		}
	for(i=1;i<=n;i++)
	{
		
		
		for(j=1;j<=n;j++)
		{
			
			if(i!=j)
			{
				//cout<<a[j][i]%a[i][i]<<endl;
				d=powee(a[i][i],MOD-2);
				d=(1LL*a[j][i]*d)%MOD;
				
				for(k=1;k<=b;k++)
				{
					a[j][k]=(a[j][k]-(1LL*a[i][k]*d))%MOD;
					while(a[j][k]<0)
					a[j][k]+=MOD;
				}
				
			}
		}
	}	
	

	for(i=1;i<=n;i++)
	{
		d=powee(a[i][i],MOD-2);
		for(j=1;j<=b;j++)
		{
		a[i][j]=(1LL*a[i][j]*d)%MOD;
		while(a[i][j]<0)
		a[i][j]+=MOD;
		}
	
	}
	
	
	for(i=n;i>=1;i--)
	{
		d=0;
		for(j=n+1;j<=b;j++)
		{
			d=(d+1LL*a[i][j]*f[j-n])%MOD;
			while(d<0)
			d+=MOD;
			
		}
		cout<<d<<" ";
		
	} 
	
}
int main()
{
	//ifstream cin("check.txt");
	 int k,i,j;
	//rd(n);
	//rd(k);
	cin>>n;
	cin>>k;
	T.resize(n+1,vector<long long int >(n+1,0));
	I.resize(n+1,vector<long long int>(n+1,0));
	for(i=n;i>=1;i--)
	//rd(f[i]);
	cin>>f[i];
	for(i=1;i<n;i++)
	T[i][i+1]=1LL,I[i][i]=1LL;
	I[n][n]=1LL;
	for(i=n;i>=1;i--)
	//rd(T[n][i]);
	cin>>T[n][i];
	matrix a=powe(T,k-n+1);
	inverse(a);
	
}

