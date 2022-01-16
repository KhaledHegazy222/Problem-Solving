

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

typedef unsigned long long ull;
typedef long long ll;

using namespace std;



int mem[1000][1000];
string s,t;
int sl,tl;
ll dp(int i,int j){
    if(i == sl) return 30ll * (tl-j);
    if(j == tl) return 15ll * (sl-i);

    int& ret = mem[i][j];
    if(ret != -1) return ret;


    if (s[i] == t[j]) return ret = dp(i+1,j+1);

    int ch1 = 15 + dp(i+1,j);
    int ch2 = 30 + dp(i,j+1);
    return ret = min(ch1,ch2);
    
}


int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    while(1){
        memset(mem,-1,sizeof mem);
        cin >> s;
        if(s == "#"){
            return 0;
        }
        cin >> t;

        sl = s.length();
        tl = t.length();
        
        cout << dp(0,0) << endl;
    }

}

