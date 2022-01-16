#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 200 + 5;

int n,l;
double prob[N];
int arr[N];
double dp[N][N * 2 + 11][N];

double solve(int idx,int rem,int wins){
    if(idx == n)
        return wins >= l && rem >= 0;
    double &ret = dp[idx][rem + N][wins];
    if(ret == ret)
        return ret;
    double ch1 = prob[idx] * solve(idx + 1,min(N,rem + arr[idx]),wins + 1);
    double ch2 = (1.0 - prob[idx]) * solve(idx + 1,rem,wins);
    return ret = ch1 + ch2;
}



signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;




    int k;
    cin >> n >> l >> k;


    for(int i = 0;i < n;i++){
        cin >> prob[i];
        prob[i] /= 100;
    }

    for(int i = 0;i < n;i++)
        cin >> arr[i];

    memset(dp,-1,sizeof dp);
    cout << fixed << setprecision(7) << solve(0,k,0) << endl;


    

}



