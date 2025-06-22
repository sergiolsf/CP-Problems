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

const int MAX_N = 200'005;

vector<tuple<int,int,string>> v(MAX_N);
string vazio = "";

signed main() {
    fastio();
    int n, q; cin >> n >> q;
    for (int i = 1; i <= q; i++) {
        int op, p; cin >> op >> p;
        if (op == 1) {
            auto &[a, b, c] = v[i];
            a = op; b = p; c = vazio;
        } else if (op == 2) {
            string s; cin >> s;
            auto &[a, b, c] = v[i];
            a = op; b = p; c = s;
        } else {
            auto &[a, b, c] = v[i];
            a = op; b = p; c = vazio;
        }
    }

    stack<string> st;
    int atual = 0; // 0 = servidor
    for (int i = q; i >= 1; i--) {
        auto [op, p, s] = v[i];
        if (atual == 0) {
            if (op != 3) continue;
            atual = p;
        } else {
            if (op == 3) continue;
            if (p != atual) continue;
            if (op == 1) atual = 0;
            else {
                st.push(s);
            }
        }
    }

    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }
    cout << endl;

  
    return 0;
}