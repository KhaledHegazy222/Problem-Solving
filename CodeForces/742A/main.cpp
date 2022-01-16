#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


int MOD;

int power(int b,int p){
    int ret = 1;
    while(p){
        if(p & 1){
            ret = (1ll * ret * b) % MOD;
        }
        b = (1ll * b * b) % MOD;
        p >>= 1;
    }
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
    

    int t;
    // cin >> t;
    t = 1;
    while(t--){
        int x,y;

        // cin >> x >> y >> MOD;
        cin >> y;
        MOD = 10;
        x = 1378;
        cout << power(x,y) << endl;
    }


}


