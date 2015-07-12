/*
N teams are playing in this cricket world cup, numbered from 1 .. N. Each team plays every other team exactly once in the World Cup. No match ever results in a draw. Team x is said to directly win over team y if in the match between x and y, x wins. Team x is said to indirectly win over y if there exists a sequence of teams a1, a2, ...., ak where a1 = x, ak = y, k >= 2 and for each 1 = i = k - 1, ai defeats ai + 1. 
Team x is said to completely win over team y if x indirectly defeats y and y does not indirectly defeat x.
The organisers of the world cup wants to make the world cup weird. World Cup will be weird if no team completely wins over another team. For making the cup weird he is ready to change the result of some matches so that the world cup becomes weird. Your task is to help him accomplish this by changing the result of minimum number of matches.
Input

First line contains N, the number of teams in the world cup. N * (N - 1) / 2 lines follow, each containing a pair i j meaning team i defeated team j in their match
 
Output

If it is not possible to make the world cup weird by changing some results, print -1.
If it is possible, print the smallest number of matches changing whose result will make the world cup weird. Then print each match (represented by the pair of team number) in a new line. If there are multiple answers possible, print any one of them. Pair u v and v u are the same.
 
Constraints

4 = N = 10^3
Each pair i j appears exactly once in the input
 
Example

Input:
4
1 2
1 3
4 1
2 3
4 2
4 3

Output:
1
3 4*/



#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
#include <stdlib.h>
#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <limits.h>
#define llu long long unsigned
#define ld long
#define F first
#define S second
#define ll long long
using namespace std;
int scan_d()    {int ip=getchar_unlocked(),ret=0,flag=1;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
ld scan_ld()    {int ip=getchar_unlocked(),flag=1;ld ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
ll scan_ll()    {int ip=getchar_unlocked(),flag=1;ll ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
llu scan_llu()    {int ip=getchar_unlocked();llu ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked());for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return ret;}
void print_d(int n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=10;char output_buffer[10];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<10);}
void print_ld(ld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=11;char output_buffer[11];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<11);}
void print_ll(ll n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<21);}
void print_llu(llu n)     {int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<21);}
 
stack<int>st,st2;
int visited[2000],pa[2000],n,value[2000],arr[2000][2000];
std::vector<int> v[2000],v_rev[2000],graph[2000];
void dfsst(int curr)
{
	if(visited[curr]==1) return;
	visited[curr]=1;
	for(int i=0;i<v[curr].size();i++)
	{
		if(visited[v[curr][i]]!=1) dfsst(v[curr][i]);
	}
	st.push(curr);
}
void dfs(int curr,int par)
{
	if(visited[curr]==1) return;
	visited[curr]=1;
	for(int i=0;i<v_rev[curr].size();i++)
	{
		if(visited[v_rev[curr][i]]!=1) dfs(v_rev[curr][i],par);
	}
	pa[curr]=par;
}
void dfstopo(int curr)
{
	if(visited[curr]==1) return;
	visited[curr]=1;
	for(int i=0;i<graph[curr].size();i++)
	{
		if(visited[graph[curr][i]]!=1) dfstopo(graph[curr][i]);
	}
	st2.push(curr);
}
int main()
{
	int i,j,temp1,temp2,rank,head;
	n=scan_d();
	int edges=n*(n-1);
	edges/=2;
	for(i=0;i<edges;i++)
	{
		temp1=scan_d();temp2=scan_d();
		v[temp1].push_back(temp2);
		v_rev[temp2].push_back(temp1);
	}
	// for(i=1;i<=n;i++){
	// 	for(j=0;j<v[i].size();j++) printf("%d ", v[i][j]);
	// 	printf("\n");
	// }
	memset(visited,0,sizeof(visited));
	for(i=1;i<=n;i++)
	{
		if(visited[i]==0)
		{
			// printf("i=%d\n", i);
			dfsst(i);
		}
	}
	memset(visited,0,sizeof(visited));
	rank=1;
	while(!st.empty())
	{
		i=st.top();st.pop();
		if(visited[i]==0)
		{
			// printf("i=%d\n", i);
			value[rank]=i;
			dfs(i,rank++);
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<v[i].size();j++)
		{
			if( (pa[v[i][j]]!=pa[i]) && (arr[pa[i]][pa[v[i][j]]]==0) )
			{
				arr[pa[i]][pa[v[i][j]]]=1;
				graph[pa[i]].push_back(pa[v[i][j]]);
			}
		}
	}
	memset(visited,0,sizeof(visited));
	if(rank==2) printf("0\n");
	else{
	for(i=1;i<rank;i++)
	{
		dfstopo(i);
	}
	head=st2.top();
	st2.pop();
	while(!st2.empty())
	{
		temp1=st2.top();st2.pop();
	}
	printf("1\n"); 
	printf("%d %d\n",value[temp1],value[head]);
	}
	return 0;
 
}
