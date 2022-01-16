#include <bits/stdc++.h> 
#define FIO cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define inf 0x3f3f3f3f
#define endl '\n'
#define EFS 1e-7 
 
typedef long long ll; 
 
using namespace std; 
 
const int N = 2e3 + 5;
double dp[N][N];
double p;
double solve(int num,int tim){
    dp[0][0] = 1.0;
    for(int i = 0;i<=num;i++){
        for(int j = 0;j<=tim;j++){
            dp[i][j + 1] += (1.0 - p) * dp[i][j];
            dp[min(num,i + 1)][j + 1] += p * dp[i][j];
        }
    }
    return dp[num][tim];
}

 
int main(){ 
    #ifdef VS_freOpen 
       freopen("input.in", "r", stdin); 
    #endif 
//    freopen("Q.in", "r", stdin); 
 
    FIO; 
/// 
    int n,t;
    cin >> n >> p >> t;
    double res = 0;
    solve(n,t);
    for(int i = 0 ;i<=n;i++){
        res += dp[i][t] * i;
    }
    cout << fixed << setprecision(6) <<  res << endl;

    

    #ifdef rerun 
        goto y; 
    #endif // rerun 
 
   return 0; 
} 
 
/* 
 
*/