//
//  Created by TaoSama on 2016-08-07
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
const int N = 20 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int sz;
struct Deque {
    int step;
    short a[10][2];
    void see() {
        puts("..........");
        for(int i = 1; i <= sz; ++i) {
            printf("(%d %d)\n", a[i][0], a[i][1]);
        }
        puts("..........");
    }
    bool operator<(const Deque& deq) const {
        for(int i = 1; i <= sz; ++i) {
            if(a[i][0] != deq.a[i][0]) return a[i][0] < deq.a[i][0];
            if(a[i][1] != deq.a[i][1]) return a[i][1] < deq.a[i][1];
        }
        return false;
    }
};

void move(Deque& v, int x, int y) {
    for(int i = sz; i > 1; --i) {
        v.a[i][0] = v.a[i - 1][0];
        v.a[i][1] = v.a[i - 1][1];
    }
    v.a[1][0] = x; v.a[1][1] = y;
}

int n, m;
char a[N][N];

bool check(Deque& v, int nx, int ny) {
    if(nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == '#') return false;
    for(int i = 1; i < sz; ++i) if(nx == v.a[i][0] && ny == v.a[i][1]) return false;
    return true;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &m);
    vector<pair<int, int> > v(10);

    sz = 0;
    for(int i = 1; i <= n; ++i) {
        scanf("%s", a[i] + 1);
        for(int j = 1; j <= m; ++j) {
            if(isdigit(a[i][j])) {
                int d = a[i][j] - '0';
                sz = max(sz, d);
                v[d] = {i, j};
            }
        }
    }

    Deque st; st.step = 0;
    for(int i = 1; i <= sz; ++i) {
        int x, y; tie(x, y) = v[i];
        st.a[i][0] = x;
        st.a[i][1] = y;
    }

    int ans = -1;
    queue<Deque> q;
    set<Deque> mp;
    q.push(st);
    while(q.size()) {
        static int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};
        Deque& u = q.front();
        int x = u.a[1][0], y = u.a[1][1];
        if(a[x][y] == '@') {
            ans = u.step;
            break;
        }

        for(int i = 0; i < 4; ++i) {
            Deque v = u;
            int nx = x + d[i][0], ny = y + d[i][1];
            if(!check(v, nx, ny)) continue;
            move(v, nx, ny);

            if(!mp.count(v)) {
                ++v.step;
                mp.insert(v);
                q.push(v);
            }
        }
        q.pop();
    }
    printf("%d\n", ans);

    return 0;
}
