#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pii pair<int,int>
#define MOD 1000000007
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
int arr[100002];
int candy[100002];
bool cmp(int  a,int b)
{
	return arr[a]<arr[b];
}

int ind[100001];
int main()
{
	int n,i,j,k;
	long long int ans=0;
	rd(n);
	for(i=1;i<=n;i++)
	rd(arr[i]),ind[i]=i;
	sort(ind+1,ind+n+1,cmp);
	
	for(i=1;i<=n;i++)
	{
		
		if(arr[ind[i]-1]==arr[ind[i]]  && arr[ind[i]+1]==arr[ind[i]])
			candy[ind[i]]=1;
			else if(arr[ind[i]-1]==arr[ind[i]])
			candy[ind[i]]=candy[ind[i]+1]+1;
		
		else if(arr[ind[i]+1]==arr[ind[i]])
			candy[ind[i]]=candy[ind[i]-1]+1;
			else
		candy[ind[i]]=max(candy[ind[i]-1],candy[ind[i]+1])+1;
		ans+=candy[ind[i]];
	}
	pdl(ans);
}
