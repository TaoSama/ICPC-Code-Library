//
//  Created by TaoSama on 2016-05-21
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
const int N = 2e8 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int cnt[N];
string s, t;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
    freopen("C:\\Users\\TaoSama\\Desktop\\out.txt", "w", stdout);
#endif
//    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    s = "1";
//  cout << 1 << ": " << s << endl;
    for(int i = 2; i <= 13; ++i) {
        t = s;
        for(char& c : t) c = c == '1' ? '2' : '1';
        reverse(t.begin(), t.end());
        t = s + "1" + t;
//      cout << i << ": " << t << endl;
        s = t;
    }
//    cout << s << endl;

    for(int i = 1; i <= s.size(); ++i) {
        cnt[i] = cnt[i - 1] + (s[i - 1] == '1');
//      printf("%d %d\n", cnt[i - 1], s[i - 1] == '1');
//      printf("%d: %d\n", i, cnt[i]);
    }
//  for(int i = 1; i <= s.size(); ++i){
//      cnt[i] += cnt[i- 1];
//      printf("%d: %d\n", i, cnt[i]);
//  }
    vector<int> v;
    for(int i = 1; i <= s.size(); ++i) {
        int x = 1;
        for(int j = i + 1; j <= s.size() && cnt[j] == cnt[i]; ++j)
            ++x;
        i = i + x - 1;
        v.push_back(x);
    }

    pr(s.size()); prln(v.size());
    for(int delta = 10; delta <= 20; ++delta) {
		prln(delta);
        for(int x = 10; x < v.size(); ++x) {
            if(3 * x + delta + 3 < v.size() && v[x+ delta] == v[delta] &&
                    v[x + delta+ 1] == v[ delta + 1] && v[x + delta+ 2] == v[ delta + 2]
                    && v[x + delta+ 3] == v[ delta + 3]
                    && v[2 * x+ delta] == v[ delta] &&
                    v[2 * x + delta+ 1] == v[ delta + 1] && v[2 * x + delta+ 2] == v[ delta + 2]
                    && v[2 * x + delta+ 3] == v[ delta + 3]&&
                    v[3 * x+ delta] == v[ delta] &&
                    v[3 * x + delta+ 1] == v[ delta + 1] && v[3 * x + delta+ 2] == v[ delta + 2]
                    && v[3 * x + delta+ 3] == v[ delta + 3]) {
                printf("cycle: %d\n", x);
                for(int i = delta + 1; i < v.size(); ++i) {
                    printf("%d, ", v[i]);
                    if((i - delta) % x == 0) puts("");
                }
                puts("\n");
            }
        }
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
