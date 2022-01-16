#include <bits/stdc++.h>
using namespace std;int n,arr[20];

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    long long com[n + 1];
    com[0] = 0;
    for(int i = 1;i <= n;i++){
        com[i] = com[i-1] + arr[i-1];
    }
    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        cout << com[r + 1]  - com[l] << endl;
    }




    return 0;
}
