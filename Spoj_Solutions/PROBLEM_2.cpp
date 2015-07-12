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
struct box{
	
	int x_diff,y_diff;
	bool visited;
	
};


int main()
{
	
	int n,i,j,k,cnt=0,z;
	double ans;
	int**mat;
	queue<pii>Q;
	cout<<"Enter Value Of N"<<endl;
	rd(n);
	mat=new int*[n];
	
	for(i=0;i<n;i++)
	mat[i]=new int[n];
	box node[n][n];
	k=n*n;
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			rd(mat[i][j]);
			
			node[i][j].x_diff=node[i][j].y_diff=0;
			node[i][j].visited=false;
			
				if(mat[i][j]==1){
				Q.push(pii(i,j));	
				node[i][j].visited=true;
				cnt++;
			}
		}
		
		while(cnt!=k){
			while(!Q.empty()){
				i=Q.front().first;
				j=Q.front().second;
				Q.pop();
				
				if(((i-1)>=0) &&  (!node[i-1][j].visited)){
			
					node[i-1][j].x_diff=node[i][j].x_diff-1;
					node[i-1][j].y_diff=node[i][j].y_diff;
					node[i-1][j].visited=true;
					Q.push(pii(i-1,j));
					cnt++;
				}
				if(((j-1)>=0) &&  (!node[i][j-1].visited)){
			
					node[i][j-1].y_diff=node[i][j].y_diff-1;
					node[i][j-1].x_diff=node[i][j].x_diff;
					node[i][j-1].visited=true;
					Q.push(pii(i,j-1));
					cnt++;
				}
				if(((i+1)<n) &&  (!node[i+1][j].visited)){
			
					node[i+1][j].x_diff=node[i][j].x_diff+1;
					node[i+1][j].y_diff=node[i][j].y_diff;
					node[i+1][j].visited=true;
					Q.push(pii(i+1,j));
					cnt++;
				}
				if(((j+1)<n) &&  (!node[i][j+1].visited)){
			
					node[i][j+1].y_diff=node[i][j].y_diff+1;
					node[i][j+1].x_diff=node[i][j].x_diff;
					node[i][j+1].visited=true;
					Q.push(pii(i,j+1));
					cnt++;
				}
				if(cnt==k)
				break;
			}
			
		}
		
		cout<<endl;
		cout<<"Distance Matrix"<<endl;
		cout<<endl;
		
	for(i=0;i<n;i++){
	for(j=0;j<n;j++){
		
		k=abs(node[i][j].x_diff);
		k=k*k;
		z=abs(node[i][j].y_diff);
		k+=(z*z);
		cout<<(double)(sqrt(1.00*k))<<" ";
		}	
		cout<<endl;
	}
	
}
