    #include <iostream>
    using namespace std;
     
    int main()
    {
        //cout << "Hello World!" << endl;
        int t;
        cin >> t;
        while(t--){
            string s;
            cin >> s;
            bool flag=true;
            for(int i=0;i<s.length()/2;i++){
                if(s[i] != s[s.length()-i-1]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                if(s.length()%2 == 0)
                    cout << "YES EVEN\n";
                else
                    cout << "YES ODD\n";
            }else
                cout << "NO\n";
        }
        return 0;
    }