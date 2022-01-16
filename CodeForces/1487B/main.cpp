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
        ll n,k;
        cin >> n >> k;
        k--;
        if(n % 2){
            ll add = k / (n - 1);
            ll pos = k % (n - 1);
            if(pos >= n / 2)
                add++;

            cout << (pos + add) % n + 1 << endl;

        }
        else{
            cout << (k % n) + 1 << endl;
        }
    }
}


