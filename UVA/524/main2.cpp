#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

vector<int>primes = {2,3,5,7,11,13,17,19,23,29,31};



vector<int>v = {1};
int n;

void solve(int idx){
    if(idx == n){
        int x = v.back() + 1;
        if(find(all(primes),x) != primes.end()){
            
            for(int i = 0;i<n;i++)
                cout << v[i] << " \n"[i + 1 == n];
        }
        return;
    }

    for(int i = 0;i<primes.size();i++){
        int x = primes[i] - v.back();
        if(x > 0 && x <= n && find(all(v),x) == v.end()){
            v.push_back(x);
            solve(idx + 1);
            v.pop_back();
        }
    }
}


signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    int cs = 1;
    while(cin >> n){
        if(cs != 1)
            cout << endl;
        cout << "Case " << cs++ << ":\n";
        solve(1);
    }

}