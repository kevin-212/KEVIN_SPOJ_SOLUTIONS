#include<iostream>
using namespace std;
int main()
{
	int t,i;
	cin>>t;
	while(t--)
	{
		int n,w,q;
		cin>>n>>w;		
		int a[n+1];
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			//cout<<a[i];		
		}
		int total=0;
		int colour=a[1];
		int count=1;
		for(i=2;i<=n;i++)
		{
			if(a[i]==colour)			
				count++;
			else
			{
				if(count>=w)
				{total+=count-w+1;
				}
				count=1;
				colour=a[i];			
			}
		}
		if(count>=w)
		{
			total+=count-w+1;
		}			
				
 
		//cout<<total;		
		cin>>q;
		int x;
		int pos,value,count1,count2,j;
		for(x=0;x<q;x++)
		{
			cin>>pos>>value;
			int tempcol=a[pos];
			count=0;i=pos-1;j=pos+1;			
			if(a[pos]==value)
			{
				cout<<total<<"\n";continue;
			}
			else{
				while(a[i]==tempcol && i>0 )				
					{count++;i--;}
				count1=0;		
				while(a[j]==tempcol && j<=n )				
					{count1++;j++;}
				count2=count+count1+1;			
				if(count2>=w)
				{	
					total-=count2-w+1;
				}	
				if(count1>=w)
					total+=count1-w+1;
				if(count>=w)
					total+=count-w+1;
	
				count=0;i=pos-1;j=pos+1;				
				while(a[i]==value && i>0 )				
					{count++;i--;}
				count1=0;		
				while(a[j]==value && j<=n )				
					{count1++;j++;}
				count2=count+count1+1;			
				if(count2>=w)
				{	
					total+=count2-w+1;
				}	
				if(count1>=w)
					total-=count1-w+1;
				if(count>=w)
					total-=count-w+1;
			   }
			a[pos]=value;		
			cout<<total<<"\n";		
		}
	}
return 0;
}
