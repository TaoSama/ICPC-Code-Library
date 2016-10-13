#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

int n, m, k;
struct Stu {
    int s, t;
    LL cost;
    vector<pair<int, int> > seq;
    void read() {
        int cnt; scanf("%d%d%d", &s, &t, &cnt);
        while(cnt--) {
            int o, w; scanf("%d%d", &o, &w);
            seq.push_back({o, w});
        }
        reverse(seq.begin(), seq.end()); //stack
        cost = 0;
    }
} stu[N];

LL last[105];

struct Event {
    LL t;
    int qid, sid, idx;
    bool operator<(const Event& e) const {
        if(t == e.t) return sid < e.sid;
        return t < e.t;
    }
};

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; ++i) stu[i].read();

    set<Event> q;
    for(int i = 1; i <= n; ++i) {
        Stu& cur = stu[i];
        cur.cost = cur.t + k;
        q.insert({cur.cost, cur.seq.back().first, cur.s, i});
    }
    while(q.size()) {
        Event top = *q.begin(); q.erase(q.begin());
        int qid = top.qid, idx = top.idx;
        auto& cur = stu[idx]; auto& seq = cur.seq;
        auto office = seq.back(); seq.pop_back();
        cur.cost = max(cur.cost, last[qid]) + office.second;
        last[qid] = cur.cost;
        if(seq.size()) {
            auto office = seq.back();
            cur.cost += k;
            q.insert({cur.cost, office.first, cur.s, idx});
        }
    }
    for(int i = 1; i <= n; ++i) printf("%lld\n", stu[i].cost);

    return 0;
}
