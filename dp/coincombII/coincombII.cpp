#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;
#define eat cin
#define big long long
#define endl "\n"

const int MOD = 1000000007;
int n;
int x;

int dp[2][1000005];
int c[105];
int main() {
    ios_base::sync_with_stdio(false);
    eat.tie(NULL);

    eat >> n >> x;

    for (int i =0; i <n; i++) {
        int coin;
        eat >> coin;
        c[i]  = coin;
    }

    dp[0][0] = 1; // With 0 coins, can only make sum 0.

    for (int i = 0; i < n; i++) { // consider each coin
        for (int target = 0; target <= x; target++) { // consider each target value
            dp[1][target] = (dp[0][target] + ((target >= c[i]) ? dp[1][target-c[i]] : 0)) % MOD;
        }
        for (int target = 0; target <= x; target++) {
            dp[0][target] = dp[1][target];
        }
    }
    cout << dp[0][x] << endl;
}