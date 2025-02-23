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
    char ult = 'A';
    int ini = -1, fim = -1;
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == 'W' && ult != 'W') {
            ini = i;
        } else if (s[i] == 'A' && ult == 'W') {
            for (int j = ini+1; j <= i; j++) s[j] = 'C';
            s[ini] = 'A';
        }

        ult = s[i];
    }



    cout << s << endl;
  
    return 0;
}