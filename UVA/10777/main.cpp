
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
   int cs = 1;
   while(t--){
        int n;
        cin >> n;            
        double top = 0;
        double bot = 1;            
        bool save = 0;
        while(n--){
            int x;
            cin >> x;
            double p;
            cin >> p;
            top += p * abs(x);
            if(x > 0){
                save = 1;
            }
            else{
                bot -= p;
            }
        }

        cout << "Case " << cs++ << ": ";
        if(save){
            cout << fixed << setprecision(2) << top / bot << '\n';
        } 
        else{
            cout << "God! Save me\n";
        }
    }
}   