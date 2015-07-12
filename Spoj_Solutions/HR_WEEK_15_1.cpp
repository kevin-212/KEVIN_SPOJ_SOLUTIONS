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
int mat[9][9];
bool check()
{
	
	int i,j,k,a,b,c;
	for(i=0;i<9;i++)
	{
		b=(i/3)*3;
		for(j=0;j<9;j++)
		{
			a=mat[i][j];
			if(a>9 || a<1)
			return false;
			c=(j/3)*3;
			for(k=j+1;k<9;k++)
			{
			if(mat[i][k]==a)
			return false;
			}
			for(k=i+1;k<9;k++)
			{
				if(mat[k][j]==a)
				return false;
			}
			
			if(mat[b+((i+1)%3)][c+((j+1)%3)]==a)
			return false;
			if(mat[b+((i+1)%3)][c+((j+2)%3)]==a)
			return false;
			if(mat[b+((i+2)%3)][c+((j+1)%3)]==a)
			return false;
			if(mat[b+((i+2)%3)][c+((j+2)%3)]==a)
			return false;
		}
	}
	return true;
}
int main()
{
	int t,i,j,k,z,a,b,ind=1;
	rd(t);
	while(t--)
	{
		
		for(i=0;i<9;i++)
		for(j=0;j<9;j++)
		rdl(mat[i][j]);
		cout<<"Case #"<<ind++<<":"<<endl;
		if(check())
		cout<<"Serendipity"<<endl;
		else{
		
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				for(z=i;z<9;z++)
				{
					for(k=j+1;k<9;k++)	
					{
						a=mat[i][j];
						b=mat[z][k];
						mat[i][j]=b;
						mat[z][k]=a;
						if(check())
						{
							cout<<'('<<i+1<<','<<j+1<<')'<<" <-> "<<'('<<z+1<<','<<k+1<<')'<<endl;
							
						}
						mat[i][j]=a;
						mat[z][k]=b;	
					}
				}
				
			}
		}
		
	}
}
	
	
	
	
}
