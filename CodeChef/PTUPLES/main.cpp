



#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

typedef unsigned long long ull;
typedef long long ll;

using namespace std;


const int N = 1e6+1;
vector<int>isPrime(N+1,1);

void sieve(void){
    isPrime[0] = isPrime[1] = 0;
    for(ll i = 2;i*i<=N;i++){
        if(isPrime[i]){
            for(int j = 2*i;j<=N;j+=i){
                isPrime[j] = 0;
            }
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

    sieve();

    int com[N+1] = {0};
    for(int i = 3;i<=N;i++){
        if(isPrime[i-2] && isPrime[i]){
            com[i] = com[i-1] + 1;
        }
        else{
            com[i] = com[i-1];
        }
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << com[n] << endl;
    }


}