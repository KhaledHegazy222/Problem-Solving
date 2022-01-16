

#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)


using namespace std;


ll m,a,r,c,h;
int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif
    int n;
    cin >> n;
    ll ways = 0;
    while(n--){
        string s;
        cin >> s;
        if(s[0] == 'M') m++;
        if(s[0] == 'A') a++;
        if(s[0] == 'R') r++;
        if(s[0] == 'C') c++;
        if(s[0] == 'H') h++;
    }
    ll arr[5] = {m,a,r,c,h};
    for(int i = 0;i<5;i++){
        for(int j = i+1;j<5;j++){
            for(int k = j+1;k<5;k++){
                ways += arr[i] * arr[j] * arr[k];
            }
        }
    }

    cout << ways << endl;
}


