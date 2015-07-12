#include<bits/stdc++.h>
#define gc getchar_unlocked
using namespace std;
void sd(int &x)
{
	 register int c=gc();
	x=0;
	for(;c<48 || c>57;c=gc());
	for(;c>47 && c<58;c=gc()){x=(x<<1)+(x<<3)+c-48;	}
}

int main()
{
	int t;
	sd(t);
	int o,s;
	double r;
	while(t--)
	{
		sd(o);
		cin>>r;
		sd(s);
		cout<<(double)(((o*r)+s)/(o+1))<<endl;
	}
}


