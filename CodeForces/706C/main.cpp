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

struct {
    int ff,fb,bf,bb;
}res[N];



ll solve(int idx,int last){
    if(idx == n)
        return 0;
    ll &ret = dp[idx][last];
    if(~ret)
        return ret;
    
    ll ch1 = 1e16,ch2 = 1e16;
    if(idx){
        if(last){
            if(res[idx].fb)
                ch1 = solve(idx + 1,0);
            if(res[idx].bb)
                ch2 = v[idx] + solve(idx + 1,1);
        }
        else{
            if(res[idx].ff)
                ch1 = solve(idx + 1,0);
            if(res[idx].bf)
                ch2 = v[idx] + solve(idx + 1,1);
        }

        
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
    
    for(int i = 1;i<n;i++){
        string t1 = s[i];
        string t2 = s[i - 1];
        reverse(all(t1));
        reverse(all(t2));
        res[i].ff = s[i] >= s[i - 1];
        res[i].fb = s[i] >= t2;
        res[i].bf = t1 >= s[i - 1];
        res[i].bb = t1 >= t2;
    }
    cout << (solve(0,0) < 1e15 ? solve(0,0) : -1 ) << endl;
    
}



