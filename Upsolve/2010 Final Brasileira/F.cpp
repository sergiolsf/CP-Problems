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

int num(char c) {
    int d = c-'A';
    if (d >= 0 && d < 27) return d;
    d = c-'a';
    return d;
}

bool func(string s) {
    int a = num(s[0]);
    bool f = false;
    for (int i = 1; i < (int) s.size(); i++) {
        if (f) {
            if (num(s[i]) != a) return false;
            f = false;
        }
        if (s[i] == ' ') f = true;
    }
    return true;
}

signed main() {
    fastio();
    string s;
    getline(cin, s);
    while (s != "*") {
        if (func(s)) cout << "Y\n";
        else cout << "N\n";
        getline(cin, s);
    }
  
    return 0;
}