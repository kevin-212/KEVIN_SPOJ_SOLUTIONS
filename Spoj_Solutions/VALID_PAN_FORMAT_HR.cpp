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
	int t;
	char c[50];
	bool check;
	rd(t);
	while(t--)
	{
		check=false;
		scanf("%s",c);
		if(strlen(c)==10){
		
			if(c[0]>64 && c[0]<91)
			{
				
				if(c[1]>64 && c[1]<91)
				{
					
					if(c[2]>64 && c[2]<91)
					{
					
						if(c[3]>64 && c[3]<91)
						{
							
							
							if(c[4]>64 && c[4]<91)
							{
								
								if(c[5]>47 && c[5]<58)
								{
									
									if(c[6]>47 && c[6]<58)
									{
										
										if(c[7]>47 && c[7]<58)
										{
											
											if(c[8]>47 && c[8]<58)
											{
												
												if(c[9]>64 && c[9]<91)
												check=true;
												
											}
										}
										
									}
								}
							}
						}
						
					}
					
				}
				
			}
		}
		if(check)
		printf("YES\n");
		else
		printf("NO\n");
	}
}
