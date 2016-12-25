////
////  Created by TaoSama on 2016-12-18
////  Copyright (c) 2016 TaoSama. All rights reserved.
////
//#pragma comment(linker, "/STACK:102400000,102400000")
//#include <algorithm>
//#include <cctype>
//#include <cmath>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <ctime>
//#include <iomanip>
//#include <iostream>
//#include <map>
//#include <queue>
//#include <string>
//#include <set>
//#include <vector>
//
//using namespace std;
//#define pr(x) cout << #x << " = " << x << "  "
//#define prln(x) cout << #x << " = " << x << endl
//const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
//
//int n, m, k;
//int a[10][200];
//
//void dfs(int s, int t, int sum, bool e, vector<int>& v, long long& ans) {
//    if(s == t) {
//        if(!e) v.push_back(sum);
//        else {
//            ans += v.end() - upper_bound(v.begin(), v.end(), m - sum);
//        }
//        return;
//    }
//    for(int i = 1; i <= n; ++i)
//        dfs(s + 1, t, sum + a[s][i], e, v, ans);
//}
//
//int main() {
//#ifdef LOCAL
//    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
////  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
//#endif
//    ios_base::sync_with_stdio(0);
//
//    scanf("%d%d%d", &n, &m, &k);
//    for(int i = 1; i <= k; ++i)
//        for(int j = 1; j <= n; ++j)
//            scanf("%d", a[i] + j);
//
//    long long ans = 0;
//    vector<int> v; v.reserve(n * n * n);
//    dfs(1, k / 2 + 1, 0, 0, v, ans);
//    sort(v.begin(), v.end());
////    for(auto x : v) prln(x);
//    dfs(k / 2 + 1, k + 1, 0, 1, v, ans);
//    printf("%lld\n", ans);
//
//
//
//    return 0;
//}


//
//  Created by TaoSama on 2016-12-18
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
string s[N][2];
int f[N][2][2];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> s[i][0];
        s[i][1] = s[i][0];
        reverse(s[i][1].begin(), s[i][1].end());
    }
    memset(f, 0x3f, sizeof f);
    f[1][0][0] = f[1][0][1] = 0;
    f[1][1][0] = f[1][1][1] = 1;
    for(int i = 2; i <= n; ++i) {
        for(int j = 0; j < 2; ++j) {
            for(int k = 0; k < 2; ++k) {
                if(s[i - 1][k] <= s[i][j])
                    f[i][j][0] = min(f[i][j][0], f[i - 1][k][0] + j);
            }
        }
        for(int j = 0; j < 2; ++j) {
            for(int k = 0; k < 2; ++k) {
                if(s[i - 1][k] >= s[i][j])
                    f[i][j][1] = min(f[i][j][1], f[i - 1][k][1] + j);
            }
        }
    }

    int ans = INF;
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; ++j)
            ans = min(ans, f[n][i][j]);
    if(ans == INF) ans = -1;
    printf("%d\n", ans);


    return 0;
}
