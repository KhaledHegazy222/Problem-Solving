

/*problem link: https://vjudge.net/problem/UVA-524*/

#include <bits/stdc++.h>
using namespace std;

#define space ' '
#define ll long long
#define ull unsigned long long
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define terminate return 0

void IO(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifdef ZAHER
    freopen ("../in.txt", "r", stdin);
    freopen ("../out.txt", "w", stdout);
#endif
}
const ll N = 1e5 + 1;
ll a[N], b[N];
ll n, k;

int can (ll mx) {
    ll kk = k;
    for (int i = 0; i < n; ++i) {
        if (a[i] * mx < b[i]) {
            continue;
        } else {
            if (kk >= a[i] * mx - b[i]) {
                kk -= a[i] * mx - b[i];
                continue;
            } else {
                return 0;
            }
        }
    }
    return 1;
}

ll bs () {
    ll l = 0, r = 2e9+5;
    ll ans;
    while (l < r) {
        ll mid = l + (r - l + 1) / 2;
        if (can(mid)) {
            l = mid;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

int main () {
    IO ();
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    ll mx = bs();
    cout << mx << endl;

    terminate;
}