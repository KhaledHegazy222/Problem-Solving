#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    #ifndef Khaled
        #define endl '\n'
        fast;
    #endif
    ll t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        string a = s.substr(0,s.size() / 2);
        string b = s.substr((s.size() + 1 )/ 2,s.size() / 2);
        sort(all(a));
        sort(all(b));
        cout << (a != b ? "NO\n" : "YES\n");


    }    

}


