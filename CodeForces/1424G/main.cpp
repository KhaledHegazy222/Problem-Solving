#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


const ll N = 1e5 + 5;
ll n;
vector<pair<ll,ll>>A(N);
ll comp[N << 1],compSz;


void compress(){
    sort(comp,comp + compSz);
    compSz = unique(comp,comp + compSz) - comp;
    for(ll i = 0;i<n;i++){
        A[i].first = lower_bound(comp,comp + compSz,A[i].first) - comp;
        A[i].second = lower_bound(comp,comp + compSz,A[i].second) -comp ;
    }
}


signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    #ifndef Khaled
        #define endl '\n'
        fast;
    #endif
    cin >> n;
    for(ll i = 0;i<n;i++) {
        cin >> A[i].first >> A[i].second;
        comp[compSz++] = A[i].first;
        comp[compSz++] = A[i].second;
    }

    compress();

    ll partialSum[N << 1] = {0};
    for(ll i = 0;i<n;i++){
        partialSum[A[i].first]++;
        partialSum[A[i].second]--;
    }
    for(ll i = 1;i<N;i++)
        partialSum[i] += partialSum[i - 1];
    ll mx = *max_element(partialSum,partialSum + N);
    cout << comp[find(partialSum,partialSum + N,mx) - partialSum] << " " << mx << endl;

}


