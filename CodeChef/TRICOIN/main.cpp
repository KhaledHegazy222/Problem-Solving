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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int l = 0,r = 1e5;
        while(l != r){
            int mid = l + (r - l + 1) / 2;
            if(1ll * mid * (mid + 1) / 2 <= n)
                l = mid;
            else
                r = mid - 1;
        }
        cout << l << endl;
    }    

}


