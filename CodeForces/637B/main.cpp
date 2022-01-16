
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
    stack<string>st;
    map<string,int>mp;

    while(n--){
        string s;
        cin >> s;
        st.push(s);
    }
    while(!st.empty()){
        if(mp[st.top()] == 0){
            cout << st.top() << endl;
            mp[st.top()]++;
        }
        st.pop();
    }
}

