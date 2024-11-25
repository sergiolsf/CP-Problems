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

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

signed main() {
    fastio();
    cin >> N;

    int a = 1, b = 1;
    for (int i = 1; i <= N; i++) {
        int A = a, B = b;
        a = B;
        b = A+B;
    }

    cout << a/gcd(a,b) << endl;
    
    return 0;
}