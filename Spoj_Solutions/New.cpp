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
int arr[1000];
int index[1000];
int ans[1000];
stack<int>stk;
bool cmp(int  a,int b)
{
	return arr[a]>arr[b];
}
int main()
{
	int t,n,i,j,k,sum,cnt,cnt1,top;
	bool check;
	
	rd(t);
	while(t--)
	{
		rd(n);
		sum=0;
		check=true;
		for(i=0;i<n;i++)
		{
			rd(arr[i]);
			sum+=arr[i];
			if(arr[i]>=n)
			check=false;
			index[i]=i;
		}
		if(sum>n || check==false)
		{
		pd(-1);
		continue;
		}
		else
		{
			sort(index,index+n,cmp);
			for(i=0;i<n;i++)
			cout<<index[i]<<endl;
			i=1,k=0;
			while(i<=n)
			{
				j=index[k++];
				cnt1=arr[j];
				cnt=0;
				while((!stk.empty()) && (cnt<cnt1))
				{
					top=stk.top();
					stk.pop();
					cnt++;
					ans[top]=j;
				}
				while(cnt<cnt1)
				{
					if(i==j)
					{
						stk.push(i);
						
					}
					else
					ans[i]=j,cnt++;
					
				}
			}
			for(i=0;i<n;i++)
			pd(ans[i]+1),pc(' ');
			pc('\n');
		}
	}
	
	
}
