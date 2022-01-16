#include <bits/stdc++.h>
#define endl '\n'
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    int n,m;
    while(cin >> n >> m,n,m){
        int sum = 0;
        vector<int>v(n);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++)
                cin >> v[i];
            sum += v[i];
        }
        for(int i = 0;i<n;i++){
            int g = __gcd(v[i],sum);
            cout << v[i] / g << " / " << sum / g << endl;
        }
    }


}