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

priority_queue<int>buck[10];
priority_queue<pii>ans;
priority_queue<int >ans1;
vector<int>ans2,ans3;
int main()
{
	int t,n,k,i,j,temp1,temp2,temp3,temp4,cnt;
	rd(t);
	bool check,check1;
	while(t--)
	{
		cnt=0;
		rd(n);
		rd(k);
		check=check1=true;
		for(i=0;i<n;i++)
		{
			rd(j);
			temp1=j;
			temp2=0;
			while(true)
			{
			
			while(j)
			{
				temp2+=(j%10);
				j/=10;
			}
			if(temp2<10)
			break;
			else
			j=temp2,temp2=0;
			}	
			
			buck[temp2].push(temp1);
		}
		
		
		for(i=1;i<5;i++)
		{
			temp1=buck[i].size();
			temp2=buck[9-i].size();
			temp1=min(temp1,temp2);
			cnt+=2*temp1;
			for(j=0;j<temp1;j++)
			{
				if(buck[i].top()>=buck[9-i].top())
				ans.push(pii(buck[i].top(),buck[9-i].top()));
				else
				ans.push(pii(buck[9-i].top(),buck[i].top()));
				buck[i].pop(),buck[9-i].pop();	
			}
		
			while(!buck[i].empty())
			buck[i].pop();
			while(!buck[9-i].empty())
			buck[9-i].pop();
		}
		temp1=buck[9].size();
		
		cnt+=temp1;
		for(i=0;i<temp1;i++)
		{
			ans1.push(buck[9].top());
			buck[9].pop();
			
		}
		//cout<<cnt<<endl;
		if(cnt<k)
		pd(-1),pc('\n');
		else
		{
			while(k)
			{
				if(ans.empty())
				check=false;
				if(ans1.empty())
				check1=false;
				if(k>1)
				{
					if(check)
					{
						temp1=ans.top().first;
						if(check1)
						{
							temp2=ans1.top();
							if(temp1>temp2)
							{
							ans2.push_back(ans.top().first);
							ans2.push_back(ans.top().second);
							ans.pop();
							k-=2;
							}
							else
							{
							ans3.push_back(ans1.top());
							ans1.pop();
							k--;
							}
							
						}
						else
						{
							ans2.push_back(ans.top().first);
							ans2.push_back(ans.top().second);
							ans.pop();
							k-=2;
						}
					}
					else
					{
						
						if(check1)
						{
							ans3.push_back(ans1.top());
							ans1.pop();
							k--;
						}	
							
					}	
				}
				else
				{
				
							if(check1)
							{
								ans3.push_back(ans1.top());
								ans1.pop();
								k--;
							}
							
							else
							{
								ans3.pop_back();
								ans2.push_back(ans.top().first);
								ans2.push_back(ans.top().second);
								k--;
								ans.pop();
							}
					
					
				}		
						
			}
			
			
			while(!ans1.empty())
			ans1.pop();
			while(!ans.empty())
			ans.pop();
			temp1=ans2.size();
			for(i=0;i<temp1;i++)
			ans1.push(ans2[i]);
			temp2=ans3.size();
			for(i=0;i<temp2;i++)
			ans1.push(ans3[i]);
			while(!ans1.empty())
			pd(ans1.top()),ans1.pop();
			pc('\n');
			
			
			
		}
		
		
			while(!ans1.empty())
			ans1.pop();
			while(!ans.empty())
			ans.pop();
			ans2.clear();
			ans3.clear();
	}
}
