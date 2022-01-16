

#include<bits/stdc++.h>

using namespace std;
int arr[1025][1025];



int main(void){
    int t;
    cin >> t;
    while(t--){
        int d;
        cin >> d;
        int n;
        cin >> n;
        memset(arr, 0, sizeof(arr));
        int index = 0;
         while(n--) {
            int x,y,pop;
            cin >> x >> y >> pop;
            x--;
            y--;
            for(int i = max(x-d,0);i<min(x+d+1,1025);i++){
                for(int j = max(y-d,0);j<min(y+d+1,1025);j++){
                    arr[i][j] += pop;
                }
            }
        }
        int minx = 100000;
        int miny = 100000;
        int maxpop = 0;
            for(int i = 0;i<1025;i++){
                for(int j = 0;j<1025;j++){
                    int ret = arr[i][j];
                    if(ret > maxpop){
                        maxpop = ret;
                        minx = i;
                        miny = j;

                    }
                }
            }

        cout << minx+1 << " " << miny+1 << " " << maxpop << endl;


    }

}
