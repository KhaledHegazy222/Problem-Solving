#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ll n;
vector<ll>pre;



ll sum(ll x){
    return max(0ll,1ll * x * (x + 1) / 2);
}

ll sumRows(ll x){
    return x * x;
}

ll solve(){

    ll res = 0;
    ll row = upper_bound(all(pre),n) - pre.begin();
    res += sumRows(row - 1);
    n -= pre[row - 1];
    if(n > sum(row)){
        n -= sum(row);
        res += row;
        ll l = 1,r = row - 1;
        while(l != r){
            ll mid = l + (r - l) / 2;
            if(sum(row - 1) - sum(row - mid - 1) >= n){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        res += l;
    }
    else{
        ll l = 0,r = row;
        while(l != r){
            ll mid = l + (r - l) / 2;
            if(sum(mid) >= n){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        res += l;
    }


    return res;




}





signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    #ifndef Khaled
        freopen("army.in","r",stdin);
        #define endl '\n'
        fast;
    #endif
    



    pre.push_back(0);
    ll i = 1;
    while(pre.back() < 1e18){
        pre.push_back(pre.back() +  sum(i) + sum(i - 1));
        i++;
    }

    ll t;
    cin >> t;
    ll cs = 1;
    while(t--){
        cin >> n;
        cout << "Case " << cs++ << ": " << solve() << endl;
    }
}


