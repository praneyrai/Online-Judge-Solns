#include<iostream>
#include<queue>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	int t;
	cin >> t;
	while(t--){
		int xm,ym,c1x,c1y,c2x,c2y;
		cin >> xm >> ym >> c1x >> c1y >> c2x >> c2y;
		int mouse[n+1][m+1];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				mouse[i][j] = -1;
		}
		mouse[xm][ym]=0;
		queue<pair<int,int> > qq;
		qq.push(make_pair(xm,ym));
		while(!qq.empty()){
			int x = qq.front().first;
			int y = qq.front().second;
			qq.pop();
			if(mouse[x-1][y] == -1 && x-1 >= 1){
				mouse[x-1][y] = mouse[x][y] + 1;
				qq.push(make_pair(x-1,y));
			}
			if(mouse[x+1][y] == -1 && x+1 <= n){
				mouse[x+1][y] = mouse[x][y] + 1;
				qq.push(make_pair(x+1,y));
			}
			if(mouse[x][y-1] == -1 && y-1 >= 1){
				mouse[x][y-1] = mouse[x][y] + 1;
				qq.push(make_pair(x,y-1));
			}
			if(mouse[x][y+1] == -1 && y+1 <= m){
				mouse[x][y+1] = mouse[x][y] + 1;
				qq.push(make_pair(x,y+1));
			}
		}
		int cat1[n+1][m+1];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				cat1[i][j] = -1;
		}
		cat1[c1x][c1y] = 0;
		qq.push(make_pair(c1x,c1y));
		while(!qq.empty()){
			int x = qq.front().first;
			int y = qq.front().second;
			qq.pop();
			if(cat1[x-1][y] == -1 && x-1 >= 1){
				cat1[x-1][y] = cat1[x][y] + 1;
				qq.push(make_pair(x-1,y));
			}
			if(cat1[x+1][y] == -1 && x+1 <= n){
				cat1[x+1][y] = cat1[x][y] + 1;
				qq.push(make_pair(x+1,y));
			}
			if(cat1[x][y-1] == -1 && y-1 >= 1){
				cat1[x][y-1] = cat1[x][y] + 1;
				qq.push(make_pair(x,y-1));
			}
			if(cat1[x][y+1] == -1 && y+1 <= m){
				cat1[x][y+1] = cat1[x][y] + 1;
				qq.push(make_pair(x,y+1));
			}
		}
		int cat2[n+1][m+1];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				cat2[i][j] = -1;
		}
		cat2[c2x][c2y]=0;
		qq.push(make_pair(c2x,c2y));
		while(!qq.empty()){
			int x = qq.front().first;
			int y = qq.front().second;
			qq.pop();
			if(cat2[x-1][y] == -1 && x-1 >= 1){
				cat2[x-1][y] = cat2[x][y] + 1;
				qq.push(make_pair(x-1,y));
			}
			if(cat2[x+1][y] == -1 && x+1 <= n){
				cat2[x+1][y] = cat2[x][y] + 1;
				qq.push(make_pair(x+1,y));
			}
			if(cat2[x][y-1] == -1 && y-1 >= 1){
				cat2[x][y-1] = cat2[x][y] + 1;
				qq.push(make_pair(x,y-1));
			}
			if(cat2[x][y+1] == -1 && y+1 <= m){
				cat2[x][y+1] = cat2[x][y] + 1;
				qq.push(make_pair(x,y+1));
			}
		}
		bool pos = false;
		for(int i=1;i<=n;i++){
			if(mouse[i][1] < cat1[i][1] && mouse[i][1] < cat2[i][1])
				pos = true;
		}
		for(int i=1;i<=n;i++){
			if(mouse[i][m] < cat1[i][m] && mouse[i][m] < cat2[i][m])
				pos = true;
		}
		for(int i=1;i<=m;i++){
			if(mouse[1][i] < cat1[1][i] && mouse[1][i] < cat2[1][i])
				pos = true;
		}
		for(int i=1;i<=m;i++){
			if(mouse[n][i] < cat1[n][i] && mouse[n][i] < cat2[n][i])
				pos = true;
		}
		if(pos)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
