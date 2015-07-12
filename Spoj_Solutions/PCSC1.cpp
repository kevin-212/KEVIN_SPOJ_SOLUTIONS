#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pii pair<int,int>
#define piii pair<int,pii>
#define pis pair<int,piii>
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
bool cmp(vector<int>a,vector<int>b)
{
	return a[0]>b[0];
}
bool cmp1(vector<int> a,vector<int>b)
{
	if(a[3]==b[3])
	{
		if(a[2]==b[2])
		return a[1]<b[1];
		else
		return a[2]<b[2];
	}
	else
	return a[3]<b[3];
	
}
vector<vector<int > > arr(100001,vector<int>(4));
vector< vector<int > > arr1(100001,vector<int>(4));
int main()
{
	int n,i,j,k,count=0;
	vector<vector<int > >::iterator it1,it2;
	it1=arr.begin();
	it2=arr1.begin();
	while(true)
	{
		rdl(n);
		if(n<0)
		break;
		arr[count][0]=arr1[count][0]=n;
		
		rd(i);
		rd(j);
		rd(k);
		arr[count][1]=arr1[count][1]=i;
		arr[count][2]=arr1[count][2]=j;
		arr[count][3]=arr1[count][3]=k;
		it1++;
		it2++;
		count++;
	}
	sort(arr.begin(),it1,cmp);
	sort(arr1.begin(),it2,cmp1);
	printf("Money:\n");
	for(i=0;i<count;i++)
	{
		putchar('[');
		pd(arr[i][0]);
		pc(',');
		pc(' ');
		if(arr[i][1]<10)
		putchar('0');
		pd(arr[i][1]);
		pc('/');
		if(arr[i][2]<10)
		putchar('0');
		pd(arr[i][2]);
		pc('/');
		if(arr[i][3]<10)
		putchar('0');
		pd(arr[i][3]);
		putchar(']');
		putchar('\n');
	}
	printf("Date:\n");
	
	for(i=0;i<count;i++)
	{
		putchar('[');
		pd(arr1[i][0]);
		pc(',');
		pc(' ');
		if(arr1[i][1]<10)
		putchar('0');
		pd(arr1[i][1]);
		pc('/');
		if(arr1[i][2]<10)
		putchar('0');
		pd(arr1[i][2]);
		pc('/');
		if(arr1[i][3]<10)
		putchar('0');
		pd(arr1[i][3]);
		putchar(']');
		putchar('\n');
	}
}
