#include <bits/stdc++.h>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

class PingPongQueue {
    public:
        vector<int> whoPlaysNext(vector<int> skills, int N, int K) {
            vector<int> ret;
            vector<int> wons(51, 0);
            int rounds = 0, lastWon = -1;
            for(int i = 0; i < skills.size(); ++i) {
                int u = skills[i];
                ret.push_back(u);
                if(ret.size() == 2) {
                    if(ret[0] > ret[1]) swap(ret[0], ret[1]);
                    if(++rounds == K) return ret;
                    skills.push_back(ret.front());
                    ret.erase(ret.begin());
                    if(ret.front() != lastWon) {
                        lastWon = ret.front();
                        wons[ret.front()] = 0;
                    }
                    if(++wons[ret.front()] == N) {
                        skills.push_back(ret.front());
                        ret.erase(ret.begin());
                    }
                }
            }
            return vector<int>();
        }
};

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x) { return x < 0;}
template<class I, class O> vector<pair<I, O>> getTestCases() {
    return {
        { { {1, 2, 3}, 2, 2 }, { {2, 3} } },
        { { {1, 2, 3}, 2, 4 }, { {1, 2} } },
        { { {49, 24, 26, 12, 5, 33, 25, 30, 35, 41, 46, 23, 21, 3, 38, 43, 11, 19, 34, 29, 20, 32, 39, 7, 50}, 10, 399 }, { {12, 50} } },
        { { {30, 12}, 34, 80 }, { {12, 30} } },
        // Your custom test goes here:
        //{ { {}, , }, {} },
    };
}

//------------------------------------------------------------------------------
// Tester code:
#define DISABLE_COLORS

#include "tester.cpp"
struct input {
    vector<int> p0; int p1; int p2;

    vector<int> run(PingPongQueue* x) {
        return x->whoPlaysNext(p0, p1, p2);
    }
    void print() {
        //Tester::printArgs(p0,p1,p2);
    }
};

int main() {
    return Tester::runTests<PingPongQueue>(
               getTestCases<input, Tester::output<vector<int>>>(), disabledTest,
               250, 1491062367, CASE_TIME_OUT, Tester::COMPACT_REPORT
           );
}
// CUT end
