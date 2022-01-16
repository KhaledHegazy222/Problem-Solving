

#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)


using namespace std;





int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif

    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr,arr+3);
    if(arr[0] + arr[1] > arr[2]){
        cout << "Valid\n";
        double s = (arr[0] + arr[1] + arr[2]) / 2.0;
        double area = sqrt(s*(s-arr[0])*(s - arr[1]) * (s - arr[2]));
        cout << area << endl;
    }
    else{
        cout << "Invalid\n";
    }
    
}