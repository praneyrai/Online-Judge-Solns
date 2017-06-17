    #include "bits/stdc++.h"
     
    using namespace std;
     
    long long a[110][110], b[110][110], n, q, ar[110], bc[110];
    long long ff() {
    	long long sum = 0;
    	for (int c = 0; c < n; c++) {
        	for (int d = 0; d < n; d++) {
            	for (int k = 0; k < n; k++) {
              		sum = sum + a[c][k] * b[k][d];
            	}
        	}
    	}
    	return sum;
    }
    void init() {
    	for (int i = 0; i < n; i++) {
    		long long ss = 0;
    		long long sss = 0;
    		for (int j = 0; j < n; j++) {
    			ss += a[j][i];
    			sss += b[i][j];
    		}
    		ar[i] = ss;
    		bc[i] = sss;
    	}
    }
    int main() {
    	cin >> n;
    	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
    	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> b[i][j];
    	long long osum = ff();
    	init();
    	cin >> q;
    	while (q--) {
    		char c;
    		long long x, y, val;
    		cin >> c >> x >> y >> val;
    		if (c == 'A') {
    			long long el = a[x][y];
    			osum = osum - el * bc[y] + val * bc[y];
    			a[x][y] = val;
    			ar[y] = ar[y] - el + val;
    		} else {
    			long long el = b[x][y];
    			osum = osum - el * ar[x] + val * ar[x];
    			b[x][y] = val;
    			bc[x] = bc[x] - el + val;
    		}
    		cout << osum << '\n';
    	}
    } 