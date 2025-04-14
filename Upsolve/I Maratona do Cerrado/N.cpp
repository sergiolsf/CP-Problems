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


int main () { 
    fastio()
    int m, k;
    cin >> m >> k;
    string s;
    cin >> s;

    if (m == 1) {
        int cod = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            cod = (cod + (int) (s[i]-'a'));
        }
        char a = ('a' + cod%26);
        char b = 'a' + (cod/26)%26;
        string ans = s;
        ans += b;
        ans += a;
        for (int i = s.size()-1; i>=0; i--) {
            ans += s[i];
        }
        cout << ans << endl;
    } else {
        int sz = s.size()/2 -1;
        bool flag = true;
        for (int i = 0; i < sz; i++) {
            if (s[i] != s[s.size()-1-i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            for (int i = 0; i < sz; i++) cout << s[i];
        } else {
            char a = s[sz+1], b = s[sz];
            int cod = 0;
            for (int i = 0; i < sz; i++) {
                cod = (cod + (int) (s[i]-'a'));
            }
            if (a == ('a' + cod%26) && b == ('a' + (cod/26)%26)) {
                for (int i = 0; i < sz; i++) cout << s[i];
            } else {
                for (int i = 0; i < sz; i++) cout << s[s.size()-1-i];
            }
        }

        cout << endl;
    }

    return 0;
}