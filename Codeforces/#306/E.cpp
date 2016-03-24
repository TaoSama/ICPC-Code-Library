//
//  Created by TaoSama on 2015-06-06
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, a[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        for(int i = 1; i <= n; ++i) cin >> a[i];
        if(a[n] == 1) {
            cout << "NO\n";
            continue;
        }
        bool ok = false;
        if(n == 1 && a[1] == 0) {
            cout << "YES\n0\n";
            continue;
        }
        if(n >= 2 && a[n - 1] == 1 && a[n] == 0)  {
            cout << "YES\n";
            for(int i = 1; i <= n; ++i)
                cout << a[i] << (i == n ? "" : "->");
            cout << "\n";
            continue;
        }
        string cur;  //"xxxx...(0(111..110))0" = "xxxx...(00)0" = "xxxx...10" = "0"
        for(int i = 1; i <= n - 2; ++i) {
            if(a[i]) cur += (a[i] + '0'), cur += "->";
            else {
                ok = true;
                cout << "YES\n";
                cout << cur << "(0->";  //�Ѿ��ѵ�ǰλ�ô�ӡ��
                bool have = ++i <= n - 2;  //�������
                if(have) cout << "(";  //��һ������
                while(i <= n - 2) cout << a[i++] << "->";
                cout << "0)";  //��ӡ�����ڶ���0
                if(have) cout << ")";
                cout << "->0\n";  //����Ǹ�0
            }
        }
        if(!ok) cout << "NO\n";
    }
    return 0;
}
