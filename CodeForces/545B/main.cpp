

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


    string s,t;
    cin >> s >> t;
    int n = s.length();
    int dif = 0;
    for(int i = 0;i<n;i++){
        if(s[i] != t[i]){
            dif++;
        }
    }

    if(dif % 2){
        cout << "impossible\n";
    }
    else{
        for(int i = 0;i<n;i++){
            if(s[i] == t[i]){
                cout << s[i];
            }
            else if(dif%2){
                cout << s[i];
                dif--;
            }
            else{
                cout << t[i];
                dif--;
            }
        }
        cout << endl;
    }

}