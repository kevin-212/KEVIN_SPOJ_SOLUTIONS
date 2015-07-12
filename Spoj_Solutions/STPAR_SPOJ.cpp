#include<bits/stdc++.h>
#define gc getchar_unlocked
#define pc putchar_unlocked
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
	int n,i,j,k;
	int arr[1001];
	
	while(true)
	{
	stack<int>st;
	rd(n);
	if(!n)
	break;
	for(i=0;i<n;i++)
	{
		rd(arr[i]);
	}
	j=1;
	for(i=0;i<n;)
	{
		if(arr[i]!=j)
		{	
			if(!st.empty()) 
			{
			if(st.top()!=j)
			st.push(arr[i]),i++;
			else
			st.pop(),j++;
			}
			else
			st.push(arr[i]),i++;
		}
		else
		j++,i++;
		
	}
	while(!st.empty() && st.top()==j)
	{
		j++;
		st.pop();
	}
	if(st.empty())
	printf("yes\n");
	else
	{
		
		printf("no\n");
	}
}
}
