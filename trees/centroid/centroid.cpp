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
#include <tuple>

using namespace std;
#define eat cin
#define moo cout
#define big long long

int n;


vector<int> adj[200000];
big sz[200000];
int visited[200000];
void dfs(int v) {
    visited[v] = true;
    for (int u: adj[v]) {
        if (!visited[u]) {
            dfs(u);
            sz[v] += sz[u];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    eat.tie(NULL);

    eat >> n;

    // Create adjacency list
    for (int i =0; i < n-1; i++) {
        int u, v;
        eat >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    fill(sz, sz+n, 1);


    dfs(0); // fix 0 as the root


    for (int node = 0; node < n; node++) {
        big biggest = 0;
        for(int c: adj[node]) {
            biggest = max(biggest, (sz[c] <= sz[node]) ? sz[c] : n - sz[node]);
        }
        if (biggest <= n/2) {
            moo << node + 1 << endl;
            return 0;
        }

    }

}