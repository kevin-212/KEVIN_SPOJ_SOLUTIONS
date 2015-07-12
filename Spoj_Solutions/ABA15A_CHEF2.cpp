/*Problem description.


"You're waiting for a train. A train that will take you far away. You know where you hope this train will take you, but you can't know for sure. Yet it doesn't matter..."


             	-COBB




Ariadne, an architect student,who is now a "dream architect" is in her third level of dream.She needs to think of an array of buildings along both the sides of the road.That is, at the left side of the road there is an array of buildings where each building is adjoined. Similarly,on the right side of the road,there is an array of buildings . Dom Cobb now orders Ariadne that she should think of the largest rectangular hole on both the right and left hand sides and we need to demolish those building parts,to construct a tunnel.Now ,Ariadne had thought of the heights and width of the building in her mind(we take the width of a building to be of unit length, for convenience!!!!).Both the left and right array should be of the same length.(Equal number of buildings on both sides)


Now she needs to calculate the area of the largest rectangular hole for the tunnel that will fit,both the left and right side of the array of buildings.Ariadne searched for the best mind in the town,at last found you.Wow!!!Now you are obliged to help her in finding the area of the largest rectangular hole with a constraint that the right rectangular block should be at the same position as that of the left rectangular block.  
Input

First line contains an integer T, denoting the number of test cases.
Next line contains an integer N, denoting the number of buildings.
It is followed by exactly two lines, each line with the height description of the N buildings.
 
Output

Output a single value denoting the largest area.
Output description.
 
Constraints

First line
1 = T = 1000
1 = N = 1000
 All values fit in the range of a 32-bit integer.
Example

Input:
2
3
1 2 3
1 1 1
4
1 2 3 4
1 2 3 4

Output:
3
6
 
Explanation

Example case 1. In the first test case, a rectangular hole of width 3 and height one will be the largest possible,covering all the buildings...
Example case 2. In the second test case, two possible answers are there... Either the last three buildings of height 2 or the last two buildings of height 3 will be the maximum*/

#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int main(){
int t;
int arr[1001];
int arr1[1001];

cin>>t;
int mx,i,l,j,n,sz;
while(t--)
{
	cin>>n;
	mx=0;
	for(i=0;i<n;i++)
	cin>>arr[i];
	for(i=0;i<n;i++)
	cin>>arr1[i];
	for(i=0;i<n;i++)
	dp[i][i]=min(arr[i],arr1[i]);
	for(l=2;l<=n;l++)
	{
		for(i=0;i<n-l+1;i++)
		{
			j=i+l-1;
			dp[i][j]=min(dp[i][j-1],dp[i+1][j]);
			if(dp[i][j]>=mx)
			{
			mx=dp[i][j];
			sz=l;
			}
			
		}
	}
	cout<<sz*mx<<endl;
}
}

/* Solution 2*/
#include <bits/stdc++.h>
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<n;i++)
#define lli long long int
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define mp make_pair
 
using namespace std;
void sd(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int getMaxArea(int hist[], int n)
{
   
    stack<int> s;
 
    int max_area = 0; 
    int tp;  
    int area_with_top;
 
    
    int i = 0;
    while (i < n)
    {
        
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
 
       
        else
        {
            tp = s.top();  // store the top index
            s.pop();  // pop the top
 
 
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
 
 
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
 
    
    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
 
        if (max_area < area_with_top)
            max_area = area_with_top;
    }
 
    return max_area;
}
 
int main()
{
	int t;
	sd(t);
	int i,n;
	
	while(t--)
	{
		sd(n);
		int arr[n];
		int d;
		fo(i,n)
			sd(arr[i]);
		fo(i,n)
		{
			sd(d);
			arr[i]=min(arr[i],d);
		
		}
		
		//print max area
		printf("%d\n",getMaxArea(arr,n));
		
		
	
	}
	
	return 0;
}

