#include <bits/stdc++.h>
#define endl '\n'
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 18 + 1;
double prob[N][N];
int n;
double dp[1 << N];

double solve(int mask){
    if(mask + 1 == (1 << n))
        return 1;
    
    double &ret = dp[mask];
    if(ret == ret)
        return ret;
    ret = 0;

    double cnt = 0;
    for(int i = 0;i<n;i++)
        if((mask >> i )& 1)
            cnt++;


    for(int i = 0;i<n;i++){
        if (mask & (1 << i)) {
            for(int j = 0;j<n;j++){
                if((mask >> j) & 1) 
                    continue;
                ret +=  prob[i][j] * solve(mask | (1 << j)) / (cnt * (cnt + 1) / 2);
            }
        }
    }
    return ret;
}

int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    memset(dp,-1,sizeof dp);
	cin >>n;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cin >> prob[i][j];
		}	           
	}
    cout << fixed << setprecision(9);
	for(int i = 0;i<n;i++){
		cout << solve(1 << i) << " \n"[i + 1 == n];	
	}	           


}