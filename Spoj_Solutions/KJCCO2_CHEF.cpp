#include<bits/stdc++.h>
#define gc getchar_unlocked
#define pc putchar
#define pii pair<int,int>
using namespace std;


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


void rdl(int &x)
{
	x=0;
	register int c=gc();
	for(;c<48 || c>57;c=gc());
	for(;c>47 && c<58;c=gc()){
		x+=(int)(c-48);
	}
	int temp;
	while(x>9){
	 	temp=x;
		x=0;
	while(temp)
	{
		x+=temp%10;
		temp/=10;
	}
	}
}


bool check[10];
int main()
{
	int t,n;
	char s[10][10]={"red","blue","pink","white","black","violet","cyan","yellow","green","brown"};
	rd(t);
	int i,j,k;
	while(t--)
	{
		memset(check,false,sizeof check);
	rd(n);
	for(i=0;i<n;i++)
	{
		rdl(j);
		check[j]=true;
		
	}
	for(i=9;check[i]==false;i--);
	printf("%s\n",s[i]);
}
}

