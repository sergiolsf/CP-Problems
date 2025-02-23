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
    string s;
    cin >> s;
    deque<char> dq;
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == '(' || s[i] == '<' || s[i] == '[') dq.push_front(s[i]);
        else {
            if (dq.empty()) {
                cout << "No\n";
                return 0;
            }
            char c = dq.front();
            dq.pop_front();
            if (c == '(' && s[i] == ')') continue;
            if (c == '<' && s[i] == '>') continue;
            if (c == '[' && s[i] == ']') continue;
            cout << "No\n";
            return 0;
        }
    }
    if (!dq.empty()) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";

    return 0;
}