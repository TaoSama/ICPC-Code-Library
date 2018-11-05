#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;



int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int x, y, a, b; cin >> x >> y >> a >> b;
        while(x < a || y < b) {
            if(a > b) {
                swap(x, y);
                swap(a, b);
            }
            int bb = b % a;
            if(bb >= y) {}
            else {
                int lft = y - bb;
                bb += (lft + a - 1) / a * a; 
            }
            if(b == bb) break;
            b = bb;
            // cout << a << ' ' << b << endl;
        }
        cout << (x == a && y == b ? "YES" : "NO") << endl;
    }
    return 0;
}
