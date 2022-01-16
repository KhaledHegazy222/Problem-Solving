

#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)


using namespace std;



bool srt_b(pair<int,int>&a,pair<int,int>&b){
    return 1ll * a.first > 1ll *b.first;
}
bool srt_s(pair<int,int>&a,pair<int,int>&b){
    return 1ll * a.first < 1ll *b.first;
}

bool decrease(pair<int,int>&a,pair<int,int>&b){
    return a.first > b.first;
}

int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    int n,s;
    cin >> n >> s;
    map<int,int>buy,sell;
    for(int i = 0;i<n;i++){
        char c;
        int p,q;
        cin >> c >> p >> q;
        if(c == 'S'){
            sell[p] += q;
        }
        else{
            buy[p] += q;
        }
    }

    vector<pair<int,int>>v_b,v_s;
    for(auto it = buy.begin(); it != buy.end();it++){
        v_b.push_back(*it);
    }
    for(auto it = sell.begin(); it != sell.end(); it++){
        v_s.push_back(*it);
    }

    sort(all(v_s),srt_s);
    int x = min(s,(int)v_s.size());
    sort(v_s.begin(),v_s.begin()+x,decrease);

    sort(all(v_b),srt_b);
    x = min(s,(int)v_s.size());
    sort(v_s.begin(),v_s.begin()+x,decrease);

    for(int i = 0;i<s && i < v_s.size();i++){
        cout << "S " << v_s[i].first << " " << v_s[i].second << endl;
    }

    for(int i = 0;i<s && i < v_b.size();i++){
        cout << "B " << v_b[i].first << " " << v_b[i].second << endl;
    }







}

