#include<bits/stdc++.h>
using namespace std;


struct tree_node{
	tree_node*child[3];
	int val;	
};
struct tree{
	tree_node*root;
	
};

tree_node* getnode()
{
	tree_node*node=new tree_node;
	for(int i=0;i<3;i++)
	node->child[i]=NULL;
	node->val=0;
	return node;
}
tree* gettree()
{
	tree*trie=new tree;
	trie->root=getnode();
	return trie;
}


void insert(tree*trie,char*str,int len)
{
	tree_node*pcrawl=trie->root;
	int i;
	int v;
	for(i=0;i<len;i++)
	{
		v=str[i]-'a';
		if(pcrawl->child[v]==NULL)
		pcrawl->child[v]=getnode();
		
		pcrawl=pcrawl->child[v];
	}
	pcrawl->val++;
}

bool check(tree_node*trie,char*str,int start,int count)
{
	int v;
	 
	int len=strlen(str);
	tree_node *pcrawl=trie;
	bool check1,check2;
	for(int i=start;i<len;i++)
	{
		v=str[i]-'a';
		if(pcrawl->child[v]==NULL)
		{
		
		count++;
		if(count>1)
		return false;
			if(v==0)
			{
				if(pcrawl->child[1]!=NULL)
				check1 = check(pcrawl->child[1],str,i+1,1);		
				if(pcrawl->child[2]!=NULL)
				 check2 =check(pcrawl->child[2],str,i+1,1);
				return check1 | check2;		
			}
			else if(v==1)
			{
				if(pcrawl->child[0]!=NULL)
				 check1= check(pcrawl->child[0],str,i+1,1);		
				if(pcrawl->child[2]!=NULL)
				check2=check(pcrawl->child[2],str,i+1,1);
				return check1|check2;		
			}
			else
			{
				if(pcrawl->child[1]!=NULL)
				check1= check(pcrawl->child[1],str,i+1,1);		
				if(pcrawl->child[0]!=NULL)
				 check2=check(pcrawl->child[1],str,i+1,1);
				return check1|check2;		
			}
		
		}
		pcrawl=pcrawl->child[v];
	}
	if(pcrawl->val>0)
	return true;
	else
	return false;
	
}
int main()
{
	int n,m,i,len,j,k,sz;
	cin>>n>>m;
	tree*trie=gettree();
	char str[600001];
	char c;
	
	for(i=0;i<n;i++)
	{
		cin>>str;
		
		len=strlen(str);
		insert(trie,str,len);
		
	}
	
	for(i=0;i<m;i++)
	{
		cin>>str;
		len=strlen(str);
		if(check(trie->root,str,0,0))
		cout<<"YES"<<endl;	
		else
		cout<<"NO"<<endl;
	
	
			
	}
	}

