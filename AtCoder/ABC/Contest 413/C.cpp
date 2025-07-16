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

signed main() {
    fastio();
    deque<pii> q;
    int Q; cin >> Q;

    while (Q--) {
        int t; cin >> t;
        if (t == 1) {
            int c, x; cin >> c >> x;
            q.push_back({c, x});
        } else {
            int k; cin >> k;
            int sum = 0, quant = 0;

            while (quant < k) {
                auto [c, x] = q.front();
                q.pop_front();

                if (quant + c > k) {
                    int g = k - quant;
                    quant = k;
                    sum += g*x;
                    q.push_front({c-g, x});
                } else {
                    quant += c;
                    sum += c*x;
                }
            }

            cout << sum  << endl;
        }
    }
  
    return 0;
}