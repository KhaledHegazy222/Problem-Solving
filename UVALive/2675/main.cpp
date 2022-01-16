
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;

const int N = 1e2 + 5;
int n,cnt[N],price[N];


ll dp[N][N];


ll solve(int curIdx,int lastIdx){
    // base case
    if(curIdx == n)
        return 0;


    ll &ret = dp[curIdx][lastIdx];
    if(~ret) return ret;
    ret = 0;
    for(int i = lastIdx;i<=curIdx;i++){
        ret += cnt[i];
    }
    ret = (ret + 10) * price[curIdx] + solve(curIdx + 1,curIdx + 1);

    if(curIdx != n - 1)
        ret = min(ret,solve(curIdx + 1,lastIdx));
    return ret;
}



int main(void){

	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    fast;


    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0;i<n;i++){
            cin >> cnt[i] >> price[i];
        }
        memset(dp,-1,sizeof dp);
        cout << solve(0,0) << endl;
    }


}