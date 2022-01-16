



#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

using namespace std;


bool cmp(pair<int,char>&a,pair<int,char>&b){
    return a.first > b.first;
}

int  main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif
  
    int n,r;
    cin >> n >> r;
    vector<pair<int,char>>v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i].first;
    }
    for(int i = 0;i<n;i++){
        cin >> v[i].second;
    }

    int index;
    for(int i = 0;i<n;){
        char c = v[i].second;
        index  = i;
        while(i<n && v[i].second == c){
            i++;
        }
        sort(v.begin()+index,v.begin() + i,cmp);
    }
    ll score = 0;
    for(int i = 0;i<n;){
        int taken = 0;
        int index = i;
        while(i < n && v[i].second == v[index].second){
            if(taken < r){
                score += v[i].first;
                taken++;
            }
            i++;
        }
    }

    cout << score << endl;


}