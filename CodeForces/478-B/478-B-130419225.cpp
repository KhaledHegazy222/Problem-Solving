#include <bits/stdc++.h>
#define endl '\n'
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    ll n,m;
    cin >> n >> m;
    ll mn = 1ll * (n - m + 1 ) * (n - m) / 2;
    ll gSz = (n + m - 1) / m;
    ll big_groups = n % m;
    ll small_groups = m - big_groups;
    if(n % m == 0){
        big_groups = m;
        small_groups = 0;
    }
    
    ll mx = (big_groups) * (gSz * (gSz - 1)) / 2 + small_groups * ((gSz-1) * (gSz - 2)) / 2;

    cout << mx << " " << mn << endl;


}