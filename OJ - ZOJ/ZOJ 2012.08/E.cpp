//
//  Created by TaoSama on 2015-10-08
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

const char month[][5] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                         "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
                        };
int day[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//               1   2   3   4   5   6   7   8   9   10  11  12

void gao() {
    for(int i = 0; i < 12; ++i) day[i] += day[i - 1];
}

int n;

char buf[10];
int getMonth() {
    scanf("%s", buf);
    for(int i = 0; i < 12; ++i)
        if(!strcmp(buf, month[i])) return i;
    return -1;
}

int getDay() {
    int d; scanf("%d%s", &d, buf);
    return d;
}

int getTime() {
    int mon = getMonth();
    int d = getDay();
    int h, m; scanf("%d:%d%s", &h, &m, buf);
    if(*buf == 'p') h += 12;
    return (day[mon] + d) * 24 * 60 + h * 60 + m + 1;
    //plus one to start from one
}

struct Point {
    int st, ed;
    double c;
    bool operator< (const Point& rhs) const {
        return ed < rhs.ed;
    }
} a[N];

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

const int Time = 6e5;

double maxv[Time << 2];
void update(int o, double v, int l, int r, int rt) {
    if(l == r) {
        maxv[rt] = max(maxv[rt], v);
        return;
    }
    int m = l + r >> 1;
    if(o <= m) update(o, v, lson);
    else update(o, v, rson);
    maxv[rt] = max(maxv[rt << 1], maxv[rt << 1 | 1]);
}

double query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) return maxv[rt];
    int m = l + r >> 1;
    double ret = 0;
    if(L <= m) ret = max(ret, query(L, R, lson));
    if(R > m) ret = max(ret, query(L, R, rson));
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    gao();
    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) {
            a[i].st = getTime();
            a[i].ed = getTime();
            a[i].ed += 5;
            scanf("%lf", &a[i].c);
        }
        sort(a + 1, a + 1 + n);

        memset(maxv, 0, sizeof maxv);
        double ans = 0;
        for(int i = 1; i <= n; ++i) {
            double cur = query(1, a[i].st, 1, Time, 1);
            cur += a[i].c;
            update(a[i].ed, cur, 1, Time, 1);
            ans = max(ans, cur);
        }
        printf("%.1f\n", ans);
    }
    return 0;
}
