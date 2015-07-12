#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
using namespace std;


struct tree_node{
	int value;
	tree_node*child[26];
};

struct trie{
	
	tree_node*root;
};

struct tree_node* getnode(){
	tree_node*pnode=new tree_node();
	pnode->value=0;
	for(int i=0;i<26;i++)
		pnode->child[i]=NULL;
	return pnode;
}
struct trie* gettree()
{
	trie*ptrie=new trie();
	
	ptrie->root=getnode();
	return ptrie;
}

bool insert(trie*ptrie,string key)
{
	int length=key.length();
	
	tree_node *pcrawl=ptrie->root;
	for(int i=0;i<length;i++)
	{
		int index=key[i]-'a';
		if(pcrawl->child[index])
		{
			if(pcrawl->child[index]->value)
			return true;
		}
		else
			pcrawl->child[index]=getnode();

		pcrawl=pcrawl->child[index];
	}
	pcrawl->value=1;
	return false;
}

int main()
{
	int tc,num;
	
	
	
	
			vector<string>triee[51];
		scanf("%d",&num);
		string str;
		for(int i=0;i<num;i++)
			{
				cin>>str;
				triee[str.length()].push_back(str);
			}
		
		trie*ptrie=gettree();
		bool check=true;
		for(int i=1;i<51 && check;i++)
		{
			for(int j=0;j<triee[i].size();j++)
			{
				
				if(insert(ptrie,triee[i][j]))
				{
					check=false;
					break;
				}
			}
		}
		if(check)
			cout<<"non vulnerable\n"<<endl;
		else
			cout<<"vulnerable\n"<<endl;
	
}
	
