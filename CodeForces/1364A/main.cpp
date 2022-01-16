
#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)
 
 
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
    while(t--){
        int n,x;
        cin >> n >> x;
        vector<int>v(n);
        int sum = 0;
        bool f = false;
        for(int i = 0;i<n;i++){
            cin >> v[i];
            v[i] %= x;
            if(v[i]){
                f = true;
            }
            sum += v[i];
            sum %= x;
        }
        if(sum != 0){
            cout << n << endl;
        }
        else if(!f){
            cout << -1 << endl;
        }
        else{
            int i = 0;
            int j = n-1;
            while(i < v.size() && v[i] == 0){
                i++;
            }
            int right =n - i - 1; 
            while(j >= 0 && v[j] == 0){
                j--;
            }
            int left = j;

            cout << max(left,right) << endl;


        }
        
    }



}

