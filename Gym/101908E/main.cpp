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

    string a;
    string b;
    cin >> a >> b;
    int cnt = 0;
    for(int i = 0;i<a.size() - b.size() + 1;i++){
        int valid = 1;
        for(int j = i;j < i + b.size();j++){
            if(a[j] == b[j - i]){
                valid = 0;
                break;
            }
        }
        cnt += valid;
    }
    cout << cnt << endl;

}