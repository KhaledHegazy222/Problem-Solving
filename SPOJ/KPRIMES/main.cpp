

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

typedef unsigned long long ull;
typedef long long ll;

using namespace std;


const int N = 1e4 + 1;
vector<int>isPrime(N+1,1);

void sieve(void){
    isPrime[0] = isPrime[1] = 0;
    for(int i = 2;i*i <= N;i++){
        if(isPrime[i])
            for(int j = 2*i;j<=N;j+=i)
                isPrime[j] = 0;
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
    sieve();

    int t;
    cin >> t;
    int cs = 1;
    while(t--){
        int n,p;
        cin >> n >> p;
        int primes[p];
        for(int i = 0;i<p;i++){
            cin >> primes[i];
        }
        int cnt = 0;
        for(int i = 2;i<=n;i++){
            int div = 1;
            if(isPrime[i]) continue;
            for(int j = 0;j<p;j++){
                if(i % primes[j] == 0){
                    div = 0;
                    break;
                }
            }
            if(div) {
                cnt++;
            } 
        }

        cout << "Case "<< cs++ << ": " << cnt << endl;
    }
}