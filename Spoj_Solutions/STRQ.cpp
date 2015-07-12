#include<bits/stdc++.h>
using namespace std;

struct node{
	long long int arr1[6][6];
	int cn[6];	
	
};
node arr[1000000];
int main()
{
	int q,len,l,r,i,j,k;
	long long int count;
	char str[1000001],a,b,c;
	scanf("%s",str);
	len=strlen(str);
	
	int ch[6]={0,0,0,0,0,0};
	
	
	
	for(i=0;i<6;i++)
	{
	for(j=0;j<6;j++)
	arr[0].arr1[i][j]=0;
	arr[0].cn[i]=0;
	}
	ch[str[0]-'c']++;
	arr[0].cn[str[0]-'c']++;
	for(i=1;i<len;i++)
	{
		for(j=0;j<6;j++)
		for(k=0;k<6;k++)
			arr[i].arr1[j][k]=arr[i-1].arr1[j][k];
			
			for(j=0;j<6;j++)
			{
				arr[i].arr1[j][str[i]-'c']+=ch[j];
				arr[i].cn[j]=ch[j];
			}
			ch[str[i]-'c']++;
			arr[i].cn[str[i]-'c']++;
	}
	scanf("%d",&q);
	scanf("%c",&c);
	
	
	
	while(q--)
	{
		scanf("%c %c %d %d",&a,&b,&l,&r);
		scanf("%c",&c);
		a-='c';
		b-='c';
		l--,r--;
		if(l!=0)
		count=(arr[r].arr1[a][b]-arr[l-1].arr1[a][b])-(1LL*((arr[r].cn[b]-arr[l-1].cn[b])*arr[l-1].cn[a]));
		else
		count=arr[r].arr1[a][b];

		printf("%lld\n",count);
	}
}
