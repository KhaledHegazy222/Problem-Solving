#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


ll n;
vector<ll>devisors;

ll lcm(ll a,ll b){
    return a / __gcd(a,b) * b;
}


ll inc_exec(int idx = 0,ll d = 1,int sign = -1){
    if(idx == devisors.size()){
        if(d == 1)
            return 0;
        return sign * n / d;
    }
    return inc_exec(idx + 1,lcm(d,devisors[idx]),sign * -1) + inc_exec(idx + 1,d,sign);
}



int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    int m;
    cin >> n >> m;
    devisors.resize(m);
    for(int i = 0;i<m;i++)
        cin >> devisors[i];
    if(find(all(devisors),1) != devisors.end())
        cout << 0 << endl;
    else
        cout << n - inc_exec() << endl;





}