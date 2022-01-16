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
    cin >> n >> m;
    int on[m] = {0};
    vector<vector<int>>v(n);

    int l;
    cin >> l;
    while(l--){
        int x;
        cin >> x;
        on[--x] = 1;
    }
    for(int i = 0;i<n;i++){
        int k;
        cin >> k;
        while(k--){
            int x;
            cin >> x;
            v[i].push_back(--x);
        }
    }
    int cnt = accumulate(on,on + m,0);
    int res = 0;
    int t = 1e3;
    while(t--){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<v[i].size();j++){
                if(on[v[i][j]]){
                    cnt--;
                }
                else{
                    cnt++;
                }
                on[v[i][j]] ^= 1;
            }
            res++;
            if(!cnt){
                t = 0;
                break;
            }
        }
    }
    if(!cnt){
        cout << res << endl;
    }
    else{
        cout << -1 << endl;
    }
}