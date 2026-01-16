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
#define moo cout
#define big long long

int n;


vector<pair<int, int>> adj[200005];
int cost[200005];


// Evaluate cost for root 1
void dfs(int u, int p) {
    for (auto edge: adj[u]) {
        int v = edge.first;
        int w = edge.second;
        if (v == p) continue;
        dfs(v,u);
        cost[1] += w;
    }
}

// Evaluate cost for all other roots
void reroot(int curr, int p){
    for (auto edge: adj[curr]) {
        int new_cap = edge.first;
        int w = edge.second;
        if (new_cap == p) continue;
        
        // weight = 0 means that 
        cost[new_cap] = cost[curr] + ((w == 0) ? 1 : -1);

        reroot(new_cap, curr);

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    eat.tie(NULL);

    eat >> n;

    // Build the adjacency list
    for (int i = 0; i < n-1; i++) {
        int u, v;
        eat >> u >> v;
        adj[u].push_back({v,0});
        adj[v].push_back({u,1});
    }

    // Initial DFS solution
    fill(cost, cost+n, 0);
    dfs(1, -1);

    reroot(1,-1);

    int min_inversions = cost[1];

    // Check the rest of the nodes
    for (int i = 2; i < n+1; i++) {
        min_inversions = min(min_inversions, cost[i]);
    }
    cout << min_inversions << endl;

    for (int i = 1; i < n; i++) {
        if (cost[i] == min_inversions) {
            cout << i << " ";
        }
    }
    if (cost[n] == min_inversions) cout << n;
    cout << endl;
    return 0;
}