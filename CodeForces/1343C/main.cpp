


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

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>v;
        for(int i = 0;i<n;i++){
            int a;
            cin >> a;
            if(i){
                if(a > 0 && v[v.size()-1] > 0 ){
                    v[v.size()-1] = max(a,v[v.size()-1]);
                }
                else if(a < 0 && v[v.size()-1] < 0){
                     v[v.size()-1] = max(a,v[v.size()-1]);
                }
                else{
                    v.push_back(a);
                }
            }
            else{
                v.push_back(a);
            }
        }
        ll sum = 0;
        for(int i =0;i<v.size();i++){
            sum += v[i];
        }
        cout << sum << endl;
        
    }


}