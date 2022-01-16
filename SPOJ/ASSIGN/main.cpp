#include <bits/stdc++.h>
#define endl '\n'
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 20 + 1;
int arr[N][N],n;
ll dp[N][(1 << N)];

ll solve(int idx,int mask){
    if(idx == n)
        return 1;

    ll &res = dp[idx][mask];
    if(~res)
        return res;
    res = 0;
    for(int i = 0;i<n;i++){
        if(arr[idx][i] && !((mask >> i) & 1)){
            res += solve(idx + 1,mask | (1 << i));
        }
    }
    return res;
}



int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;


    int t;
    cin >> t;
    while(t--){
        memset(dp,-1,sizeof dp);
        cin >> n;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cin >> arr[i][j];
            }
        }
        cout << solve(0,0) << endl;
    }



}