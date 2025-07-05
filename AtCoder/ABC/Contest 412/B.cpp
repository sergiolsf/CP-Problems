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

bool maiuscula(char c) {
    int d = c-'A';
    if (d >= 0 && d <= 26) return true;
    return false;
}

signed main() {
    fastio();
    string s, t; cin >> s >> t;

    set<char> st;
    for (int i = 0; i < t.size(); i++) {
        st.insert(t[i]);
    }

    for (int i = 1; i < s.size(); i++) {
        if (maiuscula(s[i])) {
            if (!st.count(s[i-1])) {
                cout << "No\n";
                return 0;
            }
        }
    }

    cout << "Yes\n";
  
    return 0;
}