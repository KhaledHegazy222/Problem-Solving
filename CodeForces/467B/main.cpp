#include<bits/stdc++.h>


using namespace std;


int n,m,k;
int me;

int friending(int number){
    int ans = 0;
    int temp = me;
    for(int i =n-1;i>=0;i--){
        int x  =pow(2,i);
        if(temp >= x && number >= x){
            temp -= x;
            number -= x;
        }
        else if(temp >= x){
            temp -= x;
            ans++;
        }
        else if(number >= x){
            number-=x;
            ans++;

        }
    }

    return ans;
}

int main(void){
    cin >> n >> m >> k;
    int f = 0;
    int array[m];
    for(int i = 0;i<m;i++){
        cin >> array[i];
    }
    cin >> me;
    int friends = 0;
    for(int i=0;i<m;i++){
        if(friending(array[i])<=k){
            friends++;
        }
    }

    cout << friends << endl;


}