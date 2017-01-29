    #include<iostream>
    using namespace std;
     
    int main(){
    	while(1){
    		string s;
    		getline(cin,s);
    		if(s.length()==0)	break;
    		bool flag = false;
    		for(int i=0;i<s.length();i++){
    			if(!flag && s[i]=='-' && s[i+1]=='>'){
    				cout << ".";
    				i++;
    			}else{
    				cout << s[i];
    			}
    			if(s[i]=='/' && s[i+1]=='/')
    			    flag=true;
    		}
    		cout << "\n";
    	}
    }