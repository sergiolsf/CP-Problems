#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;

    bool primo = true;
    for (int i = 2; i*i <= n && primo; i++) {
        if (n%i == 0) primo = false;
    }

    if (primo == true) cout << "Eh primo!\n";
    else cout << "Nao eh primo!\n";
  
    return 0;
}
// 2147483647