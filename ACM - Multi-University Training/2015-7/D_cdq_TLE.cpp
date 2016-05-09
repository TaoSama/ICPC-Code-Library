//
//  Created by TaoSama on 2016-03-31
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int BUF_SIZE = 20 << 20;

namespace fastio {
char BUF[BUF_SIZE];

char* ptr;
char* end;

inline void
build() {
    ptr = BUF;
    end = BUF + fread(BUF, sizeof(char), BUF_SIZE, stdin);
}

inline bool
empty() {
    for(char* __x = ptr; __x < end; ++__x) {
        if(isspace(*__x)) continue;
        if(isalnum(*__x)) return false;
    }
    return true;
}

template <typename _Tp>
inline void
nextInt(_Tp& __x) {
    __x = _Tp();
    for(register bool __vf = 0, __sf = 0; true; ++ptr) {
        if(isdigit(*ptr))
            __x = (__x << 3) + (__x << 1) + *ptr - '0', __vf = 1;
        else if(__vf) {
            if(__sf) __x = -__x;
            break;
        } else if(*ptr == '-') __sf = true;
    }
}

inline void
nextChar(char& __x)
{ __x = *ptr, ++ptr; }

inline void
nextStr(char* __s) {
    for(; *ptr; ++__s, ++ptr) *__s = *ptr;
    *__s = 0;
}

}; // namespace fastio

struct Query {
    int l, r, id, type;
    bool operator<(const Query& q) const {
        return r < q.r;
    }
} q[N], tmp[N];

int n, ans[N];

struct BIT {
    int n, b[N << 1], tim[N << 1], sz;
    void init(int _n) {
        n = _n; sz = 0;
        memset(tim, 0, sizeof tim);
    }
    void newOne() { ++sz;}
    void add(int i, int v) {
        for(; i; i -= i & -i) {
            if(tim[i] != sz) tim[i] = sz, b[i] = 0;
            b[i] += v;
        }
    }
    int sum(int i) {
        int ret = 0;
        for(; i <= n; i += i & -i)
            if(tim[i] == sz) ret += b[i];
        return ret;
    }
} bit;

void cdq(int l, int r) {
    if(l == r) return;
    int m = l + r >> 1;
    cdq(l, m);

    for(int i = l; i <= r; ++i) tmp[i] = q[i];
    sort(tmp + l, tmp + m + 1);
    sort(tmp + m + 1, tmp + r + 1);

    int j = l;
    bit.newOne();
    for(int i = m + 1; i <= r; ++i) {
        while(j <= m && tmp[j].r <= tmp[i].r) {
            //printf("%s (%d, %d) \n", tmp[j].type > 0 ? "+" : "-", tmp[j].l, tmp[j].r);
            if(tmp[j].type > 0) bit.add(tmp[j].l, 1);
            else bit.add(q[tmp[j].l].l, -1);
            ++j;
        }
        ans[q[i].id] += bit.sum(q[i].l);
    }
    cdq(m + 1, r);
}

using namespace fastio;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    build();

    while(!empty()) {
        nextInt(n);
        vector<int> xs;
        for(int i = 1; i <= n; ++i) {
            int a, b; nextInt(a); nextInt(b);
            if(a == 0) {
                q[i] = {b, b + i, i, 1};
                xs.push_back(b);
                xs.push_back(b + i);
                ans[i] = 0;
            } else {
                q[i] = {b, -INF, i, -1};
                ans[i] = -1;
            }
        }
        sort(xs.begin(), xs.end());
        xs.resize(unique(xs.begin(), xs.end()) - xs.begin());

        for(int i = 1; i <= n; ++i) {
            if(q[i].r != -INF) {
                //printf("b (%d, %d)\n", q[i].l, q[i].r);
                q[i].l = lower_bound(xs.begin(), xs.end(), q[i].l) - xs.begin() + 1;
                q[i].r = lower_bound(xs.begin(), xs.end(), q[i].r) - xs.begin() + 1;
                //printf("a (%d, %d)\n", q[i].l, q[i].r);
            }
        }

        bit.init(xs.size());
        cdq(1, n);

        static int kase = 0;
        printf("Case #%d:\n", ++kase);
        for(int i = 1; i <= n; ++i)
            if(~ans[i]) printf("%d\n", ans[i]);
    }
    return 0;
}
