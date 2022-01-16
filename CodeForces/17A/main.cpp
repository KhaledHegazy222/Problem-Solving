

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

typedef unsigned long long ull;
typedef long long ll;

using namespace std;


vector<bool>isPrime(1001);
vector<int>Primes;

void Sieve(void){
    int n = 1000;
    isPrime[0] = isPrime[1] = 1;
    for(int i = 2; i*i< n;i++){
        if(isPrime[i] == 0)
            for(int j = 2*i;j<=1000;j+=i){
                isPrime[j] = 1;
            }
    }

    for(int i = 0;i<=1000;i++){
        if(isPrime[i] == 0) Primes.push_back(i);
    }


}


int valid(int x){
    if(isPrime[x] == 1) return 0;
    x--;
    for(int i = 0;i<Primes.size()-1;i++){
        if(Primes[i] + Primes[i+1] == x) return 1;
    }
    return 0;
}


int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    int n,k;
    cin >> n >> k;
    Sieve();


    int cnt = 0;
    for(int i = 2;i<=n;i++){
        if(valid(i)){
            cnt++;
        } 
    }




    if(cnt >= k ) cout << "YES\n";
    else cout << "NO\n";

}