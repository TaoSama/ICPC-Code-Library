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
#include <list>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &k) == 2 && (n || k)) {
        list<int> l;
        for(int i = 1; i <= n; ++i) l.insert(l.end(), i);
        //O(n * n*k)

        for(int i = 1; i <= n; ++i) {
            list<int> nl = l;
            int cnt = i - 1;
            auto iter = nl.begin();
            while(cnt--) ++iter;

            while(nl.size() > 1) {
                //go k - 1 steps
                int nk = (k - 1 + nl.size()) % nl.size();
                while(nk--) {
                    ++iter;
                    if(iter == nl.end()) iter = nl.begin();
                }
                //save the k-th iterator
                auto toKillIter = iter;

                if(++iter == nl.end()) iter = nl.begin();

                //go k steps
                nk = (k - 1 + nl.size() - 1) % (nl.size() - 1);
                while(nk--) {
                    ++iter;
                    if(iter == nl.end()) iter = nl.begin();
                    if(iter == toKillIter) ++nk;
                }
                *toKillIter = *iter;
                int toReplace = *iter;
                nl.erase(iter);

//                printf("replace = %d\n", toReplace);
                for(iter = nl.begin(); *iter != toReplace; ++iter);
                if(++iter == nl.end()) iter = nl.begin();

//                for(int x : nl) printf("%d ", x); puts("");
            }
            if(*nl.begin() == 1) {
                printf("%d\n", i);
                break;
            }
        }
    }

    return 0;
}
