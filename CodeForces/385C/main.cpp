#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


const int N = 1e7 + 6;
vector<bool>isPrime(N,1);
vector<int>primes;

void sieve(){
    isPrime[0] = isPrime[1] = 0;
    for(ll i = 2;i * i < N;i++)
        if(isPrime[i])
            for(int j = 2 * i;j < N;j += i)
                isPrime[j] = 0;

    for(int i = 0;i < N;i++){
        if(isPrime[i])
            primes.push_back(i);
    }
}



int arr[N];
int F[N];
ll com[N];

int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    sieve();
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        arr[x]++;
    }
    for(int i = 0;i<primes.size();i++){
        for(int j = primes[i];j<N;j+=primes[i])
            F[primes[i]] += arr[j];
    }

    for(int i = 1;i<N;i++)
        com[i] = com[i-1] + F[i]; 


    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        r = min(r,N - 1);
        if(l <= r)
            cout << com[r] - com[l - 1] << endl;
        else
            cout << 0 << endl;
    }


}