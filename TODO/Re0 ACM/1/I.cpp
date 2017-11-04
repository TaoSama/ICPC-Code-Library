//
//  Created by TaoSama on 2017-01-16
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

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    priority_queue<LL, vector<LL>, greater<LL> > q;
    q.push(1);
    int cnt = 0;
    set<LL> s;
    while(q.size()) {
        LL u = q.top(); q.pop();
//        if(cnt < 20) printf("%lld\n", u);
        if(++cnt == 1500) {
            printf("The 1500'th ugly number is %lld.\n", u);
            break;
        }
        int d[] = {2, 3, 5};
        for(int i = 0; i < 3; ++i) {
            LL v = u * d[i];
            if(!s.count(v)) {
                s.insert(v);
                q.push(v);
            }
        }
    }

    return 0;
}
