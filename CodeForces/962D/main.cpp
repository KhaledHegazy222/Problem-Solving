

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

    map<ll,ll>freq;
    map<ll,ll>indx;
    vector<ll>v;
    v.push_back(0);
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++){
        ll x;
        cin >> x;
        check:
        if(freq[x]){
            freq[x]--;
            ll j = indx[x];
            v[indx[x]] = 0;
            x *= 2;
            if(freq[x]){
                goto check;
            }
            else{
                freq[x]++;
                indx[x] = v.size();                
                v.push_back(x);
            }
        }
        else{
            freq[x]++;
            indx[x] = v.size();
            v.push_back(x);
        }
    }

    ll cnt = 0;
    
    for(int i = 1;i<v.size();i++){
        if(v[i]){
            cnt++;
        }
    }
    cout << cnt <<endl;
    for(int i = 1;i<v.size();i++){
        if(v[i]){
            cout << v[i] << " ";
        }
    }
    cout << endl;



}

