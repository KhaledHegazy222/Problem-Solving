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
    
    ll n,m;
    cin >> n >> m;
    ll odd = 0,even = 0;
    while(n--){
        string s;
        cin >> s;
        ll res = 0;
        for(ll i = 0;i<s.size();i++){
            res += (s[i] - '0') * (1 << (s.size() - i - 1));
        }
        odd += __builtin_popcount(res) % 2;
        even += __builtin_popcount(res) % 2 == 0;
    }
    cout << odd * even << endl;
}


