#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
#include<map>
#include<stack>
#include<string.h>
#define STOP system("pause")
#define bits(num) __builtin_popcount(num)
#define CASE int t;scanf("%d",&t);while(t--)
#define ll long long int
#define lu unsigned long long
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
using namespace std;
ll a[1805][305][12];
ll MOD=1000000007;
ll solve(int run,int ball,int wic)
{
	if(a[run][ball][wic]!=-1)
	{
		return a[run][ball][wic];		
	}
	else
	{
		ll temp=0;
		if(run==0&&wic==0)
		return 1;
		if(ball==0||wic>ball||run>6*ball)
		{
			return 0;
		}
		else
		{
			
			if(run>=4)
			temp=solve(run-4,ball-1,wic);
			temp%=MOD;
			if(wic>0)
			temp+=solve(run,ball-1,wic-1);
			temp%=MOD;
			if(run>=6)
			temp+=solve(run-6,ball-1,wic);
			temp%=MOD;
			temp+=solve(run,ball-1,wic);
			temp%=MOD;
		}
		return temp;
	}
}
int main()
{
	int i,j,k;
	for(i=0;i<=1800;i++)
	for(j=0;j<=300;j++)
	for(k=0;k<=9;k++)
	a[i][j][k]=-1;
	for(i=0;i<=1800;i++)
	{
		for(j=0;j<=300;j++)
		{
			for(k=0;k<=9;k++)
			{
				if(j*6<i||k>j)
				{
					a[i][j][k]=0;
				}
				else
				{
					a[i][j][k]=solve(i,j,k);
				}
			}
		}
	}
	CASE
	{
		ll sum=0,run,ball,wic;
		cin>>run>>ball>>wic;
		if(run>1800)
		{
			printf("0\n");
			continue;
		}
		for(i=0;i<=wic;i++)
		{
			sum+=a[run][ball][i];
			sum%=MOD;
		}
		cout<<sum<<endl;
	}
    return 0;
}
