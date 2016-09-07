//
//  Created by TaoSama on 2016-08-25
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

typedef long long LL;
LL a00, a01, a10, a11;

LL get(LL x) {
    LL l = 0, r = 1e6 + 10;
    while(l <= r) {
        LL m = l + r >> 1;
        LL cur = (1 + m) * m / 2;
        if(cur < x) l = m + 1;
        else if(cur == x) return m + 1;
        else r = m - 1;
    }
    return -1;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> a00 >> a01 >> a10 >> a11) {
        LL zero = get(a00), one = get(a11);
//        pr(zero); prln(one);
        if(zero == -1 || one == -1) {
            cout << "Impossible\n";
            continue;
        }
        if(a00 + a01 + a10 + a11 == 0) {
            cout << "0\n";
            continue;
        }
        if(a01 + a10 == 0) {
            if(a00 && !a11) cout << string(zero, '0') << endl;
            else if(a11 && !a00) cout << string(one, '1') << endl;
            else cout << "Impossible\n";
            continue;
        }
        LL tot = zero * one;
//        pr(a10 + a01); prln(tot);
        if(a01 + a10 != tot) {
            cout << "Impossible\n";
            continue;
        }

        vector<int> cnt1(zero + 1, 0);
        for(int i = zero; i; --i) {
            LL need = a01 / i;
            cnt1[i] += need;
            a01 -= need * i;
        }
        cnt1[0] = one - accumulate(cnt1.begin(), cnt1.end(), 0LL);

        string ans;
        for(int i = 0; i < zero; ++i) ans += string(cnt1[i], '1') + "0";
        ans += string(cnt1[zero], '1');
        cout << ans << endl;
    }

    return 0;
}
