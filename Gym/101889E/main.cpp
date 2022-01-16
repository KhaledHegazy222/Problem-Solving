#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

string s;
int n;

int power(int b,int p){
    int ret = 1;
    while(p){
        if(p & 1){
            ret = (ret * b) % n;
        }
        b = (b * b) % n;
        p >>= 1; 
    }
    return ret;
}


int dp[1002][1002];

int solve(int idx,int mod){
    if(idx == s.size())
        return !mod;
    
    int &ret = dp[idx][mod];
    if(~ret)
        return ret;

    if(s[idx] != '?'){
        int x = ((s[idx] -'0') * power(10,s.size() - idx - 1) ) % n;
        return solve(idx + 1,(mod + x) % n );
    }
    ret = 0;
    for(int i = !idx;i<10 && !ret;i++){
        int x = (i * power(10,s.size() - idx - 1) ) % n;
        ret |= solve(idx + 1,(mod + x) % n);
    }
    return ret;
}

void build(int idx,int mod){
    if(idx == s.size())
        return;
    
    if(s[idx] != '?'){
        cout << s[idx];
        int x = ((s[idx] -'0') * power(10,s.size() - idx - 1) ) % n;
        build(idx + 1,(mod + x) % n );
        return;
    }
    int ret = 0;
    for(int i = !idx;i<10;i++){
        int x = (i * power(10,s.size() - idx - 1) ) % n;
        ret |= solve(idx + 1,(mod + x) % n);
        if(ret){
            cout << i;
            build(idx + 1,(mod + x) % n);
            return;
        }
    }
    return;
}


signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    memset(dp,-1,sizeof dp);
    cin >> s >> n;
    if(solve(0,0)){
        build(0,0);
    }
    else
        cout << "*\n";

}