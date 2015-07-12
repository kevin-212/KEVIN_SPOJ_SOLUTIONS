#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
 
int main() {
 
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,i,min,max,j,count;
    scanf("%d",&N);
    int a[N];
    for(i=0;i<N;i++)
        scanf("%d",&a[i]);
    printf("%d\n",N);
    count=0;
    max=0;
    for(i=0;i<N;i++){
        if(a[i]>max){
            max=a[i];
            j=i;
        }
    }
   while(a[j]!=0){
      min=1001;
    for(i=0;i<N;i++){
        if(a[i]>0 && a[i]<min){
            min=a[i];
        }
    }
    count=0;
    for(i=0;i<N;i++){
        a[i]=a[i]-min;
        if(a[i]>0){
            count++;
        }
    }
    if(count!=0)
      printf("%d\n",count);
   }
    return 0;
}
