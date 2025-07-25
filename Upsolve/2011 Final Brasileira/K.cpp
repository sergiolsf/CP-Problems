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

int func (int &a, int &b, int &c) {
    if (a == b && b == c && a == c) return 1;
    if (a != b && a != c && b != c) return -1;
    if (a == b) return 0;
    if (a == c) {
        swap(b, c);
        return 0;
    }
    swap(a, c);
    return 0;
}

signed main() {
    fastio();
    int a, b, c; cin >> a >> b >> c;
    while (a != 0 || b != 0 || c != 0) {
        int res = func(a, b, c);
       
        if (res == -1) cout << "1 1 2\n";
        else if (res == 1) {
            if (a < 13) cout << a+1 << " " << a+1 << " " << a+1 << endl;
            else cout << "*\n";
        } else {
            if (b == 1 && c < 13) cout  << "1 1 " << c+1 << endl;
            else if (a == 1 && c == 13) cout << "1 2 2\n";
            else if (a != 13 && c == a-1) cout << a << " " << a << " " << a+1 << endl;
            else if (a == 13 && c == 12) cout << "1 1 1\n";
            else if (c != 13) {
                if (a < c+1) cout << a << " " << a << " " << c+1 << endl;
                else cout << c+1 << " " << a << " " << a << endl;
            }
            else if (c == 13) cout << 1 << " " << a+1 << " " << a+1 << endl;
        }


        cin >> a >> b >> c;
    }
  
    return 0;
}