#include<bits/stdc++.h>
using namespace std;
inline void rd(int &x)
{
	x=0;
	register int c=getchar_unlocked();
	for(;c<48 || c>57;c=getchar_unlocked());
	for(;c>47 && c<58;c=getchar_unlocked()){
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
	putchar(c[k--]);
	putchar('\n');
}
bool cmp(int  a,int b)
{
	return a>b;
}
int main()
{
	int t,n,i,j,k;
	int arr[50001];
	rd(t);
	int disb,dise,count;
	bool check;
	while(t--)
	{
		rd(n);
		count=0;
		check=true;
		for(i=0;i<n;i++)
		rd(arr[i]);
		sort(arr,arr+n);
		disb=0;
		
		for(i=0;i<n && check;i+=6)
		{
			for(j=0;j<6 && i+j<n;j++)
			{
			
				dise=arr[i+j]-i-j-disb;
				if(dise<=0)
				{
				check=false;
				break;
				}
				count++;
			}
			disb++;
		}
		if(check)
		{
			cout<<"Bhai Ho!"<<endl;
		
		}
		else
		{
			cout<<"Killed"<<" "<<count<<endl;
		}
	}
}
