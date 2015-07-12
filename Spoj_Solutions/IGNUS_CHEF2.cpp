/*
You are an army personnel in the great army of the Zorin race, where you are a part of a team of n people.

Unfortunately, your army has lost a war to an intergalactic species, genetically much advanced than yours.

Their captain Bruno have kept all your men (including you) as hostages, and now they are trying to have some fun.

He asks each of the n people to choose any integer from 1 to n that is not taken by someone else. i.e. no two persons can have the same chosen number. Then he arranges all the n people in a circle sequentially
and starts with person number 1.
He leaves 1, shoots 2, leaves 3, shoots 4 .... and goes on shooting people alternately until only one person remains.
He then offers the lucky man to restart his own kingdom and grants him all his looted resources.
It is you who is asked first to choose your number k. What will you choose as your lucky number?
Input

First line contains T, the number of test cases.
Each test case has the number n in a single line, denoting the number of people captured by Captain Bruno.
 
Output

For each test case, print the value of k in a single line.
 
Constraints

1 = T = 100000
1 = n = 1000000000000000000
 
Example

Input:
6
6
125
32
46
98
156


Output:
5
123
1
29
69
57
 
Explanation

Case 1: n = 6. In the first round 2, 4, 6 are killed, 1, 3, 5 remain. In next round 3 is killed. Then 1 is killed,
therefore leaving 5. So answer = 5.*/

#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define pc putchar_unlocked
typedef long long int lld;
typedef unsigned long long llu;
typedef long int ld;
#define pb push_back
 
int  comp(const void *a,const void *b)
{ 
     return *(int*)a-*(int*)b;
}
 
void si(llu &x)
{  x=0;
     char c=gc();
     int neg=0;
 
     while((c<'0'|| c>'9') && c!='-')
          c=gc();
 
     if(c=='-') {neg=1; c=gc();}
     for(;c>='0' && c<='9';c=gc())
     { 
          x=x*10+c-48;            
     }
 
     if(neg==1)
          x=-x;
}
 
 
inline void pi(int n)
{
     int i=0;
     char ch[20];
     if(n<0)
          if(n==0) pc('0');
          else
               pc('-'),n=n*(-1);
 
     while(n>0)
     {  ch[i]=n%10 +'0';
          n=n/10;
          i++;
     }
 
     while(i>0)
     { 
          pc(ch[i-1]);
          i--;
     }
     pc(' ');
}
 
inline void ss(char *s)
{
     char ch;
     ch=gc();
     int i=0;
     while((ch>=32)&&(ch<=110))
     {
          s[i++]=ch;
          ch=gc();
     }
 
     s[i]='\0';
}
 
inline void ps(char *s)
{
     int i=0;
     while(s[i]>=32 && s[i]<=127)
     {
          pc(s[i]);
          i++;
     }
     pc('\n');
}
llu nextpow(llu v)
{
     v--;
     v |= v >> 1;
     v |= v >> 2;
     v |= v >> 4;
     v |= v >> 8;
     v |= v >> 16;
     v++;
 
     return v/2;
 
}
 
int main(){
     llu test,i1,i,n,v,r;
     si(test);
 
     for(i=0;i<test;i++)
     {
          si(n);
 
          if(n==1)
               printf("1\n");
          else{
          v=n;
          v=nextpow(v);
                                       //  printf("powof2=%llu\n",v);
          if(2*v==n)
               printf("1\n");
          else
          {
               r=n-v;
 
               printf("%lld\n",n-(v-1-r));
          }
     }
     }
 
     return 0;
}
 

