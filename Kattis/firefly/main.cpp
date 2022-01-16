
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

typedef unsigned long long ull;
typedef long long ll;

using namespace std;





int main(void){

    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);    
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 

    map<pair<int,int>,int>mp;
    int n,h;
    cin >> n >> h;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        if(i%2 == 1){
            mp[{x,1}]++;
        }
        else{
            mp[{x,0}]++;
        }
    }
    int min_cur = INT_MAX;
    int cur = n/2; 
    int level = 0;
    for(int i = 0;i<h;i++){
        if(mp[{i,1}]){
            cur -= mp[{i,1}];
        }
        if(mp[{h - i,0}]){
            cur += mp[{h - i,0}];
        }
        if(cur < min_cur){
            level = 1;
            min_cur = cur;
        }
        else if(cur == min_cur){
            level++;
        }
    }

    cout << min_cur << " " << level << endl;



}
