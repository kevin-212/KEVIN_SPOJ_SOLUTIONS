#include<bits/stdc++.h>
using namespace std;
inline void rd(int &x)
{
	x=0;
	register int c=getchar();
	for(;c<48 || c>57;c=getchar_unlocked());
	for(;c>47 && c<58;c=getchar_unlocked()){
		x=(x<<1)+(x<<3)+c-48;
	}
}

inline void pd(long long int x)
{
	char c[25];
	int k=-1;
	do
	{
		c[++k]=x%10+48;
		x/=10;
	}while(x);
	while(k>=0)
	putchar_unlocked(c[k--]);
	putchar_unlocked('\n');
}
bool cmp(int  a,int b)
{
	return a>b;
}
long long int mask[1050000];
int main()
{
	int t,n;
	int i,j,k;
	rd(t);
	
	int arr[21][21];
	int lim;
	while(t--)
	{
		rd(n);
		
		
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			rd(arr[i][j]);
		
	lim=(1<<n);		
	fill(mask,mask+lim+1,0);
			mask[0]=1;
			
			
				
				for(j=0;j<lim-1;j++)
				{
				  k=__builtin_popcount(j);	
					for(i=0;i<n;i++)
					{
						if(arr[k][i]==1 && (j&(1<<i))==0)
						{
							mask[j|1<<i]+=mask[j];
						}
					}
				}
			//pd(mask[0]);
			pd(mask[lim-1]);
		
			
	}
}
