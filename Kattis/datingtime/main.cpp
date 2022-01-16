#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


struct CLK{
    int hours,minutes;


    double angle(){
        
        double hoursAngle = (hours % 12) * 5 + minutes * 5.0 / 60;
        double ret = minutes - hoursAngle;
        if(abs(ret) > 30){
            if(ret > 0)
                ret = ret - 60;
            else
                ret = ret + 60;

        }
        return ret;
    }

    int equal(CLK other){
        return hours == other.hours && minutes == other.minutes;
    }

    void inc(){
        minutes++;
        hours += minutes / 60;
        minutes %= 60;
        hours %= 24;
    }
};

int solve(double last,double cur,int theta){
    map<int,int>mp = {{0,0},{90,15},{180,30}};
    if(abs(abs(cur) - mp[theta]) < 1e-3){
        return 1;
    }
    if(!theta){
        if(last * cur < 0 && abs(last) < 5)
            return 1;
        return 0;
    }   
    else if(theta == 90){
        return ((abs(last) > 15 && abs(cur) < 15) || (abs(last) < 15 && abs(cur) > 15));
    }
    else{
        return ((last > 29 && cur < 0) || (last < -29 && cur > 0) );
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
    int t;
    cin >> t;
    while(t--){
        CLK st,en;
        int theta;
        char _;
        cin >> st.hours >> _ >> st.minutes >> en.hours >> _ >> en.minutes >> theta;
        int res = 0;
        double last_angle = st.angle();
        // cout << st.angle() << endl;
        // st.inc();
        // cout << st.angle() << endl;
        // return 0;
        while(!st.equal(en)){
            double cur_angle = st.angle();
            int ret = solve(last_angle,cur_angle,theta);
            // cout << st.hours << ":" << st.minutes << " " << cur_angle << endl;
            if(ret)
                res += ret;
            last_angle = cur_angle;
            st.inc();
        }   
        res += solve(last_angle,st.angle(),theta);
        cout << res << endl;
    }    

}


