

#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

using namespace std;


bool srt(pair<int,int>a,pair<int,int>b){
    return a.first > b.first;
}


int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>>v(n);

        // first restaurant
        // second me

        for(int i = 0;i<n;i++){
            cin >> v[i].first; // res
        }
        for(int i = 0;i<n;i++){
            cin >> v[i].second; // me
        }

        int pen = 0;
        int res = 0;
        for(int i = 0;i<n;i++){
            if(v[i].first <= v[i].second){
                res = max(res,v[i].first);
                v[i].first = 0;
                v[i].second = 0;
            }
        }
        sort(all(v),srt);
        int max_x = 0;
        int i = 0;
        while(i<n && pen + v[i].second <= v[i].first){
            pen += v[i].second;
            i++;
        }       
        if(i<n){
            max_x = v[i].first;
        } 

        cout << max(max_x,max(pen,res)) << endl;
    }

}

