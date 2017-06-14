    #include "bits/stdc++.h"
     
    using namespace std;
     
    int main() {
    /*	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    */	int t; cin >> t;
    	while (t--) {
    		int w, h, n;
    		cin >> w >> h >> n;
    		if (n == 0) {
    			cout << w * h << '\n';
    			continue;
    		}
    		set<int> a, b;
    		vector<int> f1, f2;
    		for (int i = 0; i < n; i++) {
    			int x, y;
    			cin >> x >> y;
    			a.insert(x);
    			b.insert(y);
    		}
    		for (auto i : a) {
    			f1.push_back(i);
    		}
    		for (auto i : b) {
    			f2.push_back(i);
    		}
    		vector<int> v1, v2;
    		v1.push_back(f1[0] - 1);
    		v1.push_back(w - f1[f1.size() - 1]);
    		for (int i = 1; i < f1.size(); i++) {
    			v1.push_back(f1[i] - f1[i - 1] - 1);
    		}
    		v2.push_back(f2[0] - 1);
    		v2.push_back(h - f2[f2.size() - 1]);
    		for (int i = 1; i < f2.size(); i++) {
    			v2.push_back(f2[i] - f2[i - 1] - 1);
    		}
    		sort(v1.begin(), v1.end());
    		sort(v2.begin(), v2.end());
    		cout << v1[v1.size() - 1] * v2[v2.size() - 1] << '\n';
    	}
    } 