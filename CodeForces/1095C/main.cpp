
#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

using namespace std;


int  main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif

    map<int,int,greater<int>>mp;
    int n,k;
    cin >> n >> k;
    if(n < k){
        cout << "NO\n";
    }
    else {
        ll factor = 1;
        while(n){
            if(n%2){
                mp[factor]++;
                k--;
            }
            n/=2;
            factor *= 2;
        }
        if(k < 0){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            while(k){
                auto it = mp.begin();
                mp[it->first/2]++;
                mp[it->first/2]++;
                if(it->second == 1){
                    mp.erase(it->first);
                }
                else{
                    mp[it->first]--;
                }
                k--;
            }
            for(auto it = mp.begin();it != mp.end();it++){
                for(int i = 0;i<it->second;i++){
                    cout << it->first << " ";
                }
            }
            cout << endl;
        }
    }







}