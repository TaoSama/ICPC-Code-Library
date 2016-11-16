#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

int n;
LL mb, mw;
typedef pair<LL, LL> P;
P a[N];

LL getDif(const P& x) {
    return x.second - x.first + 1;
}

struct cmpByDif {
    bool operator()(const P& x, const P& y) const {
        return getDif(x) > getDif(y);
    }
};

struct cmpByBallon {
    bool operator()(const P& x, const P& y) const {
        return x.first < y.first;
    }
};

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\luwt\\Desktop\\in.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(false);

    while(cin >> n) {
        cin >> mb >> mw;
        --n;


        priority_queue<P, vector<P>, cmpByDif> q1;
        priority_queue<P, vector<P>, cmpByBallon> q2;

        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            LL b, w; cin >> b >> w;
            a[i] = {b, w};
            if(b > mb) {
                ++ans;
                q1.push(a[i]);
            } else q2.push(a[i]);
        }

        while(q1.size()) {
            P u = q1.top(); q1.pop();
            LL diff = getDif(u);
            if(diff > mb) break;
            mb -= diff;
//            cout << n << ":...." << diff << ' ' << mb << endl;

            while(q2.size()) {
                P u = q2.top();
                if(u.first > mb) {
                    q1.push(u);
                    q2.pop();
                } else break;
            }
            ans = min(ans, (int)q1.size());
        }
        cout << ans + 1 << endl;

    }
    return 0;
}
