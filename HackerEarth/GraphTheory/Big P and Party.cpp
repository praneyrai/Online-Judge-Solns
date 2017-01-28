#include<iostream>
#include<list>
#include<queue>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	list<int> add[n];
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		add[a].push_back(b);
		add[b].push_back(a);
	}
	int dist[n];
	for(int i=1;i<n;i++){
		dist[i]=-1;
	}
	queue<int> qq;
	qq.push(0);
	dist[0]=0;
	int visited[n];
	for(int i=0;i<n;i++)
		visited[i]=0;
	while(!qq.empty()){
		int x = qq.front();
		qq.pop();
		for(list<int>::iterator it = add[x].begin(); it!=add[x].end(); it++){
			if(visited[*it]==0){
				visited[*it]=1;
				qq.push(*it);
				dist[*it] = dist[x] + 1;
			}
		}
	}
	for(int i=1;i<n;i++)
		cout << dist[i] << "\n";
}