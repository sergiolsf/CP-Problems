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
    int n; cin >> n;
    string s; cin >> s;
    deque<int> dq;
    int maior = n, menor = 1;
    for (int i = n-2; i >= 0; i--) {
        if (s[i] == '<') {
            dq.push_back(menor);
            menor++;
        } else {
            dq.push_back(maior);
            maior--;
        }
    }
    dq.push_back (menor);
    int i = 0;
    while (!dq.empty()) {
        cout << dq.back();
        i++;
        cout << (i == n ? "\n" : " ");
        dq.pop_back();
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