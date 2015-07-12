#include <stdio.h>
 
void swap (int *a, int i, int j) {
	int temp,k;
	for(k=j;k>i;k--) {
		temp=a[k-1];
		a[k-1]=a[k];
		a[k]=temp;
	}
	return ;
}
 
int main(void) {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		int a[n], b[n],i,j;
		for(i=0;i<n;i++) {
			scanf("%d", &a[i]);
			//printf("%d ", a[i]);
		}
		//printf("\n");
		for(i=0;i<n;i++) {
			scanf("%d", &b[i]);
			//printf("%d ",b[i]);
		}
		//printf("\n");
		long long int count=0;
		for(i=0;i<n;i++) {
			//scanf("%d", &a[i]);
			j=i;
			while(a[j] != b[i] && j<n) {
				j++;
				count++;
			}
			swap(a,i,j);
		}
		printf("%lld\n", count);
	}
	return 0;
}
