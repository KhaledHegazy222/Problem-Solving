#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
const int N = 1e5 + 5;

vector<string>s(N);
vector<int>v(N);
int n;
ll dp[N][2];



ll solve(int idx,int last){
    if(idx == n)
        return 0;
    ll &ret = dp[idx][last];
    if(~ret)
        return ret;
    
    ll ch1 = 1e15,ch2 = 1e15;
    if(idx){
        string t = s[idx - 1];
        if(last)
            reverse(all(t));
        if(s[idx] >= t)
            ch1 = solve(idx + 1,0);
        string t2 = s[idx];
        reverse(all(t2));
        if(t2 >= t)
            ch2 = v[idx] + solve(idx + 1,1);
        
    }
    else{
        ch1 = solve(idx + 1,0);
        ch2 = v[idx] + solve(idx + 1,1);
    }
    return ret = min(ch1,ch2);
}

signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    memset(dp,-1,sizeof dp);
    cin >> n;
    for(int i = 0;i<n;i++)
        cin >> v[i];
    for(int i = 0;i<n;i++)
        cin >> s[i];
    
    cout << (solve(0,0) < 1e14 ? solve(0,0) : -1 ) << endl;
    
}