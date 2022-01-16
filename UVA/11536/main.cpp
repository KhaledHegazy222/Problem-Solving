
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define fast cin.tie(),ios::sync_with_stdio(0)
using namespace std;


typedef unsigned long long ull;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<vector<ll>> vvll;
typedef vector<ll> vll;





int main(void){
    fast;
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    int t;
    cin >> t;
    int cs = 1;
    while(t--){
        int n,m,k;
        cin >> n >> m >> k;
        int seq[n];
        for(int i = 1;i<=min(3,n);i++){
            seq[i-1] = i;
        }
        for(int i = 3;i<n;i++){
            seq[i] = ( (seq[i-1] + seq[i-2] + seq[i-3]) % m)  + 1;
        }
        map<int,int>freq;
        int min_size = INT_MAX;
        int l = 0,r = 0;
        while(l < n){
            while(r < n && freq.size() < k){
                if(seq[r] <= k)
                    freq[seq[r]]++;
                r++;
            }

            if(freq.size() == k){
                min_size = min(min_size,r - l);
            }


            auto it = freq.find(seq[l]);
            if(it != freq.end()){
                if(it->second == 1)
                    freq.erase(seq[l]);
                else
                    freq[seq[l]]--;
            }
            l++;
        }
        cout << "Case " << cs++ << ": ";
        if(min_size == INT_MAX)
            cout <<  "sequence nai\n";
        else
            cout << min_size << '\n';

    }
}