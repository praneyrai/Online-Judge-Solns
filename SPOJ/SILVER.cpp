    #include <iostream>
    #include <cmath>
    using namespace std;
     
    int two[20];
    void init() {
    	two[0] = 1;
    	for (int i = 1; i < 20; i++) two[i] = 2*two[i-1];
    }
    int main() {
    	ios::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
    	init();
    	while (1) {
    		int n;
    		cin >> n;
    		if(n == 0)  break;
    		int sum = 0, cnt = 0;
    		for (int i = 0; ; i++) {
    			if (sum + two[i] >= n) break;
    			cnt++;
    			sum += two[i];
    		}
    		cout << cnt << "\n";
    	}
    } 