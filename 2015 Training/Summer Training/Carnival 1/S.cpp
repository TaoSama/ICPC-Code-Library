//
//  Created by TaoSama on 2015-07-27
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

string s;
int k;

struct P {
    string s;
    int k;
    P() {}
    P(string s, int k): s(s), k(k) {}
    bool operator< (const P& rhs) const {
        return s > rhs.s;
    }
};

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s >> k) {
        priority_queue<P> pq;
        int n = s.size();
        for(int i = 0; i < n; ++i) pq.push(P(string(1, s[i]), i));
        if(k > 1LL * n * (n + 1) / 2) {
            cout << "No such line.\n";
            continue;
        }
        int cnt = 0;
        while(pq.size()) {
            P cur = pq.top(), nxt = cur; pq.pop();
            if(++cnt == k) {
                cout << cur.s << '\n';
                break;
            }
            if(nxt.k != n - 1) {
                nxt.s += s[++nxt.k];
                pq.push(nxt);
            }
        }
    }
    return 0;
}
