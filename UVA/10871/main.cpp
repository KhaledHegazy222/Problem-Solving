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

    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        string line;
        getline(cin,line);
        stringstream ss(line); 
        vector<int>v;
        int x;
        ss >> x;
        while(ss >> x)
            v.push_back(x);
        int com[v.size() + 1] = {0};
        for(int i = 1;i<=v.size();i++){
            com[i] = com[i - 1] + v[i - 1];
        }

        int st = -1,sz = 100012;
        for(int i = 1;i<=v.size();i++){
            for(int j = 0;j<i;j++){
                if(isPrime[com[i] - com[j]] && i - j < sz && i - j > 1)
                    sz = i - j,st = j;
            }
        }
        if(!~st){
            cout << "This sequence is anti-primed.\n";
            continue;
        }
        cout << "Shortest primed subsequence is length " << sz << ":";
        for(int i = st;sz--;i++)
            cout << " " << v[i];
        cout << endl;



    }

}