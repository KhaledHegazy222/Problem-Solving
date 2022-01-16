

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()


typedef unsigned long long ull;
typedef long long ll;
using namespace std;



multiset<double>pass;
int x;

double prob(void){
    double res = 0;
    int tries = x;
    auto it = pass.begin();
    while(it != pass.end()){
        res += tries * (*it);
        it++;
        tries--;
    }
    return res;
}


int main(void){
   
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 

    int t;
    cin >> t;
    x = t;
    while(t--){
        string s;
        cin >> s;
        double d;
        cin >> d;
        pass.insert(d);
    }
    cout << fixed << setprecision(4) << prob() << '\n';

}   