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

int n, a[N], k, b[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
//    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        scanf("%d", &k);
        for(int i = 1; i <= k; ++i) scanf("%d", b + i);

        int ok = true, sum = 0;
        vector<vector<int> > w(k + 1);
        for(int i = 1, j = 1; i <= n && ok; ++i) {
            sum += a[i];
            w[j].push_back(a[i]);
            if(sum == b[j]) {
                sum = 0;
                ++j;
            } else if(sum > b[j]) ok = false;
            if(j == k + 1 && i != n) ok = false;
        }
        if(!ok) {puts("NO"); continue;}

//        for(int i = 1; i <= k; ++i) {
//            for(int x : w[i]) cout << x << ' '; cout << endl;
//        }

        vector<pair<int, char> > ans;
        for(int i = 1; i <= k && ok; ++i) {
            ok = false;
            for(int j = 0; j < w[i].size(); ++j) {
                vector<int> v = w[i];
                int can = 1, p = j;
                vector<pair<int, char> > cur;
//                prln(p);
                while(v.size() > 1 && can) {
                    if(p > 0 && v[p] > v[p - 1]) {
                        v[p] += v[p - 1];
                        v.erase(v.begin() + p - 1);
                        cur.push_back({p + i, 'L'});
//                        cout << p + i << " L" << endl;
                        --p;
                    } else if(p + 1 < v.size() && v[p] > v[p + 1]) {
                        v[p] += v[p + 1];
                        v.erase(v.begin() + p + 1);
                        cur.push_back({p + i, 'R'});
//                        cout << p + i << " L" << endl;
                    } else can = false;
                }
//                cout << endl;
                if(can) {
                    ok = true;
                    ans.insert(ans.end(), cur.begin(), cur.end());
                    break;
                }
            }
        }
        if(!ok) {puts("NO"); continue;}

        puts("YES");
        for(auto p : ans) printf("%d %c\n", p.first, p.second);
    }

    return 0;
}
