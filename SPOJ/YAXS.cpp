    #include<iostream>
    using namespace std;
     
    int main(){
    	ios_base::sync_with_stdio(false);
    	int t,count=1;
    	cin >> t;
    	while(t--){
    		int n;
    		cin >> n;
    		int cc[5]={0},x;
    		for(int i=0;i<n;i++){
    			cin >> x;
    			cc[x-1]++;
    		}
    		int arr[5],c1=cc[0],c2=cc[1],c3=cc[2],c4=cc[3],c5=cc[4];
    		arr[0] = c1 + min(c2,c3) + min(c4,c5);
    		arr[1] = c2 + min(c1+min(c4,c5),c3);
    		arr[2] = c3 + min(c1+min(c4,c5),c2);
    		arr[3] = c4 + min(c1+min(c2,c3),c5);
    		arr[4] = c5 + min(c1+min(c2,c3),c4);
    		int max = 0;
    		for(int i=0;i<5;i++){
    		//	cout << arr[i] << "\n";
    			if(max < arr[i]){
    				max =  arr[i];
    			}
    		}
    		cout << "Case " << count << ": " << max << "\n";
    		count++;
    	}
    } 