#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int dp[701][201][51];



int solve(int needed,int ones,int fives,int tens){
    if(!needed)
        return 0;
    
    int &ret = dp[ones][fives][tens];
    if(~ret)
        return ret;
    
    ret = 1e5;
    if(tens)
        ret = min(ret,1 + solve(needed - 1,ones + 2,fives,tens - 1));
    
    if(fives >= 2)
        ret = min(ret,2 + solve(needed - 1,ones + 2,fives - 2,tens));
    
    if(fives >= 1 && ones >= 3)
        ret = min(ret,4 + solve(needed - 1,ones - 3,fives - 1,tens));
    
    if(ones >= 8)
        ret = min(ret,8 + solve(needed - 1,ones - 8,fives,tens));
    
    if(tens && ones >= 3)
        ret = min(ret,4 + solve(needed - 1,ones - 3,fives + 1,tens - 1));



    return ret;

}




signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    int t;
    cin >> t;
    while(t--){
        memset(dp,-1,sizeof dp);
        int c,o,f,t;
        cin >> c >> o >> f >> t;
        cout << solve(c,o,f,t) << endl;
    }


}