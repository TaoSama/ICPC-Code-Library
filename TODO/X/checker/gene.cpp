#include <bits/stdc++.h>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
typedef long long LL;

int n, m;
int rand32() {
    return (rand() << 16) + rand();
}
LL rand64() {
    return (1LL * rand32() << 32) + rand32();
}

LL rand(LL l, LL r) {
    return rand64() % (r - l + 1) + l;
}

int main() {
    srand((int)(new int));

//    cout << 10 << endl;
//    for(int t = 1; t <= 10; ++t) {
//        for(int i = 1; i <= 1e5; ++i)
//            if(i % 10 != 6) cout << char('A' + rand(0, 25));
//            else cout << char('a' + rand(0, 25));
//        cout << endl;
//        cout << 10000 << endl;
//        for(int i = 1; i <= 1e4; ++i) {
//            cout << char('A' + rand(0, 25)) << ' ';
//            if(t == 1) {
//                if(i % 10 != 6) cout << char('A' + rand(0, 25));
//                else cout << char('a' + rand(0, 25));
//            } else {
//                cout << char('A' + rand(0, 25));
//            }
//            cout << endl;
//        }
//    }

	int n = 5;
	printf("%d\n", n);
	for(int i = 2; i <= n; ++i){
		printf("%d %d\n", (int)rand(1, i - 1), i);
	}
	int q = n;
	printf("%d\n", q);
	for(int i = 1; i <= q; ++i){
		printf("%d %d\n", i, rand(1, 50));
	}



    return 0;
}
