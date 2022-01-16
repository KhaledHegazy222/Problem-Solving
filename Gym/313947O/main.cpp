#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    #ifndef Khaled
        #define endl '\n'
        fast;
    #endif
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        deque<ll>A(n),B(n);
        for(auto &elem : A)
            cin >> elem;
        for(auto &elem : B)
            cin >> elem;
        sort(all(A));
        sort(all(B));
        ll score1 = accumulate(A.end() - (n - (n / 4)),A.end(),0ll);
        ll score2 = accumulate(B.end() - (n - (n / 4)),B.end(),0ll);
        ll levels = 0;
        while(score1 < score2){
            levels++;
            A.push_back(100);
            B.push_front(0);
            int last_size = n - n / 4;
            n++;
            int current_size = n - n / 4;
            score1 += 100;
            if(last_size == current_size)
                score1 -= A[A.size() - last_size - 1];
            else
                score2 += B[B.size() - last_size - 1];

            last_size = current_size;
            // score1 = accumulate(A.end() - (n - (n / 4)),A.end(),0ll);
            // score2 = accumulate(B.end() - (n - (n / 4)),B.end(),0ll);
            // if(A.size() + 1 >  - n / 4){
            //     sum1 -= A.front();
            //     sum2 -= B.front();
            //     A.push_back(100);
            //     B.push_back(0);
            //     sum1 += 100;
            // }
            // else{
            //     A.push_back(100);
            //     B.push_back(0);
            //     sum1 += 100;
            // }




        }
        // cout << levels << " " << score1 << " " << score2 << endl;
        cout << levels << endl;


    }    

}


