
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


    map<int,int>mp;
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        mp[x]++;
    }
    vector<pair<int,int>>v;
    for(auto it = mp.begin();it != mp.end(); it++){
        v.push_back({it->first,it->second});
    }


    vector<ll>powers;
    powers.push_back(1);
    for(int i = 0;i<50;i++){
        powers.push_back(powers[powers.size() - 1] * 2);
    }
    ll pairs = 0;
    for(int i = 0;i<powers.size();i++){
        ll f = powers[i];
        int l = 0;
        int r = v.size() - 1;
        while(l <= r){
            ll sum = v[l].first + v[r].first;
            if(sum == f){
                if(l == r){
                    pairs += v[l].second * 1ll * (v[l].second - 1)  / 2;
                }
                else{
                    pairs += v[l].second * 1ll * v[r].second;
                }
                l++;
                r--;
            }
            else if(sum > f){
                r--;
            }
            else{
                l++;
            }
        }
    }


    cout << pairs << endl;
    




}