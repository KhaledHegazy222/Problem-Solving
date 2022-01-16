#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 50 + 2;
int nc;
int c[N];
int dp[N][N];


int solve(int st,int en,int cst,int cen){
    if(cst > cen)
        return 0;
    int &ret = dp[cst][cen];
    if(~ret) return ret;
    ret = 1e9;
    for(int i = cst;i <= cen;i++){
        ret = min(ret,solve(st,c[i]-1,cst,i-1) + solve(c[i],en,i + 1,cen) + en - st + 1);
    }
    return ret;
}

int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif

    int n,l;
    while(1){

        cin >> l;
        if(!l)
            return 0;
        cin >> n;
        nc = 0;
        memset(dp,-1,sizeof dp);
        for(int i = 0;i<n;i++){
            cin >> c[nc++];
        }
        int res = solve(0,l-1,0,nc-1);
        cout << "The minimum cutting is " << res << ".\n";
        
    }

}