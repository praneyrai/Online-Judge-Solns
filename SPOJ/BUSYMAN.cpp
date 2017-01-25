#include<iostream>
#include<algorithm>
using namespace std;

struct time{
	int start,end;
};

bool comp(time a,time b){
	if(a.end < b.end)
		return true;
	else if(a.end==b.end){
		if(a.start < b.start)
			return true;
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		time arr[n];
		for(int i=0;i<n;i++){
			cin >> arr[i].start >> arr[i].end;
		}
		sort(arr,arr+n,comp);
		int count=1,curr=arr[0].end;
		for(int i=1;i<n;i++){
			if(arr[i].start >= curr){
				count++;
				curr = arr[i].end;
			}
		}
		cout << count << "\n";
	}
}
