#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 1e3 + 5;


vector<int> factorize(int n){
    vector<int>ret(N);
    for(int i = 2;1ll * i * i <= n;i++){
        while(!(n % i)){
            ret[i]++;
            n /= i;
        }
    }
    if(n != 1)
        ret[n]++;
    return ret;
}


signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    int cs = 1;
    int t;
    cin >> t;
    while(t--){
        cout << "Case " << cs++ << ": ";
        string s;
        cin >> s;
        int lvl = count(all(s),'!');
        s.erase(s.find('!') + s.begin(),s.end());
        int n = stoi(s);
        int res[N] = {0};
        for(int i = n;i>=0;i -= lvl){
            vector<int>v = factorize(i);
            for(int i = 0;i<N;i++){
                res[i] += v[i];
            }
        }
        double sol = 1;
        ll soll = 1;
        for(int i = 1;i<N;i++){
            sol *= res[i] + 1;
            soll *= res[i] + 1;
        }
        if(abs(sol - 1e18) > 1e-3 && sol > 1e18){
            cout << "Infinity\n";
        }
        else{
            cout << soll << endl;
        }
    }


}