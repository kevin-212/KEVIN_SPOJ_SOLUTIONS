/*
One day Abhinav was teaching little Shark about data structures and algorithms related to trees. He told that given a rooted tree T containing N nodes, numbered from 1 to N, rooted at node 1. Pre-order array of the tree can be obtained by doing pre-order depth first search on the tree, starting from node 1 and recursively visiting the subtrees rooted at the children of the root. For example, given a tree containing 5 nodes and following pair of nodes are connected via direct edge -
1 2
1 3
2 4
2 5
then pre order array can be - 1 2 4 5 3.
Clearly there are many possible pre-order array for a given tree. e.g, (1 3 2 5 4) is also a valid pre order array for the given tree. Then Abhinav told little Shark that all the nodes in the subtree rooted at a node, say nd appears consecutively in the pre-order array ! For example, nodes in the subtree rooted at nd = 2 in the given example are 2, 4 and 5. Clearly these numbers appears consecutively in the pre-order array starting at index 2 (1 based index). This is true for any pre-order array for the tree. You may verify that.
Little Shark got the point Abhinav was trying to make. But after pondering over the concept for some time he asked Abhinav can we recover the tree if pre-order array is given !
 
In this problem you will be given pre-order array of a tree and some clues about some of the subtrees of the tree. You need to find a tree satisfying the given clues and has at least one pre-order traversal as given in the input.
Clues will be given in the from three integers nd, l and r . Denoting that nodes of the subtree rooted at node nd lies consecutively in the given pre-order array from index l to r. Can you find the tree ?
Input

The first line of the input contains a single integer N denoting the size of the tree (size of the pre-order array). The second line contains N space-separated integers denoting the elements of the pre-order array.
Next line contains an integer Q denoting the number of clues given.
Next Q lines each contains three space separated integers denoting nd, l and r respectively as described in the problem statement.
Output

First line of the output should contain an integer f. If there is no such tree satisfying all the clues, then f should be equal to 0. Otherwise it should be equal to 1.
If f = 1 then in next N-1 lines print the edges of the tree. Each line should contain two integers u and v denoting there is direct edge between node u and node v in the tree. Output must satisfy a valid tree structure.
Constraints

1 = N = 100000
1 = Q = 100000
1 = nd = N
1 = l = r = N
Elements of the preorder array will be between 1 and N (both inclusive).
 
Example

Input:
4
1 2 3 4
4
1 1 4
2 2 4
3 3 4
4 4 4

Output:
1
1 2
2 3
3 4
*/

using namespace std;
 
typedef pair<int, int> pii;
typedef long long int LL;
typedef vector<int> VI;
 
#define sd(x) scanf("%d", &x)
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define INF 2000000000
#define MOD 1000000007
#define D double
#define LD long double
 
#define N 1123456
 
bool flag = false;
int lf[N], rg[N], par[N], a[N];
 
inline void go(int l, int r, int p){
	if(l > r){
		return;
	}
	//cout<<l<<" "<<r<<" "<<p<<endl;
	par[a[l]] = p;
	if(lf[a[l]] != -1){
		if(lf[a[l]] > l || rg[a[l]] > r){
			flag = true;
			return;
		}
		go(l + 1, rg[a[l]], a[l]);
		if(flag == true){
			return;
		}
		go(rg[a[l]] + 1, r, p);
	}
	else{
		go(l + 1, r, p);
	}
}
 
int main(){
	int n, i, q, l, r;
	sd(n);
	for(i = 1; i <= n; i++){
		sd(a[i]);
		lf[i] = -1;
		rg[i] = -1;
	}
	if(a[1] != 1){
		printf("0\n");
		return 0;
	}
	sd(q);
	while(q--){
		sd(i); sd(l); sd(r);
		if(lf[i] != -1){
			if(lf[i] != l || rg[i] != r){
				cout<<"0"<<endl;
				return 0;
			}
			continue;
		}
		lf[i] = l;
		rg[i] = r;
	}
	if(lf[1] != -1){
		if(lf[1] != 1 || rg[1] != n){
			cout<<"0"<<endl;
			return 0;
		}
	}
	else{
		lf[1] = 1;
		rg[1] = n;
	}
	go(1, n, 0);
	if(flag == true){
		cout<<"0"<<endl;
	}
	else{
		cout<<1<<endl;
		for(i = 2; i <= n; i++){
			printf("%d %d\n", i, par[i]);
		}
	}
	return 0;
}
