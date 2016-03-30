#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;
//4 5
LL l, r;

LL calc(LL x) {
    if(x < 4) return 1;
    return (x - 4 + 5 - 1) / 5 + 1;
}

int main() {
    while(scanf("%lld%lld", &l, &r) == 2 && (l || r)) {
        printf("%lld\n", calc(r) - calc(l) + 1);
    }
    return 0;
}
