#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pii pair<double,int>
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

struct cmp{
bool operator()(const pii a,const pii b)
{
	if(a.first==b.first)
	return a.second>b.second;
	return a.first<b.first;
}
	
};

int main()
{
	int t,n,i,j,k,ans,wicket;
	rd(t);
	queue<pii> arr;
	double p[8],temp;
	p[1]=(120.00/300.00);
	p[2]=(30.00/300.00);
	p[4]=p[2];
	p[6]=(10.00/300.00);
	p[3]=p[6];
	p[7]=p[6];
	p[0]=(90.00/300.00);
	p[5]=0;
	priority_queue<pii,vector<pii>,cmp>Q;
	
	while(t--)
	{
		rd(n);
		n*=6;
		ans=0;
		wicket=0;
		for(i=0;i<=7;i++)
		Q.push(pii(p[i],i));
		
		cout<<p[6]*p[6]<<endl;	
		for(i=1;i<=n;i++)
		{
			
			j=Q.top().second;
			
			temp=Q.top().first;
			temp*=p[j];
			cout<<j<<" "<<temp<<endl;
			Q.pop();
			
			Q.push(pii(temp,j));
			if(j<=6)
			ans+=j;
			else
			wicket++;
		}
		
	pd(ans);
	pd(wicket);
		
	}
}
