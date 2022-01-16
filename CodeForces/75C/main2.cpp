#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

vector<int>factors;

void factorize(int n){
    factors.push_back(1);
    if(n != 1){
        factors.push_back(n);
    }
    for(ll i = 2;i * i <= n;i++){
        if(n % i == 0){
            factors.push_back(i);
            if(n / i != i)
                factors.push_back(n / i);
        }
    }
    sort(all(factors));
}



int bs(int n){
    int l = 0,r = factors.size() - 1;
    while(l != r){
        int mid = l + (r - l + 1) / 2;
        if(factors[mid] > n){
            r = mid - 1;
        }
        else{
            l = mid;
        }
    }
    return factors[l];
}

int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    int a,b;
    cin >> a >> b;
    int g = __gcd(a,b);
    factorize(g);
    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        
        int idx = bs(r);
        if(idx >= l)
            cout << idx << endl;
        else

            cout << -1 << endl;
    }


}

//