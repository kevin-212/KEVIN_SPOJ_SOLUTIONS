/*
Problem Statement

Given a list containing N integers, calculate the XOR_SUM of all the non-empty subsets of the list and print the value of sum % (109 + 7).

XOR operation on a list (or a subset of the list) is defined as the XOR of all the elements present in it. 
E.g. XOR of list containing elements {A,B,C} = ((A^B)^C), where ^ represents XOR.

E.g. XOR_SUM of list A having three elements {X1, X2, X3} can be given as follows.
All non-empty subsets will be {X1, X2, X3, (X1,X2), (X2,X3), (X1,X3), (X1,X2,X3)}

XOR_SUM(A) = X1 + X2 + X3 + X1^X2 + X2^X3 + X1^X3 + ((X1^X2)^X3)

Input Format 
An integer T, denoting the number of testcases. 2T lines follow.
Each testcase contains two lines, first line will contains an integer N followed by second line containing N integers separated by a single space.

Output Format 
T lines, ith line containing the output of the ith testcase.

Constraints 
1 <= T <= 5
1 <= N <= 105
0 <= A[i] <= 109
*/

#include<bits/stdc++.h>
using namespace std;
#define cin(n) scanf("%d",&n)
#define rep(i,n) for(i=0;i<n;i++)
#define mod 1000000007
int arr[100000];
int func(int st,int n,int xorsum)
{
	if(st==n)
	return 0;
	int ans=0;
	int temp;
	for(int i=st;i<n;i++)
	{
		temp=(xorsum^arr[i])%mod;
		ans=(ans+temp+func(i+1,n,temp))%mod;
	}
	return ans%mod;
}
int main()
{
	int t,n,i,j,k;
	
	cin(t);
	while(t--)
	{
	
	cin(n);
	rep(i,n)
	{
		cin(arr[i]);
		
	}
	int ans;
	ans=func(0,n,0);
	printf("%d\n",ans);
	
	}
}

/*SOLUTION
Solution: Find OR of all the elements and multiply it with 2^(n-1) where n is the total number of elements. This gives us the answer.
Idea:
There will be total 2^n subsets.
If ith bit of any element is set, then that bit will be set in xor of half of the total subsets which is 2^(n-1).
To find out all the set bits in all the numbers we find OR of all the numbers.
Since each set bit appears in half of the total subsets we multiply OR of all numbers with 2^n-1 to get the final result.
*/
