#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int N;
vi v(31);
vi a;

signed main() {
    fastio();
    cin >> N;
    a.resize(N+1);

    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= N; i++) {
        int exp_two = 1;
        for (int j = 0; j <= 30; j++) {
            if (a[i] & exp_two) {
                v[j]++;
            }
            exp_two *= 2;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (i > 1) cout << " ";
        int exp_two = 1;
        int num = 0;
        for (int j = 0; j <= 30; j++) {
            if (v[j] > 0) {
                num += exp_two;
                v[j]--;
            }
            exp_two *= 2;
        }
        cout << num;
    }

    cout << endl;    
    return 0;
}