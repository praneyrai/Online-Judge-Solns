#include<iostream>
#include<queue>
#include<set>
#include<vector>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	int sc=1;
	while(t--){
		int n,m;
		cin >> n >> m;
		if(m==0){
			cout << "Scenario #" << sc << ":\n";
			sc++;
			for(int i=1;i<=n;i++){
				cout << i << " " << i-1 << "\n";
			}
			continue;
		}
		set<int> add[n+1];
		int indeg[n+1]={0};
		bool flag=false;
		for(int i=0;i<m;i++){
			int a,b;
			cin >> a >> b;
			add[b].insert(a);
			indeg[a]++;
			if(a==n || b==n)
				flag = true;
		}
		queue<int> qq;
		int rank[n+1];
		int visited[n+1]={0};
		set<int> rr[1000];
		for(int i=0;i<=n&&flag;i++){
			if(indeg[i] == 0){
				qq.push(i);
				visited[i] = 1;
				rank[i] = 1;
				rr[1].insert(i);
			}
		}
		for(int i=0;i<n&&!flag;i++){
			if(indeg[i] == 0){
				qq.push(i);
				visited[i] = 1;
				rank[i] = 1;
				rr[1].insert(i);
			}
		}
		int count=0;
		while(!qq.empty()){
			int x = qq.front();
			qq.pop();
			for(set<int>::iterator it = add[x].begin(); it!=add[x].end(); it++){
				if(visited[*it] == 0){
					indeg[*it]--;
					if(indeg[*it] == 0){
						qq.push(*it);
						visited[*it]=1;
						rank[*it] = rank[x] + 1;
						rr[rank[*it]].insert(*it);
					}
				}
			}
		}
		cout << "Scenario #" << sc << ":\n";
		sc++;
		for(int i=1;i<1000;i++){
			for(set<int>::iterator it = rr[i].begin(); it!= rr[i].end(); it++){
				cout << i << " " << *it << "\n";
			}
		}
	}
}
