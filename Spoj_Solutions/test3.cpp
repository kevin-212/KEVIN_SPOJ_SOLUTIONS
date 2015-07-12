#include<bits/stdc++.h>
#include<dirent.h>
#include<sys/stat.h>
using namespace std;

map<string,int>msearch;
map<string,int>mdoc;
vector<double>cosine_similarity;
vector<int>num;
vector<string>names;
bool cmp(int a,int b)
{
	return cosine_similarity[a]>cosine_similarity[b];
}
void search(char*c1)
{
	char* s;
	freopen(c1,"r",stdin);
	while((scanf("%s",s)!=EOF))
	{
		msearch[s]++;
	}
	
}

double calc(){
		map<string,int>::iterator it1,it2;
	 	double dotProduct=0,modA=0,modB=0;
	 	int freq;
	 	
		it1=mdoc.begin();
		it2=mdoc.end();
	
	
	while(it1!=it2){
		freq=it1->second;
		
		if(msearch[it1->first]!=0){
		dotProduct+=(msearch[it1->first]*freq);
		}
		modA+=1.00*(freq*freq);
		it1++;
	}
	modA=sqrt(modA);
	
	it1=msearch.begin();
	it2=msearch.end();
	
	while(it1!=it2){
		freq=it1->second;
		modB+=1.00*freq*freq;
		it1++;
	}
	modB=sqrt(modB);
	return 1.00*dotProduct/(1.00*modA*modB);
}

void explore(char* dir_name){
	
	DIR*dir;
	char*s;
	struct dirent *entry;
	struct stat *info;
	int index=-1;
	dir=opendir(dir_name);
	
	int sz;
	if(!dir)	{
		puts("Directorty Not found\n");
		return;
	}
	
	while((entry=readdir(dir))!=NULL){
		if(entry->d_name[0]=='.')
		continue;
		
		 string path1=string(dir_name)+"\\"+ string(entry->d_name);
		 sz=path1.length();
		 char*path=new char[sz+1];
		 for(int i=0;i<sz;i++)
		 path[i]=path1[i];
		 path[sz]='\0';
		 names.push_back(entry->d_name);
		freopen (path,"r",stdin);
		
		
		while(scanf("%s",s)!=EOF)
		mdoc[s]++;
			index++;
			num.push_back(index);
	cosine_similarity.push_back(calc());
	mdoc.clear();	
	
			fclose(stdin);
	}
	closedir(dir);
}

int main(int argc,char**argv){
	char c[1000];
	char c1[1000];
	int sz;
	
	cout<<"Enter directory path."<<endl;
	cin>>c;
	
	cout<<"Enter Path of Document."<<endl;
	cin>>c1;
	
	search(c1);
	explore(c);
	sort(num.begin(),num.end(),cmp);
	sz=num.size();
	
	if(sz<3){
		for(int i=0;i<sz;i++)
		cout<<names[num[i]]<<endl;
	}else{
		for(int i=0;i<3;i++)
		cout<<names[num[i]]<<endl;
	}
}
