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

int arr[1001];
pii temp[1000000];
int main()
{
	
	int t,n,m,b,ind=1,i,j1,mx,j,a,ind1;
	long long int T,k,lo,high,mid;
	
	//ifstream cin("R2.in");
	//ofstream cout("R2A.txt");
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>j1;
		ind1=0;
		mx=-100;
		for(i=1;i<=n;i++)
		cin>>arr[i],mx=max(mx,arr[i]);
		j=j1-n;
		lo=0;
		high=1LL*mx*1000000000;
		
		
		
		while(lo<=high)
		{
			k=0;
			mid=(lo+high)/2;
			for(i=1;i<=n;i++)
			k+=(mid/arr[i]);
			if(k<j)
			lo=mid+1;
			else
			high=mid-1;
		}
		k=0;
		ind1=0;
		for(i=1;i<=n;i++)
		{
		k+=(lo/arr[i]);
			a=(arr[i]-(lo%arr[i]))%arr[i];
			temp[ind1++]=(pii(a,i));
			temp[ind1++]=(pii(a+arr[i],i));
		}
		sort(temp,temp+ind1);
		j=j1-k;
		cout<<"Case #"<<ind++<<": "<<temp[j-1].second<<endl;
		
	
	}
}
