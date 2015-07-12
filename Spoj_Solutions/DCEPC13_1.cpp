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
	int t,l,i,j,k;
	rd(t);
	char s[1005];
	while(t--)
	{
		scanf("%s",s);
		l=strlen(s);
		i=0;
	
		while(s[i]=='6' || s[i]=='9')
		{
			i++;
			if(i>=l)
			break;
		}
		if(i<l)
		{
			if(s[i]<'6')
			s[i]='6';
			else
			s[i]='9';
			
			for(j=i+1;j<l;j++)
			s[j]='6';
		}
		else
		{
			i=l-1;
			while(s[i]!='6' && i>=0)
			i--;
			if(i>=0){
			s[i]='9';
			for(j=i+1;j<l;j++)
			s[j]='6';
			}
			else{
				
			for(i=0;i<=l;i++)
			s[i]='6';
			s[l+1]='\0';
			}
		}
		printf("%s\n",s);
	}
}
