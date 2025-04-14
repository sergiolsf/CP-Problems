#include <bits/stdc++.h>
using namespace std;

#define int long long

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

bool letra (char c) {
    int a = c-'a';
    int A = c-'A';
    if (a < 26 && a >= 0) return true;
    if (A < 26 && A >= 0) return true;
    return false;
}

signed main() {
    fastio();
    string s;
    while (getline(cin,s)) {
        int sz = s.size();
        for (int i = 0; i < sz; i++) {
            if (s[i] == 'C') {
                if (i-1 >= 0 && letra(s[i-1]) && i+1 < sz && s[i+1] == '-') cout << "-se";
                else if (i-1 >= 0 && letra(s[i-1]) && (i+1 == sz || !letra(s[i+1]))) cout << "-se";
                else cout << 'C';
            } else {
                cout << s[i];
            }
        }
        cout << endl;
    }

    return 0;
}