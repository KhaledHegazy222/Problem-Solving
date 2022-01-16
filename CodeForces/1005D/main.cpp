#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


const int N = 2e5 + 5;
string s;

int dp[N][3][3];


int solve(int idx,int rem,int last){
    if(idx == s.size())
        return 0;
    int &ret = dp[idx][rem][last];
    if(~ret)
        return ret;
    int ch1 = 0;
    int _ = (rem * 10 + (s[idx] - '0')) % 3 == 0;
    if(last != 2)
        ch1 = _ + solve(idx + 1,0,0);

    int ch2 = 0;
    if(last != 2){
        ch2 = solve(idx + 1,(rem * 10 + s[idx] - '0') % 3,s[idx] == '0' ? 2 : 1);
    }
    return ret = max(ch1,ch2);
    
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
    cin >> s;
    memset(dp,-1,sizeof dp);
    cout << solve(0,0,0) << endl;

}


