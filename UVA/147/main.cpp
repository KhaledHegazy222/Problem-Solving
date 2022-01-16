
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;
const int N = 11;
int coins[N] = {5,10,20,50,100,200,500,1000,2000,5000,10000};

ll dp[N + 5][30000 + 5];

ll solve(int idx,int rem){
    if(idx == N)
        return !rem;
    
    ll &ret = dp[idx][rem];
    if(~ret) return ret;
    ret = 0;
    if(rem >= coins[idx])
        ret += solve(idx,rem - coins[idx]);
    ret += solve(idx + 1,rem);
    return ret;
}   

int main(void){

	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    fast;

    string s;
    vector<pair<string,ll>>res;
    int mx = 0;
    while(cin >> s){
        stringstream ss(s);
        int d,c;
        char _;
        ss >> d >> _ >> c;
        int val = d * 100 + c;
        if(!val) break;
        memset(dp,-1,sizeof dp);
        string z = to_string(val % 100);
        if(z.size() < 2)
            z = "0" + z;
        if(z.size() < 2)
            z = "0" + z;
        res.push_back({to_string(val / 100)  + "." + z,solve(0,val)});
        mx = max(mx,(int)res.back().first.size());
    }
    
    for(auto it : res){
        cout << right << setw(mx) << it.first;
        cout << right << setw(17) << it.second << '\n';
    }


}