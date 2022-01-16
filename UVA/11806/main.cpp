#include <bits/stdc++.h>
#define endl '\n'
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
const int K = 500 + 2;
const int MOD = 1000007;



int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    ll ncr[K][K];
    memset(ncr,0,sizeof ncr);

    for(int i = 0;i<K;i++)
        ncr[i][0] = 1;
    for(int i = 1;i<K;i++){
        for(int j = 1;j<=i;j++){
            ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1]) % MOD;
        }
    }

    int cs = 1;
    int t;
    cin >> t;
    while(t--){
        int n,m,k;
        cin >> n >> m >> k;
        ll ans = 0;
        for(int i = 0;i<(1 << 4);i++){
            int r = n,c = m;
            if(i & 1)
                r--;
            if(i & 2)
                r--;
            if(i & 4)
                c--;
            if(i & 8)
                c--;

            ans += __builtin_popcount(i) % 2 ? -ncr[r * c][k] : ncr[r * c][k];
            ans = (ans + MOD) % MOD; 
        }
        cout << "Case " << cs++ << ": " << ans << endl;
    }


}