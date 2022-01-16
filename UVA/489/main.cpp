// #include <bits/stdc++.h>
// #define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
// #define all(a) a.begin(),a.end()

// typedef long long ll;
// typedef unsigned long long ull;

// using namespace std;

// ll range(ll l,ll x){
//     return max(0,l / x);
// }
// ll range2(ll l,ll r,ll x){
//     return range(r,x) - range(l - 1,x);
// }



// signed main(void){

//     #ifdef Khaled
//         freopen("in.txt","r",stdin);
//         //freopen("out.txt","w",stdout);
//     #endif
//     #ifndef Khaled
//         #define endl '\n'
//         fast;
//     #endif

//     ll t;
//     cin >> t;
//     while(t--){
//         ll l,r,x;
//         cin >> l >> r >> x;
//         cout << range2(l,r,x) << endl;
//     }
    

// }



#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;





signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    #ifndef Khaled
        #define endl '\n'
        fast;
    #endif

    int cs;
    while(cin >> cs,~cs){
        string s,t;
        int vis[270] = {0};
        cin >> s;
        cin >> t;
        int state = 0;
        int wrongs = 0;
        set<char>st;
        for(auto c : s)
            st.insert(c);

        for(auto c : t){
            if(vis[c] || st.find(c) != st.end() ){
                vis[c] = 1;
                st.erase(c);
            }
            else{
                wrongs++;
            }
            if(wrongs == 7){
                state = 1;
                break;
            }
            if(!st.size())
                break;
        }
        if(state != 1){

        for(auto c : s){
            if(!vis[c])
                state = 2;
        }
        }
        cout << "Round " << cs << endl;
        if(!state)
            cout << "You win.\n";
        else if(state == 1)
            cout << "You lose.\n";
        else
            cout << "You chickened out.\n";
    }
}





