#include<bits/stdc++.h>
#define gc getchar_unlocked
#define pc putchar_unlocked
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
bool cmp(int  a,int b)
{
	return a>b;
}
int main()
{
	int t,i,j,k,ind;
	
	int ansi,ansj,ansk;
	int bit[3];
	rd(t);
	while(t--)
	{
		rd(i);
		rd(j);
		rd(k);
	
		ansi=ansj=ansk=0;
		ansi|=((i>>9&1)<<9);
		ansj|=((j>>9&1)<<9);
		ansk|=((k>>9&1)<<9);
		
		for(ind=8;ind>=0;ind--)
		{
			
			ansi|=((((i>>(ind+1))&1)^(i>>ind&1))<<ind);
			ansj|=(((j>>(ind+1)&1)^(j>>ind&1))<<ind);
			ansk|=(((k>>(ind+1)&1)^(k>>ind&1))<<ind);
			
		}
	
		i=(ansi^ansk);
		j=(ansj^ansk);
		k=(ansi^ansj);
			bit[0]=__builtin_popcount(i);
			bit[1]=__builtin_popcount(j);
			bit[2]=__builtin_popcount(k);
		sort(bit,bit+3);
	
		
		if(bit[0]+bit[1]==bit[2])
		printf("YES\n");
		else
		printf("NO\n");
	}
}
