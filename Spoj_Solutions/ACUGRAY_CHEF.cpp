#include<iostream>
#include<cstring>

#define gc getchar
using namespace std;
void sd(int &x)
{
	 int c=gc();
	x=0;
	for(;c<48 || c>57;c=gc());
	for(;c>47 && c<58;c=gc()){
		x=(x<<1)+(x<<3)+c-48;
	}
	
	
}

int main()
{
	int t,l,i,j,k,prev;
	int c;
	char s[1001];
	string ans;
	sd(t);
	while(t--){
	ans="";
	 c=gc();

	for(;c<48 || c>57;c=gc());


	prev=0;
	for(;c>47 && c<58;c=gc()){
	c=c&1;
	ans=ans+char((prev^c)+48);
	prev=c;
	}
	cout<<ans<<endl;
}
}
