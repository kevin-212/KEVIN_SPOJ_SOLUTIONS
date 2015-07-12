#include<iostream>
#include<queue>
using namespace std;
struct vert
{
	int x,y,count;
};
bool check(int x,int y,bool visited[8][8])
{
	if(x<0||x>7 ||y<0 || y>7 || visited[x][y])
	return false;
	return true;
}
void bfs(vert a,vert b)
{
	bool visited[8][8];
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++)
	visited[i][j]=false;
	queue<vert>Q;
	Q.push(a);
	while(!Q.empty())
	{
		vert temp=Q.front();
		Q.pop();
		int x=temp.x;
		int y=temp.y;
		int count=temp.count;
		if(visited[x][y])
		continue;
		if(x==b.x && y==b.y)
		{
			cout<<count<<endl;
			break;
		}
		
		visited[x][y]=true;
		
		if(check(x+1,y+2,visited))
		Q.push((vert){x+1,y+2,count+1});
		
		if(check(x+1,y-2,visited))
		Q.push((vert){x+1,y-2,count+1});
		
		if(check(x-1,y+2,visited))
		Q.push((vert){x-1,y+2,count+1});
		
		if(check(x-1,y-2,visited))
		Q.push((vert){x-1,y-2,count+1});
		
		if(check(x+2,y+1,visited))
		Q.push((vert){x+2,y+1,count+1});
		
		if(check(x+2,y-1,visited))
		Q.push((vert){x+2,y-1,count+1});
		
		if(check(x-2,y+1,visited))
		Q.push((vert){x-2,y+1,count+1});
		
		if(check(x-2,y-1,visited))
		Q.push((vert){x-2,y-1,count+1});
		
		
	}
	
	
}
int main()
{
	int tc;
	char a[3],b[3];
	cin>>tc;
	while(tc--)
	{
		cin>>a;
		cin>>b;
		bfs((vert){a[0]-'a',a[1]-'1',0},(vert){b[0]-'a',b[1]-'1'});
	}
}
