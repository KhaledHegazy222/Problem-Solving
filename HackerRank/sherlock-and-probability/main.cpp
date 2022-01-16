


#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()


typedef unsigned long long ull;
typedef long long ll;

using namespace std;
int main(void){
   
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 

    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        ll ttl = 1ll*n*n;
        int com[n+1] = {0};
        for(int i = 0;i<n;i++){
            com[i+1] = com[i];
            if(s[i] - '0')
                com[i+1]++;
        }
        ll pairs = 0;
        for(int i = 1;i<=n;i++){
            int e = min(n,i+k);
            if(s[i-1] - '0')
                pairs += com[e] - com[i-1];
        }
        pairs *= 2;
        pairs -= com[n];
        ll g = __gcd(pairs,ttl);
        cout << pairs / g << "/" << ttl / g << '\n';
    
    }
}   


