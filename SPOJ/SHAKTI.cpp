    #include <iostream>
    using namespace std;
     
    int main() {
    	
    	// your code here
        int t;
        cin >> t;
        while(t--){
        	int x;
        	cin  >> x;
        	if(x==2)
        	  cout<<"Sorry Shaktiman\n";
        	else if(x==3)
        	  cout<<"Thankyou Shaktiman\n";
        	else if(x%2 == 0)
        	  cout<<"Thankyou Shaktiman\n";
        	else
        	  cout<<"Sorry Shaktiman\n";
        }
    	return 0;
    } 