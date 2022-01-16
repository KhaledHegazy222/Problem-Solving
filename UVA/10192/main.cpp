#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 1e2 + 5;

string a,b;
int dp[N][N];

int solve(int i,int j){
    if(i == a.size() || j == b.size())  
        return 0;
    
    int &ret = dp[i][j];
    if(~ret)
        return ret;

    if(a[i] == b[j])
        return 1 + solve(i + 1,j + 1);


    int ch1 = solve(i + 1,j);
    int ch2 = solve(i,j + 1);   
    return ret = max(ch1,ch2);
}





signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    int cs = 1;

    while(1){
        getline(cin,a);
        if(a == "#")
            return 0;
        getline(cin,b);
        memset(dp,-1,sizeof dp);
        cout << "Case #" << cs++ << ": you can visit at most " << solve(0,0) << " cities." << endl;

    }    

}