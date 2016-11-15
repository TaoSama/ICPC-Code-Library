//
//  Created by TaoSama on 2016-10-31
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;

typedef long long LL;

struct Int_128 {
    unsigned long long a, b;
    Int_128(LL x = 0) {a = 0, b = x;}
    friend bool operator < (Int_128 x, Int_128 y) {
        return x.a < y.a || x.a == y.a && x.b < y.b;
    }
    friend Int_128 operator + (Int_128 x, Int_128 y) {
        Int_128 re(0);
        re.a = x.a + y.a + (x.b + y.b < x.b);
        re.b = x.b + y.b;
        return re;
    }
    friend Int_128 operator - (Int_128 x, Int_128 y) {
        y.a = ~y.a; y.b = ~y.b;
        return x + y + 1;
    }
    void Div2() {
        b >>= 1; b |= (a & 1ll) << 63; a >>= 1;
    }
    friend Int_128 operator * (Int_128 x, Int_128 y) {
        Int_128 re = 0;
        while(y.a || y.b) {
            if(y.b & 1)re = re + x;
            x = x + x; y.Div2();
        }
        return re;
    }
    friend Int_128 operator % (Int_128 x, Int_128 y) {
        Int_128 temp = y;
        int cnt = 0;
        while(temp < x)temp = temp + temp, ++cnt;
        for(; cnt >= 0; cnt--) {
            if(temp < x)x = x - temp;
            temp.Div2();
        }
        return x;
    }
    void see() {cout << a << ' ' << b << endl;}
};

Int_128 tri(Int_128 x) {return x * x * x;}

Int_128 getV(Int_128 a, Int_128 b, Int_128 c) {
//  a.see(); b.see(); c.see();
    return tri(min({a, b, c}));
}

void test() {
    Int_128 v = getV(1, 2, 3);
    cout << v.a << ' ' << v.b << endl;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

//  test();
//  return 0;

    while(scanf("%d", &n) == 1) {
        map<pair<int, int>, pair<int, int> > mp;
        pair<Int_128, pair<int, int> > ans = {Int_128(0), { -1, -1}};
        for(int i = 1; i <= n; ++i) {
            int t[3];
            for(int j = 0; j < 3; ++j) scanf("%d", t + j);
            sort(t, t + 3);
            ans = max(ans, {getV(t[0], t[1], t[2]), {i, -1}});

            if(mp.count({t[0], t[1]})) {
                int c, id; tie(c, id) = mp[ {t[0], t[1]}];
                ans = max(ans, {getV(t[0], t[1], t[2] + c), {id, i}});
            }
            if(mp.count({t[0], t[2]})) {
                int c, id; tie(c, id) = mp[ {t[0], t[2]}];
                ans = max(ans, {getV(t[0], t[2], t[1] + c), {id, i}});
            }
            if(mp.count({t[1], t[2]})) {
                int c, id; tie(c, id) = mp[ {t[1], t[2]}];
                ans = max(ans, {getV(t[1], t[2], t[0] + c), {id, i}});
            }
            mp[ {t[0], t[1]}] = max(mp[ {t[0], t[1]}], {t[2], i});
            mp[ {t[0], t[2]}] = max(mp[ {t[0], t[2]}], {t[1], i});
            mp[ {t[1], t[2]}] = max(mp[ {t[1], t[2]}], {t[0], i});
        }
        auto tt = ans.second;
        if(tt.second != -1) {
            printf("2\n%d %d\n", tt.first, tt.second);
        } else {
            printf("1\n%d\n", tt.first);
        }
    }

    return 0;
}
