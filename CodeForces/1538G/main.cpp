#include <bits/stdc++.h>
#define endl '\n'
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ll x,y,a,b;

ll valid(ll n){
    ll l = 0,r = n;
    while(l != r){
        ll mid = l + (r - l + 1) / 2;
        if(mid * a + (n - mid) * b <= x && mid * b + (n - mid) * a <= y){
            return 1;
        }
        if(mid * a + (n - mid) * b > x)
            r = mid - 1;
        else
            l = mid;
    }
    return l * a + (n - l) * b <= x && l * b + (n - l) * a <= y;
}


int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    ll t;
    cin >> t;
    while(t--){
        cin >> x >> y >> a >> b;
        if(a < b)
            swap(a,b);
        ll l = 0,r = 1e9;
        while(l != r){
            ll mid = l + (r - l + 1) / 2;
            if(!valid(mid))
                r = mid - 1;
            else
                l = mid;
        }
        cout << l << endl;

    }


}