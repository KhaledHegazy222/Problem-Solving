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

    string a,b;
    cin >> a >> b;
    string c;
    deque<int>v;
    if(a == b)
        return puts("0") * 0;
    for(int i = 0;i<max(b.size(),a.size());i++){
        int x = 0;
        if(i < a.size()){
            x = a[i] - '0';
        }
        int y = 0;
        if(i < b.size()){
            y = b[i] - '0';
        }
        v.push_back(abs(x - y));
    }
    int i = 0;
    while(!v.front()){
        v.pop_front();
    }
    for(auto it : v)
        cout << it;
    cout << endl;



}