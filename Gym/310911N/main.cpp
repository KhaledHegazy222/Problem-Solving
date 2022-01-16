
#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)


using namespace std;

bool srt(pair<ll,ll>a,pair<ll,ll>b){
    if(a.first != b.first){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    ll n,m,k;
    cin >> n >> m >> k;
    ll frog[m];
    for(int i = 0;i<m;i++){
        cin >> frog[i];
    }

    ll mos[k];
    for(int i = 0;i<k;i++){
        cin >> mos[i];
    }

    map<ll,ll>mp;
    vector<pair<ll,ll>>v;
    for(int i = 0;i<m;i++){
        int killed = 0;
        for(int j = 0;j<k;j++){
            if(mos[j] % frog[i] == 0){
                killed++;
            }
        }
        mp[killed]++;
        v.push_back({killed,i});
    }

    cout << mp.begin()->second << endl;
    sort(all(v),srt);
    int mn = v[0].first;
    int index = 0;
    while(index < m && v[index].first == mn){
        cout << v[index].second + 1 << " ";
        index++;
    }
}