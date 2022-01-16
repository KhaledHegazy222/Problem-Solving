

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
        int arr[n];
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }        
        map<int,int,greater<int>>freq;
        for(int i = 0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                freq[arr[i] + arr[j]]++;
            }
        }
        cout << fixed << setprecision(9) << freq.begin()->second * 1ll / ( n* (n-1) / 2.0 ) << endl;
    

    }

}   