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

int main()
{
	
	int n,i,j,k,l;
	rd(n);
	string str;
	set<string>S;
	while(n--)
	{
		getline(cin,str);
		l=str.length();
		if(l>=20)
		{
			l-=20;
			for(i=0;i<=l;i++)
			{
				if(str[i]>47 && str[i]<58 && str[i+1]>47 && str[i+1]<58 && str[i+2]>47 && str[i+2]<58 && str[i+3]=='-')
				{
					if(str[i+4]>47 && str[i+4]<58 && str[i+5]>47 && str[i+5]<58 && str[i+6]=='-' && str[i+7]>47 && str[i+7]<58 && str[i+8]>47 && str[i+8]<58 && str[i+9]=='-')
					{
						for(j=10;j<=17;j++)
						{
							if(str[i+j]>47 && str[i+j]<58)
							continue;
							else
							break;
						}
						if(j==18)
						{
							if(str[i+18]=='-' && str[i+19]>64 && str[i+19]<91)
							S.insert(str.substr(i,20));
							
						}
						
					}
					
					
				}			
				
			}
			
			
		}
		
		
	}
	l=S.size();
	set<string>::iterator it=S.begin();
	set<string>::iterator it1=S.end();
	if(l==0)
	cout<<"JUNK"<<endl;
	else
	while(it!=it1)
	{
		cout<<*it<<endl;
		it++;
	}
}
