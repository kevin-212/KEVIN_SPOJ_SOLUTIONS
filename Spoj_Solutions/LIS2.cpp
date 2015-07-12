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
inline void pdl(int x)
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
int arr[100001];
int arr1[100001];
set<pii> m[100001];

int main()
{
	
	int n;
	set<pii>::iterator it,it1;
	bool check;
	pii temp;
	int ans=0,i,k,j,lo,high,len=0,mid;
	rd(n);
	for(i=0;i<n;i++)
	{
		rdl(arr[i]),rdl(arr1[i]);
	}
	for(i=0;i<n;i++)
	{
		lo=1;
		high=len;
		while(lo<=high)
		{
			mid=(lo+high+1)/2;
			check=false;
			it=m[mid].begin();
			it1=m[mid].end();
			while(it!=it1)
			{
				j=it->first;
				k=it->second;
				if(j>=arr[i])
				break;
				if(k<arr1[i])
				{
					check=true;
					break;
				}
				it++;			
			}
			if(check)
			lo=mid+1;
			else
			high=mid-1;
		}
		m[lo].insert(pii(arr[i],arr1[i]));
		if(len<lo)
		len=lo;
	}
	pd(len);
	
}
