#include<iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int count=1;
	while(1){
		int n;
		cin >> n;
		if(n==0)	break;
		long long arr[n][3];
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++)
				cin >> arr[i][j];
		}
		arr[0][2] += arr[0][1];
		arr[1][0] += arr[0][1];
		arr[1][1] += min(arr[1][0],min(arr[0][1],arr[0][2]));
		arr[1][2] += min(arr[1][1],min(arr[0][2],arr[0][1]));
		for(int i=2;i<n;i++){
			for(int j=0;j<3;j++){
				if(j==0){
					arr[i][j] += min(arr[i-1][j],arr[i-1][j+1]);
				}else if(j==1){
					arr[i][j] += min(min(arr[i][j-1],arr[i-1][j-1]),min(arr[i-1][j],arr[i-1][j+1]));
				}else{
					arr[i][j] += min(arr[i][j-1],min(arr[i-1][j-1],arr[i-1][j]));
				}
			}
		}
	/*	for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}*/
		cout << count << ". " << arr[n-1][1] << "\n";
	}
}
