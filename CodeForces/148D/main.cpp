#include <bits/stdc++.h>
#define endl '\n'
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


const int N = 1e3 + 5;
double dp[N][N][2];



double solve(int b,int w,int p){
    if(!w || b < 0)
        return 0;
    if(!b)
        return !p;
    
    double &ret = dp[b][w][p];
    if(ret == ret)
        return ret;


    if(!p){
        double pw = (w * 1.0) / (w + b);
        double ch1 =  pw;
        double ch2 = (1 - pw) * solve(b-1,w,!p);
        return ret = ch1 + ch2;
    }
    else{
        double pb = (b * 1.0) / (w + b);
        double pbb;
        pbb = ((b-1) * 1.0) / (w + b - 1);
        
        ret = pb * (pbb * solve(b-2,w,!p) + (1.0 - pbb) * solve(b-1,w-1,!p));
        return ret;
    }

}


int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    memset(dp,-1,sizeof dp);
    int b,w;
    cin >> w >> b;
    cout << fixed << setprecision(9) << solve(b,w,0) << endl;


}