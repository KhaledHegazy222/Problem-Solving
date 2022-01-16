#include <stdio.h>


int max(int a,int b){
    return a > b ? a : b;
}



int main(void){

    int T;

    scanf("%d",&T);


    while(T--){

        int a,b,c,n;
        scanf("%d%d%d%d",&a,&b,&c,&n);

        double maximum = max(a,max(b,c));

        int sum = a + b + c + n;

        if( sum % 3 == 0 && maximum <=(double) sum / 3.0 ){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
        
    }



    return 0;


}