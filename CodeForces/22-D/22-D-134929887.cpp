#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 1e3 + 5;

vector<pair<int,int>>seg;



signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    #ifndef Khaled
        #define endl '\n'
        fast;
    #endif
    int n;
    cin >> n;    

    seg.resize(n);
    for(auto &elem : seg){
        cin >> elem.first >> elem.second;
        if(elem.first > elem.second)
            swap(elem.first,elem.second);
    }

    sort(all(seg),[](pair<int,int>&a,pair<int,int> &b){
        return a.second < b.second;
    });

    vector<int>pos;
    vector<int>nailed(n);
    for(int i = 0;i<n;i++){
        if(nailed[i])   
            continue;
        else{
            pos.push_back(seg[i].second);
            for(int j = 0;j<n;j++){
                nailed[j] |= (seg[i].second >= seg[j].first && seg[i].second <= seg[j].second);
            }
        }
            
    }
    cout << pos.size() << endl;
    for(auto elem : pos)
        cout << elem << " ";
    cout << endl;

}