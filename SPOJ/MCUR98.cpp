    #include <stdio.h>
    #include <bits/stdc++.h>
    using namespace std;
    #ifdef _WIN32
    	#define pc putchar
    	#define gc getchar
    #else
    	#define pc putchar_unlocked
    	#define gc getchar_unlocked
    #endif
     
    typedef long long ll;
     
    void putln(ll a) {int n=(a<0?1:0);if(n)a=-a;char b[20];int i=0;do{b[i++]=a%10+'0';a/=10;}while(a);if(n)pc('-');i--;while(i>=0)pc(b[i--]);pc('\n');}
     
    long long a[1001000];
     
    long long f(int n) {
    	int x = n;
    	int s = 0;
    	while (x) {
    		s += x%10;
    		x = x /10;
    	}
    	return s + n;
    }
    int main() {
    	for (int i = 1; i < 1000000; i++) {
    		if (a[i] == 0) {
    			putln(i);
    			int in = f(i);
    			while (in < 1000000) {
    				if (a[in] == 1) break;
    				a[in] = 1;
    				in = f(in);
    			}
    		}
    	}	
    } 