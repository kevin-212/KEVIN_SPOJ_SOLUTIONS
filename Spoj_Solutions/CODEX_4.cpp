  #include<bits/stdc++.h>
    using namespace std;
     
     
    int main()
    {
    	int t;
    	cin>>t;
    	while(t--)
    	{
    		string x,y;
    		cin>>x;
    		cin>>y;
    		int ct=0;
    		int maxi=INT_MAX;
    		if(x.size()==y.size())
    		{
    			for(int i=0;i<x.size();i++)
    			{
    				if(x[i]!=y[i])
    				ct++;
    			}
    			maxi=ct;
    		}
    		else
    		{
    			if(x.size()>y.size())
    			{
    				string temp=x;
    				x=y;
    				y=temp;
     
    			}
    			for(int i=0;i<=(y.size()-x.size());i++)
    			{
    			    ct=0;
    				for(int j=0;j<x.size();j++)
    				{
    					if(x[j]!=y[j+i])//similar to pattern mating naive approach
    					++ct;
    				}
    				if(ct<maxi)
    				maxi=ct;
    			}
    		}
    		cout<<maxi<<endl;
    	}
        //cout << "Hello World!" << endl;
        return 0;
    } 
