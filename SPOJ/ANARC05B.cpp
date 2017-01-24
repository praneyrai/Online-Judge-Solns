    #include<iostream>
    #include<set>
    #include<map>
    #include<vector>
    #include<algorithm>
    using namespace std;
     
    int main(){
    	ios_base::sync_with_stdio(false);
    	while(1){
    		int a,b;
    		vector<int> aa,bb;
    		cin >> a;
    		if(a==0)	break;
    		aa.resize(a);
    		map<int,int> mapa;
    		map<int,int> mapb;
    		for(int i=0;i<a;i++){
    			cin >> aa[i];
    			mapa[aa[i]]=i;
    		}
    		cin >> b;
    		bb.resize(b);
    		for(int i=0;i<b;i++){
    			cin >> bb[i];
    			mapb[bb[i]]=i;
    		}
    		long long ans=0;
    		int ap=0,bp=0;
    		if(a < b){
    			for(int i=0;i<a;i++){
    				if(find(bb.begin(),bb.end(),aa[i]) != bb.end()){
    					long long s1=0,s2=0;
    					for(int j=ap;j<=mapa[aa[i]];j++){
    						s1+=aa[j];
    					}
    					for(int j=bp;j<=mapb[aa[i]];j++){
    						s2+=bb[j];
    					}
    					if(s1 > s2){
    						ans+=s1;
    					}else{
    						ans+=s2;
    					}
    					ap=mapa[aa[i]]+1;
    					bp=mapb[aa[i]]+1;
    				}
    			}
    		}else{
    			for(int i=0;i<b;i++){
    				if(find(aa.begin(),aa.end(),bb[i]) != aa.end()){
    					long long s1=0,s2=0;
    					for(int j=ap;j<=mapa[bb[i]];j++){
    						s1+=aa[j];
    					}
    					for(int j=bp;j<=mapb[bb[i]];j++){
    						s2+=bb[j];
    					}
    					if(s1 > s2){
    						ans+=s1;
    					}else{
    						ans+=s2;
    					}
    					ap=mapa[bb[i]]+1;
    					bp=mapb[bb[i]]+1;
    				}
    			}
    		}
    		long long s1=0,s2=0;
    		for(int i=ap;i<a;i++){
    			s1+=aa[i];
    		}	
    		for(int i=bp;i<b;i++){
    			s2+=bb[i];
    		}
    		if(s1 > s2){
    			ans+=s1;
    		}else{
    			ans+=s2;
    		}
    		cout << ans << "\n";	
    	}
    } 