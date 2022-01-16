#include <bits/stdc++.h>

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
    vector<string>st;
    int n;
    int mx = -1;
    while(cin >> n){
        string z = to_string(n);
        mx = max(mx,(int)z.size());
        st.push_back(z);
    }
    for(auto it : st){
        n = stoi(it);
        cout << right << setw(5) << n << " -> ";
        int res = 1;
        while(n--){
            res *= n+1;
            while(res % 10 == 0)
                res /= 10;
            res %= 100000;
        }
        cout << res % 10 << endl;
    }

}