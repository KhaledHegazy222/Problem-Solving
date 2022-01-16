
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

typedef unsigned long long ull;
typedef long long ll;

using namespace std;
ull npr(ull n,ull r){
    
    if(r > n) return 0;
    if(r == 0) return 1;
    if(r == 1) return n;
    
    ull ret = 1;
    for(int i = 0;i<r;i++){
        ret *= n--;
    }
    return ret;
}




int main(void){
   
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 


    int t;
    cin >> t;
    int ds = 1;
    while(t--){
        int alpha[26] = {0};
        string s;
        cin >> s;
        for(int i = 0;i<s.length();i++){
            alpha[s[i]-'A']++;
        }
        ull res = npr(s.length(),s.length()); 
        for(int i = 0;i<26;i++){
            if(alpha[i]){
                res /= npr(alpha[i],alpha[i]);
            }
        }
        cout << "Data set " << ds++ << ": ";
        cout << res << endl;
    }

    



}   


