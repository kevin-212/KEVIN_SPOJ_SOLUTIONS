#include<bits/stdc++.h>
#define gc getchar
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
int main()
{
	char s[100001];
	int i,j,k,l,t;
	bool check;
	rd(t);
	while(t--)
	{
	check=false;
	scanf("%s",s);
	l=strlen(s);
	if(l>13)
	printf("false\n");
	else if(l==3 || l==4)
	{
		for(i=0;i<l;i++)
		{
	
			if(s[i]<48 || s[i]>57)
			{
				check=true;
				break;
			}
		}
		if(check)
		printf("false\n");
		else
		printf("true\n");
	}
	else if(l==13)
	{
		if(s[0]!='+' || s[1]!='9' || s[2]!='1')
		{
			printf("false\n");
		}
		else
		{
			for(i=2;i<13;i++)
			{
				if(s[i]<48 || s[i]>57)
				{
					check=true;
					break;
				}
			}
			if(check)
			printf("false\n");
			else
			printf("true\n");	
		}
	}
	else if(l==11)
	{
		if(s[0]=='0')
		{
			for(i=1;i<11;i++)
			{
				if(s[i]<48 || s[i]>57)
				{
					check=true;
					break;
				}
			}
			if(check)
			printf("false\n");
			else
			printf("true\n");
		}
		else if(s[0]=='1')
		{
			if(s[1]!='8' || s[2]!='0' || s[3]!='0')
			printf("false\n");
			else{
			
			for(i=4;i<11;i++)
			{
				if(s[i]<48 || s[i]>57)
				{
					check=true;
					break;
				}
			}
			if(check)
			printf("false\n");
			else
			printf("true\n");
			}
		}
		else
		printf("false\n");
	}
	else if(l==10)
	{
		for(i=0;i<10;i++)
			{
				if(s[i]<48 || s[i]>57)
				{
					check=true;
					break;
				}
			}
			if(check)
			printf("false\n");
			else
			printf("true\n");
	}
	else if(l>10)
	{
		if(s[0]!='1' || s[1]!='8' || s[2]!='0' || s[3]!='0')
		printf("false\n");
		else
		{
			for(i=4;i<l;i++)
			{
				if(s[i]<48 || s[i]>57)
				{
					check=true;
					break;
				}
			}
			if(check)
			printf("false\n");
			else
			printf("true\n");
		}
	}
	else
	printf("false\n");
}
}
