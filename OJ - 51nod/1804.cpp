//
//  Created by TaoSama on 2017-04-28
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;



int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

//    for(int n = 3; n <= 15; n += 2) {
//        vector<int> a(n), b(n);
//        for(int i = 0; i < n; ++i) a[i] = b[i] = i + 1;
//        printf("%d\n",(n+1)/2*3);
//        do {
//            bool ok = true;
//            int x = a[0] + b[0] + b[1];
//            for(int i = 1; i < n && ok; ++i) {
//                ok &= (a[i] + b[i] + b[(i + 1) % n]) == x;
//            }
//            if(ok) {
//                for(int i = 0; i < n; ++i) printf("%d ", a[i]); puts("");
//                for(int i = 0; i < n; ++i) printf("%d ", b[i]); puts("");
//            }
//        } while(next_permutation(b.begin(), b.end()));
//
//        puts("");
//    }
//6
//1 2 3
//2 3 1
//
//9
//1 2 3 4 5
//3 5 2 4 1
//
//12
//1 2 3 4 5 6 7
//4 7 3 6 2 5 1
//
//15
//1 2 3 4 5 6 7 8 9
//5 9 4 8 3 7 2 6 1

    int n; scanf("%d", &n); --n;
    if(~n & 1) puts("0");
    else {
        for(int i = 1; i <= n; ++i)
            printf("%d%c", i, " \n"[i == n]);

        int odd = (n + 1) / 2, even = n;
        for(int i = 1; i <= n; ++i) {
            if(i & 1) printf("%d", odd--);
            else printf("%d", even--);
            printf("%c", " \n"[i == n]);
        }
    }

    return 0;
}
