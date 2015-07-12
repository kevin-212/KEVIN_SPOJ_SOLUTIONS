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
bool visited[1<<20];
vector<int>diff;
int main()
{
	
	int n;
	rd(n);
	int i,j,k;
	int arr[1001];
	for(i=0;i<n;i++)
	rd(arr[i]);
	set<int>s;
	s.insert(arr[0]);
	visited[arr[0]]=true;
	diff.push_back(arr[i]);
	set<int>::iterator it1,it2,it3;
	for(i=1;i<n;i++)
	{
		
		it1=s.begin();
		it2=s.end();
		
		while(it1!=it2)
		{
			j=(*it1)|arr[i];
			cout<<*it1<<" "<<j<<endl;
			it3=(++it1);
			s.erase(--it1);
			it1=it3;
			if(!visited[j])
			diff.push_back(j),visited[j]=true;	
			s.insert(j);
		}
		if(!visited[arr[i]])
		diff.push_back(arr[i]),visited[arr[i]]=true;
		s.insert(arr[i]);
	}
	pd(diff.size());
	
	
}
