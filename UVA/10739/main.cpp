#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

string s;

const int N = 1e3 + 5;
int dp[N][N];

int solve(int st,int en){
    if(st >= en) return 0;

    int &ret = dp[st][en];
    if(~ret) return ret;

    if(s[st] == s[en])
        return solve(st + 1,en - 1);
    int ch1 = 1 + solve(st + 1,en);
    int ch2 = 1 + solve(st,en - 1);
    int ch3 = 1 + solve(st + 1,en - 1);
    return ret = min({ch1,ch2,ch3});
}






int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    int cs = 1;
    while(t--){
        memset(dp,-1,sizeof dp);
        cin >> s;
        cout << "Case " << cs++ << ": " << solve(0,s.size() - 1) << '\n';
    }
}