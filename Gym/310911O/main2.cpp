

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
    int n;
    cin >> n;
    vector<pair<int,int>>v;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        if(v.empty() || v[v.size()-1].first != x){
            v.push_back({x,1});
        }
        else{
            v[v.size()-1].second++;
        }
    }
    int index = 0;
    n = v.size();
    if(v[0].first == 1){
        index++;
    }
    while(index < n){
        if(index > 0){
            if(v[index-1].first + v[index].first == 2){
                cout << "No\n";
                return 0;
            }
        }
        if(index-1 >= 0 && index +1<n ){
            if(v[index].first == 1){
                if(v[index].second % 2 == 0){
                    if(v[index-1].first != v[index+1].first){
                        cout << "No\n";               
                        return 0;
                    }
                }
                else{
                    if(v[index-1].first == v[index+1].first){
                        cout << "No\n";                
                        return 0;
                    }
                }
            }
        }
        index++;
    }

    cout << "Yes\n";






}
