#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
const int N = 1000 + 5;



string s;
int dp[N][N];



int solve(int i,int j){
    if(i >= j)
        return 0;
    
    int &ret = dp[i][j];
    if(~ret)
        return ret;

    if(s[i] == s[j])
        return ret = solve(i + 1,j - 1);

    int ch1 = 1 + solve(i + 1,j);
    int ch2 = 1 + solve(i, j - 1);
    int ch3 = 1 + solve(i + 1,j - 1);
    return ret = min({ch1,ch2,ch3});
}




signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    int cs = 1;
    int t;
    cin >> t;
    while(t--){
        memset(dp,-1,sizeof dp);
        cin >> s;
        cout << "Case " << cs++ << ": " <<  solve(0,s.size() - 1) << endl;
    }


}