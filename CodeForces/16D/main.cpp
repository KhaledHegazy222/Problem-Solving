#include <bits/stdc++.h>
#define endl '\n'
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    int n;
    cin >> n;
    cin.ignore();
    vector<pair<int,int>>v;
    for(int i = 0;i<n;i++){
        string line;
        getline(cin,line);
        int h = stoi(line.substr(1,2));
        int m = stoi(line.substr(4,2));
        if(line[7] == 'p')
            h += 12;
        if(h == 12)
            h = 0;
        else if(h == 24)
            h = 12;
        v.push_back({h,m});
    }
    int i = 0;
    pair<int,int>lst = {-1,-1};
    map<pair<int,int>,int>frq;
    int days = 1;
    while(i < n){
        if(v[i] < lst){
            days++;
            lst = v[i];
            frq.clear();
            frq[v[i]]++;
        }
        else{   
            if(frq[v[i]] <= 9){
                frq[v[i]]++;
                lst = v[i];
            }
            else{
                frq.clear();
                frq[v[i]]++;
                days++;
                lst = v[i];
            }

        }
        i++;
    }
    cout << days << endl;



}