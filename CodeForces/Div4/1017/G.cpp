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

void solve() {
    int q; cin >> q;
    deque<int> dq;
    bool normal = true;
    int sum = 0, sumPot = 0, sumPotInv = 0, n = 0;
    while (q--) {
        int s; cin >> s;
        if (s == 1) {
            if (normal) {
                int d = dq.front();
                dq.pop_front();
                dq.push_back(d);
                sumPot += (sum-d) - (n-1)*d;
                sumPotInv += -(sum-d) + (n-1)*d;
                cout << sumPot << endl;
            } else {
                int d = dq.back();
                dq.pop_back();
                dq.push_front(d);
                sumPotInv += (sum-d) - (n-1)*d;
                sumPot += -(sum-d) + (n-1)*d;
                cout << sumPotInv << endl;
            }
        } else if (s == 2) {
            normal = !normal;
            if (normal) cout << sumPot << endl;
            else cout << sumPotInv << endl;
        } else {
            int k; cin >> k;
            sum += k;
            n++;
            if (normal) {
                dq.push_front(k);
                sumPot += k*n;
                sumPotInv += sum;
                cout << sumPot << endl;
            } else {
                dq.push_back(k);
                sumPotInv += k*n;
                sumPot += sum;
                cout << sumPotInv << endl;
            }
        }
    }

}

signed main() {
    fastio();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }    
    return 0;
}