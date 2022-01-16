#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int MOD = 1e9 + 7;

const int N = 1e4 + 5;
int d;
string s;


int dp[N][100][2];



int solve(int idx,int rem,int smaller){

    if(idx == s.size())
        return !rem;
    

    int &ret = dp[idx][rem][smaller];
    if(~ret)
        return ret;
    ret = 0;



    deque<int>dq(10);
    iota(all(dq),0);
    if(!smaller){
        while(dq.size() && dq.back() > s[idx] - '0')
            dq.pop_back();
    }


    for(auto elem : dq){
        ret = (0ll + ret + solve(idx + 1,(rem + elem) % d,smaller || elem < s[idx] - '0')) % MOD;
    }
    return ret;


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
    memset(dp,-1,sizeof dp);
    cin >> s >> d;
    cout << (solve(0,0,0) - 1 + MOD) % MOD << endl;

}


