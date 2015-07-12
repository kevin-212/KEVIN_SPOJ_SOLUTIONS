#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	int t,i,j,k,h;

	char arr[8][8];
	bool check;
	
	
	
	
		check=true;
		for(i=0;i<8;i++)
		for(j=0;j<8;j++)
		cin>>arr[i][j];
		for(i=0;i<8 && check;i++)
		{
			for(j=0;j<8 && check;j++)
			{
				if(arr[i][j]=='*')
				{
					k=i-1;
					while(k>=0)
					{
						if(arr[k--][j]=='*')
						{
							check=false;
							break;
						}
					}
					k=j-1;
					while(check && k>=0)
					{
						if(arr[i][k--]=='*')
						{
							check=false;
							break;
						}
					}
					k=i-1,h=j-1;
					while(check && k>=0 && h>=0)
					{
						if(arr[k--][h--]=='*')
						{
							check=false;
							break;
						}
					}
					k=i+1,h=j-1;
					while(check && k<8 && h>=0)
					{
						if(arr[k++][h--]=='*')
						{
							check=false;
							break;
						}
					}
				}
			}
		}
		if(check)
		cout<<"valid"<<endl;
		else
		cout<<"invalid"<<endl;
	
}
