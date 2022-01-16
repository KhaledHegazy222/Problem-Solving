
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

    int t;
    cin >> t;
    int cs = 1;
    while(t--){
        int n;
        cin >> n;
        vector<int>a(n);
        vector<int>b(n);
        for(int i = 0;i<n;i++){
            cin >> a[i];
        }
        for(int i = 0;i<n;i++){
            cin >> b[i];
        }
        sort(all(a));
        sort(all(b),greater<int>());
        ll res = 0;
        for(int i = 0;i<n;i++){
            res +=  1ll * a[i] * b[i];
        }
        cout << "Case #" << cs++ << ": " << res << endl;
        
    }


}