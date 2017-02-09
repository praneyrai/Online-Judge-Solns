#include<iostream>
#include<queue>
using namespace std;

int main(){
	int f,s,g,u,d;
	cin >> f >> s >> g >> u >> d;
	if(s == g){
		cout << 0;
		return 0;
	}
	int visited[f+1]={0};
	visited[s] = 1;
	queue<int> qq;
	qq.push(s);
	int count=0;
	bool flag = true;
	int x=-1;
	while(!qq.empty()){
		x = qq.front();
		if(x == g)	break;
		qq.pop();
		if(x < g && x+u <= f){
			x = x+u;
			if(visited[x] == 0){
				visited[x] = 1;
				count++;
				qq.push(x);
			}else{
				flag = false;
				break;
			}
		}else if(x >= g-d && x-d >= 0){
			x = x-d;
			if(visited[x] == 0){
				visited[x] == 1;
				count++;
				qq.push(x);
			}else{
				flag = false;
				break;
			}
		}
	}
	if(flag){
		cout << count;
	}else
		cout << "use the stairs\n";
}
