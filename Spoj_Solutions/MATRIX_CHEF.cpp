#include <bits/stdc++.h>
using namespace std;
 
#define MP make_pair
#define PB push_back
 
#define gc getchar//_unlocked
template <typename T>
inline void input(T &n )
{
	register T ch=gc(); T sign=1; n=0;
	while(ch<'0' || ch>'9') { if(ch=='-') sign=-1; ch=gc();}
	while(ch>='0' && ch<='9') n=(n<<3)+(n<<1)+ch-'0',ch=gc();
	n=n*sign;
}
 
typedef long long ll;
 
/*-----------------------------------------------------------*/
 
int test,V,SEG,N,M;
 
#define MAX 1005
 
int MATRIX[MAX][MAX];
int visited[MAX][MAX];
int visited1[MAX][MAX];
 
struct path
{
	int L,R,U,D;
 
}   path[MAX][MAX];
 
void init(int test)
{
	for(int i=1;i<=M;i++)
		path[1][i].U=test,path[N][i].D=test;
 
	for(int i=1;i<=N;i++)
		path[i][1].L=test,path[i][M].R=test;
}
 
void clear(int MAT[][MAX])
{
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		MAT[i][j]=1;
	}
}
 
ll ARR[1000005];
 
int BFS(int X,int Y,int W,int Z)
{
 	visited[X][Y]=V;
 	visited1[W][Z]=V;
 
	queue<pair<int,int> > Q1,Q2;
 
	Q1.push(MP(X,Y));
	Q2.push(MP(W,Z));
 
	while(1)
	{
		if(Q1.empty())
		return 2;
 
		if(Q2.empty())
		return 3;
 
		pair<int,int> idx1=Q1.front();
		pair<int,int> idx2=Q2.front();
 
		int i=idx1.first; int j=idx1.second;
		int i1=idx2.first; int j1=idx2.second;
 
		Q1.pop(); Q2.pop();
		
		if(visited[i1][j1]==V || visited1[i][j]==V)
		return true;
 
		if(path[i][j].D!=test && visited[i+1][j]!=V)
		{
			Q1.push(MP(i+1,j));
			visited[i+1][j]=V;
		}
		if(path[i][j].R!=test && visited[i][j+1]!=V)
		{
			Q1.push(MP(i,j+1));
			visited[i][j+1]=V;
		}
		if(path[i][j].U!=test && visited[i-1][j]!=V)
		{
			Q1.push(MP(i-1,j));
			visited[i-1][j]=V;
		}
		if(path[i][j].L!=test && visited[i][j-1]!=V)
		{
			Q1.push(MP(i,j-1));
			visited[i][j-1]=V;
		}
 
		if(path[i1][j1].D!=test && visited1[i1+1][j1]!=V)
		{
			Q2.push(MP(i1+1,j1));
			visited1[i1+1][j1]=V;
		}
		if(path[i1][j1].R!=test && visited1[i1][j1+1]!=V)
		{
			Q2.push(MP(i1,j1+1));
			visited1[i1][j1+1]=V;
		}
		if(path[i1][j1].U!=test && visited1[i1-1][j1]!=V)
		{
			Q2.push(MP(i1-1,j1));
			visited1[i1-1][j1]=V;
		}
		if(path[i1][j1].L!=test && visited1[i1][j1-1]!=V)
		{
			Q2.push(MP(i1,j1-1));
			visited1[i1][j1-1]=V;
		}
	}
}
 
ll BFS1(int L,int R,int SEG)
{
	int count=0;
 
 	visited[L][R]=V;
 
	queue<pair<int,int> > q;
 
	q.push(MP(L,R));
 
	while(!q.empty())
	{
		pair<int,int> idx=q.front();
		count++;
 
		int i=idx.first;
		int j=idx.second;
 
		q.pop();
 
		MATRIX[i][j]=SEG;
 
		if(path[i][j].D!=test && visited[i+1][j]!=V)
		{
			q.push(MP(i+1,j));
			visited[i+1][j]=V;
		}
		if(path[i][j].R!=test && visited[i][j+1]!=V)
		{
			q.push(MP(i,j+1));
			visited[i][j+1]=V;
		}
		if(path[i][j].U!=test && visited[i-1][j]!=V)
		{
			q.push(MP(i-1,j));
			visited[i-1][j]=V;
		}
		if(path[i][j].L!=test && visited[i][j-1]!=V)
		{
			q.push(MP(i,j-1));
			visited[i][j-1]=V;
		}
	}
	return count;
}
 
void testing()
{
		for(int i=1;i<=SEG;i++)
		cout<<ARR[i]<<endl;
 
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=M;j++)
			cout<<MATRIX[i][j]<<" ";
 
			cout<<endl;
		}
}
 
int main()
{
	#if _WIN32
	freopen("input.txt","r",stdin);
	#endif
 
	int T,Q,TYPE,X,Y,W,Z;
 
	ll ANS,val;
 
	input(T);
 
	for(test=1; test<=T ; test++)
	{
		multiset<int> MS;
  		multiset<int> :: reverse_iterator it;
 
		input(N);input(M);input(Q);
 
		clear(MATRIX);
		init(test);
		
 
		ANS=0; SEG=1; ARR[1]=N*M;
		MS.insert(ARR[1]);
 
		while(Q--)
		{
			input(TYPE);
 
			if(TYPE==1)
			{
				input(X);input(Y);
 
				if(path[X][Y].R!=test)
				{
					path[X][Y].R=test,path[X][Y+1].L=test;
 
					V++;
					int temp=BFS(X,Y,X,Y+1);
					
					if(temp!=1)
					{
						int t=MATRIX[X][Y];
						MS.erase(MS.find(ARR[t]));
						
						if(temp==2)
						{
	  						V++; SEG++; val=BFS1(X,Y,SEG);
						}
						else
						{
	  						V++; SEG++; val=BFS1(X,Y+1,SEG);
						}
						ARR[SEG]=val;
						ARR[t]-=val;
 
						MS.insert(ARR[SEG]);
						MS.insert(ARR[t]);
	 				}
				}
			}
			else if(TYPE==2)
			{
				input(X);input(Y);
 
				if(path[X][Y].D!=test)
				{
					path[X][Y].D=test,path[X+1][Y].U=test;
 
	 				V++;
	 				int temp=BFS(X,Y,X+1,Y);
	 				
					if(temp!=1)
					{
						int t=MATRIX[X][Y];
						MS.erase(MS.find(ARR[t]));
							
						if(temp==2)
						{
							V++; SEG++; val=BFS1(X,Y,SEG);
						}
						else
						{
							V++; SEG++; val=BFS1(X+1,Y,SEG);
						}
						
						ARR[SEG]=val;
	  					ARR[t]-=val;
 
	  					MS.insert(ARR[SEG]);
						MS.insert(ARR[t]);
					}
				}
			}
			else if(TYPE==3)
			{
				input(X);input(Y);input(W);input(Z);
 
   				if(MATRIX[X][Y]==MATRIX[W][Z])
				ANS++;
			}
			else
			{
				it=MS.rbegin();
				ANS+=*it;
			}
		}
		printf("%lld\n",ANS);
 
		//testing();
	}
