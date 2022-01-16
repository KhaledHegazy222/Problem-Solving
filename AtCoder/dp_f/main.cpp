#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


const int N = 3e3 + 5;

string s,t;

int dp[N][N];

int solve(int i,int j){
    if(i == s.size() || j == t.size())
        return 0;

    int &ret = dp[i][j];
    if(~ret)
        return ret;
    if(s[i] == t[j])
        return ret = 1 + solve(i + 1,j + 1);
    int ch1 = solve(i + 1,j);
    int ch2 = solve(i,j + 1);
    return ret = max(ch1,ch2);
}



void build(int i,int j){
    if(i == s.size() || j == t.size())
        return;
    if(s[i] == t[j]){
        cout << s[i];
        build(i + 1,j + 1);
        return;
    }
    int ch1 = solve(i + 1,j);
    int ch2 = solve(i,j + 1);
    if(ch1 == solve(i,j))
        build(i + 1,j);
    else
        build(i,j + 1);

}





signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    memset(dp,-1,sizeof dp);
    cin >> s >> t;
    build(0,0);
    cout << endl;



}