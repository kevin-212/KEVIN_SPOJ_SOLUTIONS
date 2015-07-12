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

map<int,int>mp[301];
map<int,int>mp1;
bool check;
map<int,int>::iterator it1,it2;
int main()
{
	int n,i,j,k,a,b,c,q,T,ans,cnt;
	
	rd(n);
	
	
	for(i=0;i<n;i++)
	{
		rd(j);
		
		for(k=0;k<j;k++)
		{
			rd(a);
			mp[i][a]++;
			
		}
	}
	
	rd(q);
	
		
		while(q--)
		{
			rd(T);
			rd(j);	
			for(i=0;i<j;i++)
			rd(a),mp1[a]++;
			cnt=0;
			if(T==1)
			{
					
				it2=mp1.end();
				for(i=0;i<n;i++)
				{
					it1=mp1.begin();
					while(it1!=it2)
					{
						if(mp[i][it1->first]<(it1->second))
							break;
							it1++;
					}
				if(it1==it2)
				cnt++;
				}
				pd(cnt);
			}
			else if(T==2)
			{
				
				
				it2=mp1.end();
				for(i=0;i<n;i++)
				{
					it1=mp1.begin();	
					while(it1!=it2)	
					{
						
						if(mp[i][(it1->first)]>0)
						{
							cnt++;
							break;
						}
						it1++;
					}
					
				}
				pd(cnt);
				
			}
			else
			{
				
				it2=mp1.end();
			
				for(i=0;i<n;i++)
				{
					it1=mp1.begin();	
					while(it1!=it2)	
					{
						
						if(mp[i][(it1->first)]>0)
						{
							cnt++;
							break;
						}
						it1++;
					}
					
				}
				
				
				for(i=0;i<n;i++)
				{
					it1=mp1.begin();
					while(it1!=it2)
					{
						if(mp[i][it1->first]<(it1->second))
							break;
							it1++;
					}
				if(it1==it2)
				cnt--;
				}
				pd(cnt);
				
			}
			mp1.clear();
		}
}
	

