#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


vector<int> factorize(int n){
    vector<int>ret;
    for(ll i = 2;i * i <= n;i++){
        while(n % i == 0){
            ret.push_back(i);
            n /= i;
        }
    }
    if(n != 1)
        ret.push_back(n);
    return ret;
} 




int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    int n;
    while(cin >> n,n){
        if(n == 1){
            cout << "1 = 1\n";
            continue;
        }
        else if(n == -1){
            cout << "-1 = -1\n";
            continue;
        }
        cout << n << " = "; 
        int sign = n < 0;
        n = sign ? -n : n;
        vector<int>res = factorize(n);
        if(sign){
            cout << "-1 ";
        }
        for(int i = 0;i<res.size();i++){
            if(i){
                cout << " x " << res[i];
            }
            else{
                if(sign)
                    cout << "x ";
                cout << res[i];
            }
        }
        cout << endl;
    
    }

}