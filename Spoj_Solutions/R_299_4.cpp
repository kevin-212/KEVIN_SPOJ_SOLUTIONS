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
vector<vector<pii> >vec(3);
int main()
{
	
	int n,i,o,z,t,j,k;
	bool check=true;
	rd(n);
	z=o=t=0;
	for(i=1;i<=n;i++)
	{
		rd(j);
		k=j%3;
		
			vec[k].push_back(pii(j,i));
	
	}
	z=vec[0].size();
	o=vec[1].size();
	t=vec[2].size();
	if(z<t || z<o)
	check=false;
	if(o<t)
	check=false;
	if(check)
	{
		printf("Possible\n");
		sort(vec[0].begin(),vec[0].end());
		sort(vec[1].begin(),vec[1].end());
		sort(vec[2].begin(),vec[2].end());
		z=o=t=0;
		i=1;
		while(true)
		{
			if(i<=n)
			pd(vec[0][z++].second),pc(' '),i++;
			else
			break;
				if(i<=n)
			pd(vec[1][o++].second),pc(' '),i++;
			else
			break;
			if(i<=n)
			pd(vec[2][t++].second),pc(' '),i++;
			else
			break;
			
		}
		pc('\n');
	}
	else
	printf("Impossible\n");
	
	
}
