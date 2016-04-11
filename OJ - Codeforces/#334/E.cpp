//
//  Created by TaoSama on 2015-12-02
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

int n, k;

/*
  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20
  0  1  0  1  2  0  2  0  1  0  1  0  1  0  1  0  2  0  1  0  2

  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20
  0  1  2  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1
*/

int odd[5] = {0, 1, 0, 1, 2}, even[3] = {0, 1, 2};

int getSg(int x) {
    if(k & 1) {
        if(x < 5) return odd[x];
        if(x & 1) return 0;
        return getSg(x >> 1) == 1 ? 2 : 1;
    } else {
        if(x < 3) return even[x];
        return (x & 1) ^ 1;
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &k) == 2) {
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            ans ^= getSg(x);
        }
        puts(ans ? "Kevin" : "Nicky");
    }
    return 0;
}

/*
int getSg(int x) {
    if(k & 1) {
        if(!x) return 0;
        if(~sg[x]) return sg[x];
        set<int> s;
        s.insert(getSg(x - 1));
        if(!(x & 1)) s.insert(getSg(x >> 1));
        for(int i = 0; ; ++i) if(!s.count(i)) return sg[x] = i;
    } else {
        if(!x) return 0;
        if(~sg[x]) return sg[x];
        set<int> s;
        s.insert(getSg(x - 1));
        if(!(x & 1)) s.insert(0);
        for(int i = 0; ; ++i) if(!s.count(i)) return sg[x] = i;
    }
}
*/
