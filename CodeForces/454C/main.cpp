
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define fast cin.tie(),ios::sync_with_stdio(0)
using namespace std;


typedef unsigned long long ull;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<vector<ll>> vvll;
typedef vector<ll> vll;



ll ncr(int n,int r){
    if(!r || n == r) return 1;
    return ncr(n-1,r) / (n-r) * n;

}

double power(double base,int p){
    double ret = 1;
    while(p > 0){
        if(p & 1)
            ret *= base;
        base *= base;
        p /= 2;
    }
    return ret;
}

double solve(int m,int n){
    double ttl = 0;
    for(int i = 1;i<=m;i++){
        double ways = 0;
        for(int j = 1;j<=n;j++){
            ways += ncr(n,j) * power(i - 1,n-j);
        }
        ttl += ways*i;
    }
    return ttl / power(m,n);
}


double solve2(int m,int n){
    double ttl = 0;
    double lst = 0;
    for(int i = 1;i<=m;i++){
        double p = power((double)i/m,n);
        double ways = p - lst;
        lst = p;
        ttl += (i*ways);
    }
    return ttl;
}


int main(void){
    fast;
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    int n,m;
    cin >> m >> n;
    cout << fixed << setprecision(9) << solve2(m,n);

}   