//
//  Created by TaoSama on 2016-09-15
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
typedef long long LL;
struct Point {
    LL x, y;
    int id;
    void read() {
        scanf("%I64d%I64d", &x, &y);
    }
    Point() {}
    Point(LL x, LL y) : x(x), y(y) {}
    Point operator-(const Point& p) const {
        return Point(x - p.x, y - p.y);
    }
    LL operator*(const Point& p) const {
        return x * p.x + y * p.y;
    }
    LL operator^(const Point& p) const {
        return x * p.y - y * p.x;
    }
    bool operator<(const Point& p) const {
        if(x == p.x) return y < p.y;
        return x < p.x;
    }
} ps[N], q[N];

const double SQRT2 = sqrt(2);
double dis(Point& A, Point& B) {
    LL difX = abs(A.x - B.x), difY = abs(A.y - B.y);
    LL minD = min(difX, difY), maxD = max(difX, difY);
//  printf("(%d, %d) = (%lld, %lld)\n", A.id, B.id, minD, maxD - minD);
    return SQRT2 * minD + maxD - minD;
}

Point ch[N];
int convexHull(Point* p, int n, Point* ch) {
    sort(p, p + n);

    int m = 0;
    for(int i = 0; i < n; ++i) {
        while(m > 1 && ((ch[m - 1] - ch[m - 2]) ^ (p[i] - ch[m - 2])) <= 0) --m;
        ch[m++] = p[i];
    }
    for(int i = n - 2, t = m; ~i; --i) {
        while(m > t && ((ch[m - 1] - ch[m - 2]) ^ (p[i] - ch[m - 2])) <= 0) --m;
        ch[m++] = p[i];
    }
    if(n > 1) --m;
    return m;
}

typedef pair<int, int> P;
pair<double, P> go(Point* ch, int n) {
    if(n == 2) return {dis(ch[0], ch[1]), {ch[0].id, ch[1].id}};

    ch[n] = ch[0];
    pair<double, P> ret = { -1, { -1, -1}};
    for(int i = 0, j = 2; i < n; ++i) {
        while(((ch[i + 1] - ch[i]) ^ (ch[j + 1] - ch[i]))
                > ((ch[i + 1] - ch[i]) ^ (ch[j] - ch[i])))
            j = (j + 1) % n;
        pair<double, P> t1 = {dis(ch[j], ch[i + 1]), {ch[j].id, ch[i + 1].id}};
        pair<double, P> t2 = {dis(ch[j], ch[i]), {ch[j].id, ch[i].id}};
        ret = max({ret, t1, t2});
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    for(int i = 0; i < n; ++i) ps[i].read(), ps[i].id = i;
    int m = convexHull(ps, n, ch);

    auto ret = go(ch, m);

    auto& ans = ret.second;
    printf("%d %d\n", ans.first + 1, ans.second + 1);

    return 0;
}
