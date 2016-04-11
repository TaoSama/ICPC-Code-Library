//
//  Created by TaoSama on 2016-04-02
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

long long a[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8092, 16184, 32368, 64736, 129472, 258944, 517888, 1035776, 2071552, 4143104, 8286208, 16572416, 33144832, 66289664, 132579328, 265158656, 530317312, 1060634624, 2121269248LL, 4242538496LL, 8485076992LL, 16970153984LL, 33940307968LL};

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int x; scanf("%d", &x);
    printf("%I64d\n", a[x]);
    return 0;
}
