//
//  Created by TaoSama on 2015-08-02
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

struct P {
    long long x, y;
    P() {}
    P(long long x, long long y): x(x), y(y) {}
    P rotate() {return P(-y, x);}
    P operator- (const P& rhs) const {
        return P(x - rhs.x, y - rhs.y);
    }
    long long operator* (const P& rhs) const {
        return x * rhs.x + y * rhs.y;
    }
    bool operator== (const P& rhs) const {
        return x == rhs.x && y == rhs.y;
    }
};

//A*i^k + (a + bi)C = B -> B - A*i^k = (a + bi)C
//D = (a + bi)C
//a*Xc - b*Yc = Xd ¢Ù  a*Yc + b*Xc = Yd ¢Ú
bool judge(P& u, P& v) {
    if(v == P(0, 0)) return u == P(0, 0);
    long long w = v.x * v.x + v.y * v.y;
    return u * v % w == 0 && u * v.rotate() % w == 0;
}

P a, b, c;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y) {
        bool ok = false;
        for(int i = 0; i < 4; ++i) {
            P d = b - a;
            if(judge(d, c)) {
                ok = true;
                break;
            }
            a = a.rotate();
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
