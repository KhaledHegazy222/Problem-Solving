#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


const int N = 1e7 + 5;
vector<bool>isPrime(N,1);
vector<int>primes;


void sieve(){
    isPrime[0] = isPrime[1] = 0;
    for(int i = 2;1ll * i * i < N;i++){
        if(isPrime[i]){
            for(int j = 2 * i;j<N;j+=i)
                isPrime[j] = 0;
        }
    }
    for(int i = 0;i<N;i++)
        if(isPrime[i])
            primes.push_back(i);

}


int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    sieve();
    int cs = 1;
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        map<char,int>mp;
        for(auto it : s){
            mp[it]++;
        }
        string res;
        for(auto it : mp){
            if(isPrime[it.second])
                res.push_back(it.first);
        }
        cout << "Case " << cs++ << ": " << (res.empty() ? "empty" : res) << endl; 
    }

}