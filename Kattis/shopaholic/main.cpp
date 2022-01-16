

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

typedef unsigned long long ull;
typedef long long ll;

using namespace std;


int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    sort(all(v));

    ll ttl = 0;
    for(int i = v.size() - 3;i>=0;i-=3){
        ttl += v[i];
    }
    cout << ttl << endl;

}