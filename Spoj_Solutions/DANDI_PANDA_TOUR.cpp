/*Panda loves taking people to programming tour. He loves to take tourists from one camp to another and teach them different algorithms.
 Some two-way roads connect the cities. For each pair of neighboring camps there is a bus service that runs only between those two cities and uses
  the road that directly connects them. Each bus service has a limit on the maximum number of passengers it can carry. 
  Panda has a map showing the cities and the roads connecting them. He also has the information regarding each bus service. He understands that it may not 
  always be possible for him to take all the tourists to the destination city in a single trip. It is guaranteed that you can reach any city from any other.
  

Help Panda find the minimum number of trips to take all his tourists to the destination city in the minimum number of trips.

Input Format:
The first line will contain two integers: N and M, representing respectively the number of cities and the number of road segments. 
Then next M lines will each contain three integers: C1, C2 and P. C1, C2 are the city numbers, and P is the limit on the maximum number of passengers to be
 carried by the bus service between the two cities.
The next line will contain Q the number of queries.
Each query consists of three integers: S, D and T representing respectively the starting city, the destination city and the number of tourists to be guided.

Output Format:
For each query, output the minimum number of trips that will be required by Panda to take tourists from one camp to another. 
If the Panda is unable to take tourists from one camp to another, output "-1" (without quotes).

Constraints:
2 <= N, Q <= 105
0 <= M <= 3*105 
1 <= C1, C2 <= N
1 <= P <= 107 
1 <= S, D <= N
0 <= T <= 109

Subtask 1:
2 <= N <= 5, Q = 100 - 5 points

Subtask 2:
Original constraints - 95 points

enter image description here

Sample Input (Plaintext Link)
7 10
1 2 30
1 3 15
1 4 10
2 4 25
2 5 60
3 4 40
3 6 20
4 7 35
5 7 20
6 7 30
1
1 7 94
Sample Output (Plaintext Link)
4
Explanation
The best path is 1-2-4-7. Panda can take all the passengers along with him from camp 1 to camp 7 in 4 trips.
Time Limit: 5 sec(s) for each input file.
*/

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define INF 1000000000

using namespace std;
typedef long long LL;
typedef vector<LL> VI;
typedef vector< vector<LL> > VVI;
typedef pair< LL, LL > PII;

const int N=100010;
LL n;
vector< pair<LL,PII> > edge;
VI G[N],W[N];
LL D[N],P[N],DP[N][20],MN[N][20],Par[N];

int par(int u) { if(Par[u]==u) return u; return Par[u] = par(Par[u]); }
void join(int u, int v) { u = par(u); v = par(v); if(u!=v) Par[u] = v;}

void dfs(int u, int p=0, LL e=INF, int dep=0)
{
	P[u] = p;
	MN[u][0] = e;
	D[u] = dep;
	for(int i=0; i<G[u].size(); i++)
		if(G[u][i]!=p)
			dfs(G[u][i],u,W[u][i],dep+1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin>>n>>m;
	for(int i=0; i<m; i++)
	{
		LL x,y,w;
		cin>>x>>y>>w; x--; y--;
		edge.pb(mp(w,mp(x,y)));
	}
	sort(edge.rbegin(),edge.rend());
	for(int i=0; i<n; i++) Par[i] = i;
	for(int i=0; i<m; i++)
	{
		LL x,y,w;
		x = edge[i].ss.ff; y = edge[i].ss.ss; w = edge[i].ff;
		if(par(x)==par(y)) continue;
		join(x,y);
		G[x].pb(y); G[y].pb(x);
		W[x].pb(w); W[y].pb(w);
	}
	dfs(0);
	for(int i=0; i<n; i++) DP[i][0] = P[i];
	for(int j=1; j<20; j++)
		for(int i=0; i<n; i++)
		{
			DP[i][j] = DP[DP[i][j-1]][j-1];
			MN[i][j] = min(MN[i][j-1],MN[DP[i][j-1]][j-1]);
		}
	int q;
	cin>>q;
	while(q--)
	{
		int s,d,t,lca,x,y;
		cin>>s>>d>>t; s--; d--;
		if(s==d || t==0) {cout<<"0\n"; continue;}
		if(D[s] < D[d]) swap(s,d); x=s; y=d;
		int diff=D[s]-D[d];
		for(int i=19; i>=0; i--)
			if(diff&(1<<i))
				s = DP[s][i];
		if(s==d) lca=s;
		else
		{
			int log=0; while(DP[s][log] != DP[d][log]) log++; log--;
			for(int i=log; i>=0; i--)
				if(DP[s][i]!=DP[d][i])
					s = DP[s][i], d = DP[d][i];
			lca = P[s];
		}
		LL mn=INF; s = x;
		d=D[x]-D[lca];
		for(int i=19; i>=0; i--)
			if(d&(1<<i))
			{
				mn = min(mn,MN[s][i]);
				s = DP[s][i];
			}
		s = y;
		d=D[y]-D[lca];
		for(int i=19; i>=0; i--)
			if(d&(1<<i))
			{
				mn = min(mn,MN[s][i]);
				s = DP[s][i];
			}
		mn--;
		if(mn==0)
		{
			cout<<"-1\n";
			continue;
		}
		LL ans = (t+mn-1)/mn;
		cout<<ans<<"\n";
	}

	return 0;
}

