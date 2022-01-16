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
    
    string s;
    cin >> s;
    ll res = 0;
    ll fact = 1;
    for(ll i = 1;i < s.size();i++)
        res += 1 << i;

    for(ll i = s.size() - 1;i >= 0;i--){
        if(s[i] == '7')
            res += fact;
        fact <<= 1;
    }


    cout << res +1 <<endl;
}


