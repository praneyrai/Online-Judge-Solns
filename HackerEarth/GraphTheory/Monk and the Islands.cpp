    #include<iostream>
    #include<list>
    #include<queue>
    using namespace std;
     
    int main(){
    	int t;
    	cin >> t;
    	while(t--){
    		int n,m;
    		cin >> n >> m;
    		list<int> add[n+1];
    		for(int i=0;i<m;i++){
    			int a,b;
    			cin >> a >> b;
    			add[a].push_back(b);
    			add[b].push_back(a);
    		}
    		queue<int> qq;
    		qq.push(1);
    		int visited[n+1];
    		for(int i=1;i<=n;i++)
    			visited[i] = 0;
    		int dist[n+1];
    		dist[1]=0;
    		visited[1]=1;
    		while(!qq.empty()){
    			int x = qq.front();
    			qq.pop();
    			for(list<int>::iterator it = add[x].begin(); it!=add[x].end(); it++){
    				if(visited[*it] == 0){
    					visited[*it]=1;
    					qq.push(*it);
    					dist[*it] = dist[x] + 1;
    					if(*it == n){
    						cout << dist[n] << "\n";
    						break;
    					}
    				}
    			}
    		}
    	}
    }