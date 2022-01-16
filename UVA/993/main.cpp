#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

string fact(ll n){
    string ret;
    if(n < 2){
        ret = to_string(n);
        return ret;
    }
    vector<ll>frq(10);
    for(ll i = 2;i * i<=n && i < 10;i++){
        while(n % i == 0){
            frq[i]++;
            n /= i;
        }
    }
    if(n != 1){
        if(n >= 10)
            return "-1";
        // ret = to_string(n);
        frq[n]++;
    }
    // for(ll i = 0;i<10;i++)
    //     cout << i << " " << frq[i] << endl;
    for(ll i = 4;i<10;i++){
        ret += string(frq[i],i + '0');
    }
    ret += string(frq[2] / 3,'8');
    ret += string(frq[3] / 2,'9');

    frq[2] %= 3;
    frq[3] %= 2;
    if(frq[2] == 2 && frq[3]){
        ret += "26";
    }
    else if(frq[2] && frq[3])
        ret += "6";
    else if(frq[2] == 2)
        ret += "4";
    else if(frq[2])
        ret += "2";
    else if(frq[3])
        ret += "3";


    return ret;




}

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
        ll n;
        cin >> n;
        auto res = fact(n);
        sort(all(res));
        cout << res << endl;
    }

}


