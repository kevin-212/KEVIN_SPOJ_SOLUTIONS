#include<bits/stdc++.h>
 
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define scan(a) scanf("%d",&a)
#define scanl(a) scanf("%lld",&a)
#define print(a) printf("%d",a)
#define printl(a) printf("%lld",a)
#define fin(i,j,n) for(int i=j;i<n;i++)
#define f0n(i,n) fin(i,0,n)
#define MAX 1000001
#define mod 10
using namespace std;
 
typedef pair<int,int>pii;
typedef long long LL;
inline void fast(int *a)
{
register char c=0;
while (c<33) c=getchar_unlocked();
*a=0;
while (c>33)
{
*a=*a*10+c-'0';
c=getchar_unlocked();
}
}
bool cmp(const pii &left,const pii &right)
{
	return left.second<right.second;
}
int gcd(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	else
		return gcd(b,a%b);
}
#define Pu putchar_unlocked
#define write(n) r=n; chptr=s; *chptr=r%10+'0'; r/=10; for (; r; r/=10) {++chptr; *chptr=r%10+'0'; } Pu(*chptr); for (; chptr!=s; ) Pu(*--chptr);
 
LL r;
   char s[20];
   char *chptr;
int m[MAX];
int main()
{
	int t;
	fast(&t);
	while(t--)
	{
		int n;
		int cnt=0,ans1=0,ans2=0,i=1;
		fast(&n);
		int a;
		
		int mn=MAX;
		int mx=0;
		memset(m,0,sizeof(m));
		for(int j=0;j<n;j++)
		{
			fast(&a);
			m[a]=1;
			mx=max(mx,a);
		}
		
		while(i<mx+1)
		{
			while(m[i]==0&&i<mx+1) i++;
			while(m[i]==1&&i<mx+1)
			{
				cnt++;
				i++;
			}
			ans1+=cnt/3;
			if(cnt%3!=0)
				ans1++;
			ans2+=(cnt/2)+(cnt%2);
			cnt=0;
		}
		write(ans1);printf(" ");
		write(ans2);
		printf("\n");
	}
	
}
