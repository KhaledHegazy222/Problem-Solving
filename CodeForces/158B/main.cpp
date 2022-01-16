#include<bits/stdc++.h>

using namespace std;


int main(void){
    int n;
    cin >> n;
    int groups[4] = {0};
    for(int i = 0;i<n;i++){
        int number;
        cin >> number;
        groups[number-1]++;
    }

    int taxies = 0;
    taxies += groups[3];

    groups[3] = 0;

    int twos = groups[1] / 2;
    taxies += twos;
    groups[1] -= twos * 2;

    int ones_with_threes = min(groups[0],groups[2]);
    taxies += ones_with_threes;
    groups[0] -= ones_with_threes;
    groups[2] -= ones_with_threes;

    taxies += groups[2];
    groups[2] = 0;

    int could2 = groups[0] / 2;
    int ones_with_twos = min(could2,groups[1]);
    taxies += ones_with_twos;

    groups[0] -= ones_with_twos * 2;
    groups[1] -= ones_with_twos;

    int one_with_two = min(groups[0], groups[1]);

    groups[0] -= one_with_two;
    groups[1] -= one_with_two;


    taxies += one_with_two;
    int remain = ceil(groups[0] / 4.0);
    int remain2 = ceil(groups[1]/ 2.0);

    taxies += remain + remain2;

    cout << taxies << endl;




}