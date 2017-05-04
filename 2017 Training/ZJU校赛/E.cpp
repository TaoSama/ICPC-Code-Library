//
//  Created by TaoSama on 2017-04-10
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
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;



int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    {
        int stk[10], top = 0;
        stk[++top] = 5; //1 n
        stk[++top] = 1; //2 i
        stk[++top] = 0; //3 temp
        stk[++top] = 0; //4 f[i-1]
        stk[++top] = 1; //5 f[i]

        stk[++top] = 0; //to cmp
        while(stk[1] != stk[2]) {
            stk[3] = stk[5];
            stk[4] = stk[4] + stk[5];
            stk[5] = stk[4];
            stk[4] = stk[3];

            stk[6] = stk[2];
            ++stk[6];
            stk[2] = stk[6];
        }
//        printf("%d\n", stk[5]);
    }

    auto printc = [](int x) {cout << string(x, 'c') << '\n';};
    auto push = [&](int x) {printc(7 + x);};
    auto cmp = [&] {printc(3);};
    auto jmp = [&](int x) {printc(7 + x); printc(6);};
    auto copyXtoY = [&](int x, int y) {push(x); push(y); printc(5);};

    printc(4); //1: n
    push(1);  //2: i
    push(0);  //3: temp
    push(0);  //4: f[i-1]
    push(1);  //5: f[i]

    push(0); //6
    push(0); //7
    copyXtoY(1, 6);
    copyXtoY(2, 7);
    cmp();
    jmp(100); //true to end

    //fib
//    prln(1);
    copyXtoY(5, 3);
    printc(1);  //add
    push(0); //5
    copyXtoY(4, 5);
    copyXtoY(3, 4);
    push(0);   //6
    copyXtoY(2, 6);
    push(1);
    printc(1); //add
    copyXtoY(6, 2);


    push(0); //7
    copyXtoY(1, 6);
    copyXtoY(2, 7);
    printc(3); //cmp
    push(0);  //0;
    cmp();
    jmp(17); //continue to fib


    return 0;
}
