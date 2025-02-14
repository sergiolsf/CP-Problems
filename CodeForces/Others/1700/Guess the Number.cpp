#include <bits/stdc++.h>

signed main() {
    int l = 1;
    int r = 1000001;
    while (r-l != 1) {
        char c[3];
        int m = (r+l)/2;
        printf("%d\n", m);
        fflush(stdout);
        scanf("%s", c);
        if (strcmp(c,"<") == 0) { 
            r = m;
        }
        else l = m;
    }
    printf("! %d\n", l);
    fflush(stdout);
  
    return 0;
}