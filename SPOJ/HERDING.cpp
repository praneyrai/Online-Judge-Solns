#include<iostream>
#include<queue>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	char arr[n+2][m+2];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cin >> arr[i][j];
	}
	int visited[n+2][m+2];
	for(int i=0;i<=n+1;i++)	
		for(int j=0;j<=m+1;j++){
			if(i==0 || j==0 || i==n+1 || j==m+1){
				visited[i][j] = 1;
				arr[i][j] = 'x';
			}
			else
				visited[i][j] = 0;
		}	
	int count=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(visited[i][j] == 0){
				visited[i][j] = 1;
				count++;
				queue<pair<int,int> > qq;
				qq.push(make_pair(i,j));
				while(!qq.empty()){
					int xx = qq.front().first;
					int yy = qq.front().second;
				//	cout << xx << " " << yy << "\n";
					qq.pop();
					if(arr[xx][yy] == 'S' && visited[xx+1][yy] == 0){
						qq.push(make_pair(xx+1,yy));
						visited[xx+1][yy] = 1;
					}else if(arr[xx][yy] == 'W' && visited[xx][yy-1] == 0){
						qq.push(make_pair(xx,yy-1));
						visited[xx][yy-1] = 1;
					}else if(arr[xx][yy] == 'E' && visited[xx][yy+1] == 0){
						qq.push(make_pair(xx,yy+1));
						visited[xx][yy+1] = 1;
					}else if(arr[xx][yy] == 'N' && visited[xx-1][yy] == 0){
						qq.push(make_pair(xx-1,yy));
						visited[xx-1][yy] = 1;
					}
					if(arr[xx][yy+1] == 'W' && visited[xx][yy+1] == 0){
						qq.push(make_pair(xx,yy+1));
						visited[xx][yy+1] = 1;
					}
					if(arr[xx-1][yy] == 'S' && visited[xx-1][yy] == 0){
						qq.push(make_pair(xx-1,yy));
						visited[xx-1][yy] = 1;
					}
					if(arr[xx][yy-1] == 'E' && visited[xx][yy-1] == 0 ){
						qq.push(make_pair(xx,yy-1));
						visited[xx][yy-1] = 1;
					}
					if(arr[xx+1][yy] == 'N' && visited[xx+1][yy] == 0){
						qq.push(make_pair(xx+1,yy));
						visited[xx+1][yy] = 1;
					}
				}
			/*	for(int i=1;i<=n;i++){
					for(int j=1;j<=m;j++){
						cout << visited[i][j] << " ";
					}
					cout << "\n";
				}
				cout << "\n";*/
			}
		}
	}
	cout << count;
}
