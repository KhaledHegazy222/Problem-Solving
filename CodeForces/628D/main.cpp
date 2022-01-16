#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;



const int MOD = 1e9 + 7;
const int N = 2000 + 5;
int n,m,d;
string a,b;


int dp[N][N][2][2];


int solve(int idx,int rem,int bigger,int smaller){
    if(idx == n)
        return !rem;
    
    int &ret = dp[idx][rem][bigger][smaller];
    if(~ret)
        return ret;

    ret = 0;


    deque<int>chs(10);
    iota(all(chs),0);
    if(!bigger){
        while(chs.size() && chs.front() < a[idx] - '0')
            chs.pop_front();
    }
    if(!smaller){
        while(chs.size() && chs.back() > b[idx] - '0')
            chs.pop_back();
    }

    for(auto elem : chs){
        if(idx % 2){
            if(elem == d)
                ret = (0ll + ret + solve(idx + 1,(rem * 10 + elem) % m,bigger || elem > a[idx] - '0',smaller || elem < b[idx] - '0')) % MOD;
        }
        else{
            if(elem != d)
                ret = (0ll + ret + solve(idx + 1,(rem * 10 + elem) % m,bigger || elem > a[idx] - '0',smaller || elem < b[idx] - '0')) % MOD;
        }
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
    cin >> m >> d;
    cin >> a >> b;
    n = a.size();
    memset(dp,-1,sizeof dp);
    cout << solve(0,0,0,0) << endl;


}


