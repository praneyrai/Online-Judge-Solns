#include<iostream>
#include<list>
#include<queue>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	list<int> add[n+1];
	for(int i=0; i<m; i++){
		int a,b;
		cin >> a >> b;
		add[a].push_back(b);
	}
	int max = -99;
	bool flag = true;
	for(int i=1;i<=n;i++){
		queue<int> qq;
		int count = 1;
		qq.push(i);
		int visited[n+1] = {0};
		visited[i] = 1;
		while(!qq.empty()){
			int x = qq.front();
			qq.pop();
			for(auto it = add[x].begin(); it != add[x].end(); it++){
				if(visited[*it] == 0){
					qq.push(*it);
					count++;
					visited[*it] = 1;
				}
			}
		}
		if(count > max){
			max = count;
		}
		if(max == n){
			flag = false;
			cout << n << "\n";
			break;
		}
	}
	if(flag)
		cout << max;
}
