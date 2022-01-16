
#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)


using namespace std;

map<string,string>mp;

map<string,string>::iterator f(string &x){
    auto it = mp.begin();
    for(;it != mp.end();it++){
        if(it->second == x){
            return it;
        }
    }
    return it;
}




int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    
    int n;
    cin >> n;
    while(n--){
        string a,b;
        cin >> a >> b;
        auto it = f(a);
        if( it == mp.end()){
            mp.insert({a,b});
        }
        else{
            it->second = b;
        }
    }

    cout << mp.size() << endl;
    for(auto it : mp){
        cout << it.first << " " << it.second << endl;
    }




}

