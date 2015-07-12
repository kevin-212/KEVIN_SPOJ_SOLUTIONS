#include<bits/stdc++.h>
#define gc getchar
using namespace std;
void sd(int &x)
{
	 int c=gc();
	cout<<c<<endl;
	x=0;
	for(;(c<48 || c>57);c=gc());
	for(;c>47 && c<58;c=gc()){
		x=(x<<1)+(x<<3)+ c- 48;
	}

	
}

int main()
{
	int t,l,i,j,count;
	sd(t);
	
	char s[1001];
	while(t--)
	{
		cin>>s;
		l=strlen(s);
		j=l-1;
		count=0;
		for(i=0;i<=j;i++,j--)
		{
			if(s[i]!=s[j])
			{
				count++;
				if(count>1)
				break;
			}
			
		}
		if(i<=j)
		cout<<"no"<<endl;
		else
		cout<<"yes"<<endl;
	}
}
