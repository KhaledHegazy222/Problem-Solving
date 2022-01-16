#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 1e6 + 5;
vector<bool>isPrime(N,1);
vector<int>primes;
vector<int>diff;
map<int,int>primeToIdx;

int bs1(int x){
    int l = 0,r = primes.size() - 1;
    while(l != r){
        int mid = l + (r - l) / 2;
        if(primes[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return primes[l];
}
int bs2(int x){
    int l = 0,r = primes.size() - 1;
    while(l != r){
        int mid = l + (r - l + 1) / 2;
        if(primes[mid] <= x)
            l = mid;
        else
            r = mid - 1;
    }
    return primes[l];
}



void sieve(){
    isPrime[0] = isPrime[1] = 0;
    for(ll i = 2;i*i <N;i++){
        if(isPrime[i]){
            for(int j = 2 * i;j<N;j+=i)
                isPrime[j] = 0;
        }
    }
    for(int i = 0;i<N;i++)
        if(isPrime[i])
            primes.push_back(i),primeToIdx.insert({i,primes.size()-1});

    for(int i = 1;i<primes.size();i++)
        diff.push_back(primes[i] - primes[i-1]);
}


int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    sieve();
    int t;
    cin >> t;
    while(t--){
        int l,r;
        cin >> l >> r;
        l = bs1(l);
        r = bs2(r);
        int st = primeToIdx[l];
        int en = primeToIdx[r];

        map<int,int>frq;
        for(int i = st;i<en;i++){
            frq[diff[i]]++;
        }
        vector<int>res;
        for(auto it : frq){
            res.push_back(it.second);
        }
        if(res.empty()){
            cout << "No jumping champion\n";
            continue;
        }
        int z = *max_element(all(res));
        if(count(all(res),z) != 1){
            cout << "No jumping champion\n";
            continue;
        }
        for(auto it : frq){
            if(it.second == z){
                cout << "The jumping champion is " << it.first << endl; 
                break;
            }
                
        }

    }

}