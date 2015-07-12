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

vector<int>M[21];
int K[1000001];
int P[21];

int main()
{
	 int i,j,k,cnt,mx;
	long long int a,b,c;
	M[0].resize(1000002);
	fill(M[0].begin(),M[0].end(),0);
	M[0][0]=M[0][1]=1;
	K[0]=-1;
	K[1]=0;
	
	for(i=2;i<=1000001;i++)
	{
		if((i&(i-1))==0)
		K[i]=K[i-1]+1;
		else
		K[i]=K[i-1];
		a=1LL*i;
		cnt=1;
		
		while(a!=1LL)
		{
			
			if(a<=1000000 && M[0][a]>0)
			{
			cnt+=M[0][a]-1;
			break;
			}
			
			if(a&1LL)
			{
				cnt+=2;
				a=(3LL*a+1);
				a>>=1;
				
			}
			else
			cnt+=1,a>>=1;
			
			
		}
		
		M[0][i]=cnt;
		
	}
	for(i=0;i<=20;i++)
	P[i]=(1<<i)-1;
	
	for(j=1;j<=20;j++)
	{
		for(i=0;i+(1<<j)<=1000001;i++)
		{
			if(M[j-1][i]>M[j-1][i+(1<<(j-1))])
			M[j].push_back(M[j-1][i]);
			else
			M[j].push_back(M[j-1][i+(1<<(j-1))]);
		}
		
	}
	ifstream cin("check.txt");
	for(i=1;i<=1000000;i++)
	{
		cin>>a;
		if(M[0][i]!=a)
		cout<<a<<" "<<M[0][i]<<" "<<i<<endl;
		
	}
	/*while(scanf("%d %d",&i,&j)!=EOF)
	{
		mx=0;
		a=min(i,j);
		b=max(i,j);
		cnt=K[b-a+1];
		mx=max(M[cnt][a],M[cnt][b-P[cnt]]);
		cout<<i<<" "<<j<<" "<<mx<<endl;
	}*/
	
}
