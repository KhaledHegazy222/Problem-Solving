
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
    multiset<int>st;
    vector<pair<int,int>>v;
    

    while(n--){
        string s;
        cin >> s;
        if(s == "insert"){
            int x;
            cin >> x;
            st.insert(x);
            v.push_back({1,x});
        }
        else if(s == "getMin"){
            int x;
            cin >> x;
            if(!st.empty() && *st.begin() == x){
                v.push_back({2,x});
            }
            else{
                while(!st.empty() && *st.begin() < x){
                    v.push_back({3,0});
                    st.erase(st.begin());
                }
                if(!st.empty() && *st.begin() == x){
                    v.push_back({2,x});
                }
                else {
                    st.insert(x);
                    v.push_back({1,x});
                    v.push_back({2,x});
                }
            }
        }
        else{
            if(st.size()){
                st.erase(st.begin());
                v.push_back({3,0});
            
            }
            else{
                st.insert(-1e9);
                v.push_back({1,1e-9});
                
                st.erase(st.begin());
                v.push_back({3,0});
            }
        }
    }

    cout << v.size() << endl;
    for(int i = 0;i < v.size() ;i++){
        if(v[i].first == 1){
            cout << "insert " << v[i].second << endl; 
        }
        else if(v[i].first == 2){
            cout << "getMin " << v[i].second << endl;
        }
        else{
            cout << "removeMin\n";
        }
    }




}

