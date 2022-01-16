#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

vector<ll>logs;
ll n,k;


ll valid(ll x){
    ll cuts = 0;
    for(ll i = 0;i < n;i++){
        if(logs[i] > x)
            cuts += logs[i] / x;
    }
    return cuts <= k;
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
    
    cin >> n >> k;
    logs.resize(n);
    for(auto &elem : logs)
        cin >> elem;
    
    ll l = 1,r = 1e9;
    while(l != r){
        ll mid = l + (r - l) / 2;
        if(valid(mid)){
            r = mid;
        }
        else{
            l = mid + 1;
        }   
    }
    cout << l << endl;


}


