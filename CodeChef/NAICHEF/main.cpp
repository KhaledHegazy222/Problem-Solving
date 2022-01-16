
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;


typedef unsigned long long ull;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<vector<ll>> vvll;
typedef vector<ll> vll;






int main(void){
   
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 


    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int faces[n];
        int a,b;
        cin >> a >> b;
        int a_cnt= 0;
        int b_cnt = 0;
        for(int i = 0;i<n;i++){
            cin >> faces[i];
            a_cnt += faces[i] == a;
            b_cnt += faces[i] == b;
        }

        cout << fixed << setprecision(9) << (double)a_cnt / n * (double)b_cnt / n << '\n';


    }
   

}   