#include <bits/stdc++.h>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

class BearBall {
public:
    int countThrows(vector<int> x, vector<int> y) {
        int n = x.size();

        int ans = 0;
        for(int i = 0; i < n; ++i) {
            map<pair<int, int>, int> mp;
            for(int j = 0; j < n; ++j) {
                if(i == j) continue;
                int dx = x[j] - x[i], dy = y[j] - y[i];
                int g = __gcd(abs(dx), abs(dy));
                dx /= g; dy /= g;
//                printf("(%d, %d) = %d\n", dx, dy, d);

                ++mp[ {dx, dy}];
            }
            if(mp.size() == 1){
                int cnt = 0;
                for(int j = 0; j < n; ++j){
                    int l = j, r = n - j - 1;
                    cnt += (1 + l) * l / 2;
                    cnt += (1 + r) * r / 2;
                }
                return cnt;
            }
            for(auto p : mp) {
                int cnt = p.second;
                ans += 2 * cnt - 1;
            }
        }

        return ans;
    }
};

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x) { return x < 0;}
template<class I, class O> vector<pair<I, O>> getTestCases() {
    return {
        { { {1, 4, 2}, {1, 10, 7} }, {6} },
        { { {0, 0, 0, 1, 1}, {0, 1, 2, 0, 1} }, {22} },
        { { {5, 7, 9, 11}, {4, 3, 2, 1} }, {20} },
        { { {10, 10, 50, 50, 90, 90}, {5, 17, 5, 17, 5, 17} }, {34} },
        { { { -100, -90, -80, -70, -85, -90, 0, 20}, { -5, -8, -13, -21, -13, -13, -13, -69} }, {68} },
        // Your custom test goes here:
        //{ { {}, {}}, {} },
    };
}

//------------------------------------------------------------------------------
// Tester code:
#define DISABLE_COLORS

#include "tester.cpp"
struct input {
    vector<int> p0; vector<int> p1;

    int run(BearBall* x) {
        return x->countThrows(p0, p1);
    }
    void print() {
        //Tester::printArgs(p0,p1);
    }
};

int main() {
    return Tester::runTests<BearBall>(
               getTestCases<input, Tester::output<int>>(), disabledTest,
               250, 1466269160, CASE_TIME_OUT, Tester::COMPACT_REPORT
           );
}
// CUT end
