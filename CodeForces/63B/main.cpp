
#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n,k;
    cin >> n >> k;
    int arr[k] = {0};
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        arr[x-1]++;
    }
    int coins =0;
    while(arr[k-1] != n){
        vector<int>v;
        for(int i = 0;i<k-1;i++){
            if(arr[i]){
                v.push_back(i);
            }
        }
        for(int i=0;i<v.size();i++){
            arr[v[i]]--;
            arr[v[i]+1]++;
        }
        coins++;
    }
    cout << coins <<endl;
}
