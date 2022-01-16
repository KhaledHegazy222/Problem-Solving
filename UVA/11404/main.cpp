#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 1e3 + 5;
string s;

map<int,char>mp;

int dp[N][N];
string dp2[N][N];
int vis[N][N];


int solve(int i,int j){
    if(i > j)
        return 0;
    if(i == j)
        return 1;

    int &ret = dp[i][j];
    if(~ret)
        return ret;


    if(s[i] == s[j])
        return ret = 2 + solve(i + 1,j - 1);
    
    int ch1 = solve(i + 1,j);
    int ch2 = solve(i,j - 1);
    return ret = max(ch1,ch2);
}

string build(int i,int j){
    string &ret = dp2[i][j];
    if(vis[i][j])
        return ret;
    vis[i][j] = 1;
    ret = "";
    if(i > j){
        return ret;
    }
    if(i == j){
        // mp.insert({i,s[i]});
        ret = ret + s[i];
        return ret;
    }
    if(s[i] == s[j]){
        mp.insert({i,s[i]});
        mp.insert({j,s[j]});
        ret = build(i + 1,j - 1);
        string z = "";
        z = z + s[i];
        return ret = z + ret + z;
    }
    int ch1 = solve(i + 1,j);
    int ch2 = solve(i,j - 1);
    if(ch1 == ch2){
        string a = build(i + 1,j);
        string b = build(i,j - 1);
        if(a < b)
            return ret = a;
        return ret = b;
    }
    else if(solve(i,j) == ch1){
        return ret = build(i + 1,j);
    }
    else
        return ret = build(i,j - 1);
}



signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    while(cin >> s){
        memset(dp,-1,sizeof dp);
        memset(vis,0,sizeof vis);
        cout << build(0,s.size() - 1);
        cout << endl;
    }

}