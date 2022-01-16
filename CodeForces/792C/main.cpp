#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 1e5 + 5;
string s;
int n;


int dp[N][3][2];


int solve(int idx,int mod,int c){
    if(idx == n)
        return (mod || !c) ? 1e6 + 5 : 0;

    int &ret = dp[idx][mod][c];
    if(~ret)
        return ret;


    int ch1 = 1 + solve(idx + 1,mod,c);
    int ch2 = 1e6 + 5;
    if(c || s[idx] != '0')
        ch2 = solve(idx + 1,(mod * 10 + s[idx] - '0' )% 3,1);
    return ret = min(ch1,ch2);
}


void build(int idx,int mod,int c){
    if(idx == n)
        return;
    
    int sol = solve(idx,mod,c);
    if(sol == 1 + solve(idx + 1,mod,c)){
        build(idx + 1,mod,c);
        return;
    }
    else{
        cout << s[idx];
        build(idx + 1,(mod * 10 + s[idx] - '0') % 3,1);
        return;
    }


}



signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    memset(dp,-1,sizeof dp);

    cin >> s;
    n = s.size();
    int sol = solve(0,0,0);
    if(find(all(s),'0') != s.end())
        sol = min(sol,(int)s.size() - 1);
    if(sol >= n)
        return puts("-1") * 0;
    if(sol == n - 1 && find(all(s),'0') != s.end())
        return puts("0") * 0;
    
    build(0,0,0);


}