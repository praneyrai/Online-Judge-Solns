    #include<iostream>
    using namespace std;
    typedef long long ll;
    int mp[1000001]={0};
    inline ll input1(){ll number=0;bool negative=false;register int c;number=0;c=getchar();if(c=='-'){negative=true;c=getchar();}for(;(c>47 && c<58);c=getchar())number=number*10+c-48;if(negative)number*= -1;return number;}
    int main(){
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	int k,l,m;
    	k = input1();
    	l = input1();
    	m = input1();
    	mp[1] = 1;
    	mp[k] = 1;
    	mp[l] = 1;
    	for(int i=1;i<=1000000;i++){
    		if(mp[i]==0){
    			if(mp[i-1]==2 || mp[i-k]==2 || mp[i-l]==2){
    				mp[i] = 1;
    			}else
    				mp[i] = 2;
    		}
    	}
    	while(m--){
    		int test;
    		test = input1();
    		if(mp[test]==1)
    			cout << "A";
    		else
    			cout << "B";
    	}
    	/*for(int i=1;i<14;i++)
    		cout << mp[i] << " ";*/
    } 
