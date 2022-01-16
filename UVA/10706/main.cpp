#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
const int N = 1e5 + 5;
ll com[N];

int x;



int valid(int n){
    return x <= com[n];
}




int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    com[0] = 0;
    for(int i = 1;i<N;i++){
        com[i] = com[i - 1] + log10(i) + 1;
    }
    for(int i = 1;i<N;i++)
        com[i] += com[i-1];




    int t;
    cin >> t;
    while(t--){
        cin >> x;
        
        int l = 0,r = N - 1;
        while(l != r){
            int mid = (l + r) / 2;
            if(valid(mid))
                r = mid;
            else
                l = mid + 1;
        }
        string s;
        for(int i = 1;i<=l;i++){
            string z = to_string(i);
            s += z;
        }

        cout << s[x - com[l - 1] - 1] << endl;
            
    }

}
