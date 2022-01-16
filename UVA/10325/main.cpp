#include <bits/stdc++.h>
#define endl '\n'
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
const ll M = 15;
vector<ll>nums(M);
ll n,m;

long long lcm(ll a,ll b){
    return 1ll * a / __gcd(a,b) * b;
}

ll solve(ll idx,ll d,ll sign = -1){
    if(idx == m){
        return (d == 1 ? 0 : sign * n / d);
    }
    return solve(idx + 1,lcm(nums[idx],d),sign * -1) + solve(idx + 1,d,sign); 
}



signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    while(cin >> n >> m){
        for(ll i = 0;i<m;i++)
            cin >> nums[i];
        cout << n - solve(0,1) << endl;
    }

}