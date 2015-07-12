#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
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

inline void pd(int x)
{
	char c[11];
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
int main()
{
	int tl,tr,i,j,k,l,r,n,m,ans,sz,sl,sr,sm;
	int arr1[100001];
	
	
	
		rd(n);
		rd(m);
		rd(k);
		vector<vector<int > >arr(m+1);
		for(i=1;i<=n;i++)
		rd(j),arr1[i]=j,arr[j].push_back(i);

		while(k--)
		{
			rd(l);
			rd(r);
			ans=0;
			for(j=l;j<=r;j++)
			{
				i=arr1[j];
				sz=arr[i].size();
				if(sz>1)
				{
					sl=arr[i][0];
					sr=arr[i][sz-1];
					if(sl<=r && sr>=l)
					{
						tl=*(upper_bound(arr[i].begin(),arr[i].end(),l-1));
						sl=0;
						sr=sz-1;
						while(sl<=sr)
						{
							sm=(sl+sr)/2;
							if(arr[i][sm]==r)
								break;
							
							if(arr[i][sm]<r)
							sl=sm+1;
							else
							sr=sm-1,sm=sr;
							
						}
					tr=arr[i][sm];
					
					ans=max(ans,tr-tl);
					}
					
				}
			}
			pd(ans);
			
		}
		
		
	
}
