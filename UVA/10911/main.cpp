#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 16;
int n;
vector<pair<int,int>>cor;

double dist(pair<int,int>a,pair<int,int>b){
    return hypot(abs(a.first - b.first),abs(a.second - b.second));
}

double dp[1 << N];


double solve(int mask){
    if((mask + 1) == (1 << n))
        return 0;
    double &ret = dp[mask];
    if(ret == ret)
        return ret;
    ret = 1.0 / 0;
    for(int i = 0;i < n;i++){
        if(!((mask >> i) & 1)){
            for(int j = i + 1;j < n;j++){
                if(!((mask >> j) & 1))
                    ret = min(ret,dist(cor[i],cor[j]) + solve(mask | (1 << i) | (1 << j)));
            }
        }
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
    int cs = 1;
    while(cin >> n,n){
        memset(dp,-1,sizeof dp);
        n <<= 1;
        cor.resize(n);
        string _;
        for(int i = 0;i < n;i++)
            cin >> _ >> cor[i].first >> cor[i].second;
        cout << "Case " << cs++ << ": ";
        cout << fixed << setprecision(2) << solve(0) << endl;
    }    

}


