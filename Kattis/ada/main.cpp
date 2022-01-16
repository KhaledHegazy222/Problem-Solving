
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define fast cin.tie(),ios::sync_with_stdio(0)
using namespace std;


typedef unsigned long long ull;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<vector<ll>> vvll;
typedef vector<ll> vll;

int d;


int id(vector<int> &x){
    for(int i = 1;i<x.size();i++){
        if(x[i] != x[i-1])  return 0;
    }
    return 1;
}

void solve(vvi& x,int m){
    while(x.back().size() > 1){
        if(!id(x.back())) d++;
        vi p;
        for(int i = 0;i<x.back().size()-1;i++){
            p.push_back(x.back()[i+1] - x.back()[i]);
        }
        x.push_back(p);
    }
    x.back().resize(m+1,x.back().back());
    for(int i = x.size()-1,k = 1;i>0;i--,k++){
        for(int j = 0;j<m;j++){
            x[i-1].push_back(x[i][j+k] + x[i-1][j+k]);
        }
    }
}




int main(void){
    fast;
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 

    int s,c = 1;
    cin >> s;
    vvi x;
    vi p;
    for(int i = 0;i<s;i++){
        int x;
        cin >> x;
        p.push_back(x);
    }
    x.push_back(p);
    solve(x,c);
    cout << d << ' ';   
    for(int i = s;i<x[0].size();i++){
        cout << x[0][i] << ' ';
    }
    cout << '\n';



    

}   