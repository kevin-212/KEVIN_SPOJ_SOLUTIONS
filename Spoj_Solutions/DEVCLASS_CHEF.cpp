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

inline void pdl(long long int x)
{
	char c[21];
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
	int t;
	rd(t);
	char s[100001];
	int countb,countg,i,j,l,type,oddg,eveng,oddb,evenb;
	long long int ans,k;
	vector<int>girlso,girlse;
	vector<int>boyso,boyse;
	while(t--)
	{
		rd(type);
		scanf("%s",s);
		l=strlen(s);
		countb=0;
		ans=0;
		girlso.clear();
		boyso.clear();
		girlse.clear();
		boyse.clear();
		for(i=0;i<l;i++)
		{
			if(s[i]=='B')
			{
				countb++;
				if(i&1)
				boyso.push_back(i);
				else
				boyse.push_back(i);
			}
			else
			{
					if(i&1)
					girlso.push_back(i);
					else
					girlse.push_back(i);
			}
		}
		countg=l-countb;
		oddg=girlso.size();
		evenb=boyse.size();
		oddb=countb-evenb;
		eveng=countg-oddg;
		
		if(countg==countb+1)
		{
			
			
			if(type==0)
			{
				pd(oddg);
			}
			else
			{
			
				for(i=0;i<oddg;i++)
				{
					ans+=abs(girlso[i]-boyse[i]);
				}
				pdl(ans);
				
				
			}
		}
		else if(countb==countg+1)
		{
			if(type==0)
			{
				pd(oddb);
			}
			else
			{
				
				for(i=0;i<oddb;i++)
				{
					ans+=abs(boyso[i]-girlse[i]);
				}
				pdl(ans);
			}
		}
		else if(countb==countg)
		{
			if(type==0)
			{
				pd(min(oddg,eveng));
			}
			else
			{
				
				k=0;
				for(i=0;i<oddb;i++)
				{
					ans+=abs(boyso[i]-girlse[i]);
				}
			
				for(i=0;i<oddg;i++)
				{
					k+=abs(girlso[i]-boyse[i]);
				}
					pdl(min(k,ans));				
			}
		}
		
		else
		printf("-1\n");
	}
}
