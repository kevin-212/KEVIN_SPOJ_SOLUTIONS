#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pii pair<int,int>
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
inline void pd(long long int x)
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
	
}
bool cmp(int  a,int b)
{
	return a>b;
}

bool check[31622780];
vector<int>prime;
bool isprime(long long int num)
{
	int root=(int)sqrt(num);
	int ind=lower_bound(prime.begin(),prime.end(),root)-prime.begin();
	while(ind>=0)
	{
		if(num%prime[ind]==0)
		return false;
		ind--;
	}
	return true;
}
int main(){

long long int i,j,n,temp,k;
long long int arr[4];
int t;

memset(check,false,sizeof check);
for(i=2;i<31622780;i++)
{
	if(check[i]==false)
	{
		prime.push_back(i);
		for(j=i*i;j<31622780;j+=i)
		check[j]=true;
	}
}
rd(t);
int sum;
while(t--)
{
	rdl(n);
	for(i=3;i>0;i--)
	{
		temp=n-2*i;
		if(temp==2)
		arr[i]=temp,n-=temp;
		else{
		
		if(!(temp&1))
		temp--;
		
		while(true){
		if(isprime(temp))
		{
			
			arr[i]=temp;
			n-=temp;	
			break;	
		}
		else
		temp-=2;
		}
	}
	}
	arr[0]=n;
	for(i=0;i<=3;i++)
	pd(arr[i]),pc(' ');
	pc('\n');
}


}
