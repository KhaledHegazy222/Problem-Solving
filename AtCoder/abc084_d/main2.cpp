


#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)


using namespace std;
const int N = 100001;

vector<bool> isPrime(N+1, true); 
void sieve(int n) {
    isPrime[0] = isPrime[1] = 0; 
    for (int i = 2; i*i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * 2; j <= n; j += i)
                isPrime[j] = 0;
            }
    }
   
}

int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    sieve(N);
    int com[N+2] = {0};
    for(int i = 1;i<=N+1;i++){
        com[i] = com[i-1];
        if(isPrime[i] && isPrime[(i+1) / 2]){
            com[i]++;
        } 
    }

    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l  >> r;
        cout << com[r] - com[l-1] << endl;
    }
}
