#include <iostream>
#include <cstdio>

using namespace std;

double h,u,d,f,ans;
int main() {
#ifdef LOCAL
    freopen("ACM_in.txt","r",stdin);
    //freopen("ACM_out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin>>h>>u>>d>>f&&h) {
        double cur=0;
        double x=f/100*u;
        for(int i=1;; ++i) {
            cur+=u;
            if(cur>h) {
                cout<<"success on day "<<i<<endl;
                break;
            } else {
                cur-=d;
                u-=x;
                if(u<0) u=0;
                if(cur<0) {
                    cout<<"failure on day "<<i<<endl;
                    break;
                }
            }
        }
        // cout<<ans<<endl;
    }
    return 0;
}
