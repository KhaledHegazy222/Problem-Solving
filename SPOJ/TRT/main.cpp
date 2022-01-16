#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n;
const int N = 2000 + 5;
int A[N];

int dp[N][N];

int solve(int st,int en){
    if(st > en)
        return 0;
    int &ret = dp[st][en];
    if(~ret)
        return ret;
    int day = n - (en - st);
    int ch1 = solve(st + 1,en) + A[st] * day;
    int ch2 = solve(st,en -1) + A[en] * day;
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
    memset(dp,-1,sizeof dp);
    cin >> n;  
    for(int i = 0;i < n;i++)
        cin >> A[i];
    cout << solve(0,n - 1) << endl;

    

}


