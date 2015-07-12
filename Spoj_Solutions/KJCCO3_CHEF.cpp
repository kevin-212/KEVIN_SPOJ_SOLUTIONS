#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pii pair<int,int>
using namespace std;
inline void rdl(long long int &x)
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

int main()
{
	char s[120];
	char ans[220];
	stack<int>arr1;
	stack<int>arr2;
	gets(s);
	int l=strlen(s);
	int i,j,k,temp1,temp2,temp3,ind,carry,l1,l2;
	i=0;
	j=s[i]-48;
	for(;s[i]>47 && s[i]<58;j=s[i]-48)
	{
		arr1.push(j);
		i++;
		
	}
	temp1=temp2=temp3=carry=0;
	ind=-1;
	if(s[i]=='+')
	{
	
		
		for(k=l-1;k>i && !arr1.empty();k--)
		{
			j=s[k]-48;
			temp1=arr1.top()+j+carry;
			arr1.pop();
			ans[++ind]=(temp1%10)+48;
			carry=temp1/10;
		}
		if(k==i)
		{
			while(!arr1.empty())
			{
				temp1=arr1.top()+carry;
				arr1.pop();
				ans[++ind]=(temp1%10)+48;
				carry=temp1/10;
			}
		}
		else
		{
			for(;k>i;k--)
			{
				j=s[k]-48;
				temp1=j+carry;
				ans[++ind]=(temp1%10)+48;
				carry=temp1/10;
			}
		}
		for(i=ind;i>=0;i--)
		putchar(ans[i]);
		putchar('\n');
		
		
	}
	else if(s[i]=='-')
	{
		
		for(k=i+1;k<l;k++)
		{
			j='9'-s[k];
			arr2.push(j);
		
		}
		temp2=arr1.size();
		temp3=arr2.size();
		if(temp3<temp2){
		
		while(temp3--)
		{
			j=arr1.top()+arr2.top()+carry;
			arr1.pop(),arr2.pop();
			ans[++ind]=(j%10)+48;
			carry=j/10;
			temp2--;
			
		}
		while(temp2--)
		{
			j=arr1.top()+9+carry;
			arr1.pop();
			ans[++ind]=(j%10)+48;
			carry=j/10;
		
		}
		
		
		}
		else{
			
			while(temp2--)
		{
			j=arr1.top()+arr2.top()+carry;
			arr1.pop(),arr2.pop();
			ans[++ind]=(j%10)+48;
			carry=j/10;
			temp3--;
			
		}
		while(temp3--)
		{
			j=arr2.top()+carry;
			arr2.pop();
			ans[++ind]=(j%10)+48;
			carry=j/10;
		
		}
		}
		if(carry==0)
		{
			for(i=0;i<=ind;i++)
			ans[i]='9'-ans[i]+48;
			while(ans[ind]=='0')
			ind--;
			ans[++ind]='-';
		}
		else{
			temp3=0;
			while(carry)
			{
				
				temp2=ans[temp3]-48+carry;
				ans[temp3++]=temp2%10+48;
				carry=temp2/10;
			
			}
			temp3--;
			if(temp3>ind)
			ind=temp3;
		}
	
	for(i=ind;i>=0;i--)
		putchar(ans[i]);
		putchar('\n');
	}
	else if(s[i]=='*')
	{

		for(k=l-1;k>i && !arr1.empty();k--)
		{
				
			temp1=arr1.top()*
		
		
		
		
		
		
		
		
		
		
		for(i=ind;i>=0;i--)
		putchar(ans[i]);
		putchar('\n');
	}
	else if(s[i]=='/')
	{
		
		
		
		for(i=ind;i>=0;i--)
		putchar(ans[i]);
		putchar('\n');
	}
	else
	puts("Invalid Operation\n");
	
}
