#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int INF = 1'000'000'000'000'000'000;

signed main() {
    fastio();
    int n; cin >> n;
    vector<tuple<int,int,int>> v (n);
    for (auto &[a, b, c]: v) cin >> a >> b >> c; 

    int delta = 0;
    tuple<int,int,int> ans;
    for (int a = 0; a < 256; a++) {
        for (int b = 0; b < 256; b++) {
            for (int c = 0; c < 256; c++) {
                int sum = INF;
                for (int p = 0; p < n; p++) {
                    auto &[i, j, k] = v[p];
                    sum = min(sum, abs(i-a) + abs(j-b) + abs(k-c));
                }
                if (sum > delta) {
                    ans = {a, b, c};
                    delta = sum;
                }
            }
        }
    }

    auto &[a, b, c] = ans;
    cout << a << " " << b << " " << c << endl;
  
    return 0;
}