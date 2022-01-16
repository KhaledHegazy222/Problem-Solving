#include <bits/stdc++.h>
#define endl '\n'
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


bool cmp(string &a,string &b){
    string c = a + b;
    string d = b + a;
    return c < d;
}


int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;


    int n;
    cin >> n;
    vector<string>v(n);
    for(int i = 0;i<n;i++)
        cin >> v[i];
    
    sort(all(v),cmp);
    for(auto it : v)
        cout << it;

    cout << endl;


}