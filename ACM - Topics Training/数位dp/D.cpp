//
//  Created by TaoSama on 2015-10-19
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

typedef long long LL;

LL dp[25][2][2], digit[25];

LL dfs(int i, int s, int ok, int e) {
    if(i == 0) return ok;
    if(!e && ~dp[i][s][ok]) return dp[i][s][ok];
    LL ret = 0;
    int to = e ? digit[i] : 9;
    for(int d = 0; d <= to; ++d) {
        ret += dfs(i - 1, d == 4, ok || (s && d == 9), e && d == to);
    }
    if(!e) dp[i][s][ok] = ret;
    return ret;
}

LL calc(LL x) {
    int cnt = 0;
    for(; x; x /= 10) digit[++cnt] = x % 10;
    memset(dp, -1, sizeof dp);
    return dfs(cnt, 0, 0, 1);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        LL x; scanf("%I64d", &x);
        printf("%I64d\n", calc(x));
    }
    return 0;
}

/*
//
//  Created by TaoSama on 2015-10-19
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

typedef long long LL;

LL dp[25][2], digit[25];

LL dfs(int i, int s, int e) {
    if(i == 0) return 1;
    if(!e && ~dp[i][s]) return dp[i][s];
    LL ret = 0;
    int to = e ? digit[i] : 9;
    for(int d = 0; d <= to; ++d) {
        if(s && d == 9) continue;
        ret += dfs(i - 1, d == 4, e && d == to);
    }
    if(!e) dp[i][s] = ret;
    return ret;
}

LL calc(LL x) {
    int cnt = 0;
    for(; x; x /= 10) digit[++cnt] = x % 10;
    memset(dp, -1, sizeof dp);
    return dfs(cnt, 0, 1);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        LL x; scanf("%I64d", &x);
        printf("%I64d\n", x - calc(x) + 1);
    }
    return 0;
}
*/
