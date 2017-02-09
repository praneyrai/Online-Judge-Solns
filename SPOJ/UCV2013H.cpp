#include<iostream>
#include<queue>
#include<map>
#include<set>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	while(1){
		int n,m;
		cin >> n >> m;
		if(n==0 && m==0)	break;
		int arr[n+1][m+1];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				cin >> arr[i][j];
		}
		int visited[n+2][m+2];
		for(int i=0;i<=n+1;i++)
			for(int j=0;j<=m+1;j++){
				if(i==0 || j==0 || i==n+1 || j==m+1)
					visited[i][j] = -1;
				else
					visited[i][j] = 0;
			}
		set<int> st;
		map<int,int> mp;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(arr[i][j] == 1 && visited[i][j] == 0){
					int count=0;
					visited[i][j] = 1;
					queue<pair<int,int> > qq;
					qq.push(make_pair(i,j));
					while(!qq.empty()){
						int xx = qq.front().first;
						int yy = qq.front().second;
						qq.pop();
						count++;
						if(arr[xx-1][yy] == 1 && visited[xx-1][yy] == 0){
							qq.push(make_pair(xx-1,yy));
							visited[xx-1][yy] = 1;
						}
						if(arr[xx+1][yy] == 1 && visited[xx+1][yy] == 0){
							qq.push(make_pair(xx+1,yy));
							visited[xx+1][yy] = 1;
						}
						if(arr[xx][yy-1] == 1 && visited[xx][yy-1] == 0){
							qq.push(make_pair(xx,yy-1));
							visited[xx][yy-1] = 1;
						}
						if(arr[xx][yy+1] == 1 && visited[xx][yy+1] == 0){
							qq.push(make_pair(xx,yy+1));
							visited[xx][yy+1] = 1;
						}
					}
					st.insert(count);
					mp[count]++;
				}
			}
		}
		int ans=0;
		for(auto it = st.begin(); it!= st.end(); it++)
			ans += mp[*it];
		cout << ans << "\n";
		for(auto it = st.begin(); it!= st.end(); it++)
			cout << *it << " " << mp[*it] << "\n";
	}
}
