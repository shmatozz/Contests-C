#define practice

#ifdef practice
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void FillMatrix(int arr[][m]){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i][j] = rand() % 10;
        }
    }
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int arr[n][m];
    srand((unsigned) time(0));
    FillMatrix(arr);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
#endif

#ifdef contest1
#include <stdio.h>

int main(){
    int n, nomer, countL = 0, countR = 0, maxR, maxL;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &nomer);
    while (nomer != -1){
        countL = 0;
        countR = 0;
        maxL = arr[nomer-1];
        maxR = arr[nomer-1];
        for (int i = nomer; i < n; ++i) {
            if (arr[i] >= maxR){
                countR++;
                maxR = arr[i];
            }
        }
        for (int i = nomer - 2; i >= 0; --i) {
            if (arr[i] >= maxL){
                countL++;
                maxL = arr[i];
            }
        }
        printf("%d %d\n", countL, countR);
        scanf("%d", &nomer);
    }
    return 0;
}
#endif

#ifdef contest2
#include <stdio.h>

int main(){
    int n, c = 1, max, min, x;
    scanf("%d", &n);
    scanf("%d", &x);
    max = x;
    min = x;
    while (c != n){
        scanf("%d", &x);
        if (x > max)
            max = x;
        if (x < min)
            min = x;
        c += 1;
    }
    if (max % 10 + max / 10 == min % 10 + min / 10)
        printf("%d %d\nYes\n", max % 10 + max / 10, min % 10 + min / 10 );
    else
        printf("%d %d\nNo\n", max % 10 + max / 10, min % 10 + min / 10 );
    return 0;
}
#endif

#ifdef contest3
#include <stdio.h>

int main(){
    int n, c = 0;
    float average, sum = 0;
    scanf("%d", &n);
    int arr[n];
    int otv[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    average = sum / n;
    for (int i = 0; i < n; ++i) {
        if (arr[i] >= average){
            otv[c] = arr[i];
            c += 1;
        }
    }
    for (int i = n-1; i >= 0; --i) {
        if (arr[i] < average){
            otv[c] = arr[i];
            c += 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d\n", otv[i]);
    }
    return 0;
}
#endif

#ifdef contest4
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    int arr2[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; ++i) {
        arr2[i] = (arr[n-i-1] % 10) + (arr[n-i-1] % 100 / 10) + (arr[n-i-1] % 1000 / 100) + (arr[n-i-1] % 10000 / 1000);
    }
    for (int i = 0; i < n; ++i) {
        printf("%d\n", arr2[i]);
    }
    return 0;
}
#endif

#ifdef contest5
#include <stdio.h>
#include <math.h>

int main(){
    int n, k, mod3, mod6, prom;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &k);
    while ( k != -1 ) {
        mod3 = 0;
        mod6 = 0;
        prom = abs(arr[k - 1]);
        if (arr[k - 1] % 3 == 0)
            mod3 = 1;
        if (prom == 0) {
            mod6 = 1;
        } else {
            while (prom > 0) {
                if ((prom % 10 % 2 == 0 && arr[k - 1] % 3 == 0)) {
                    mod6 = 1;
                    break;
                }
                prom /= 10;
            }
        }
        if (mod3 && mod6)
            printf("Yes Yes\n");
        else if (mod3 && !mod6)
            printf("Yes No\n");
        else if (!mod3 && mod6)
            printf("No Yes\n");
        else
            printf("No No\n");
        scanf("%d", &k);
    }
}
#endif

#ifdef contest6
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    int cmax = 0, c, max;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; ++i) {
        c = 0;
        for (int j = i; j < n; ++j) {
            if (arr[i] == arr[j])
                c += 1;
        }
        if (c > cmax) {
            cmax = c;
            max = arr[i];
        }
    }
    printf("%d\n", max);
    return 0;
}
#endif

#ifdef contest7
#include <stdio.h>

int main(){
    char skobka;
    int open = 0, closed = 0;
    while (1){
        scanf("%c", &skobka);
        if (skobka == '(' && open >= 0)
            open++;
        if (skobka == ')' && open > 0)
            open--;
        else if (skobka == ')' && open == 0)
            open--;
        if (skobka == '\n')
            break;
    }
    if (open == closed)
        printf("Yes\n");
    else printf("No\n");
    return 0;
}
#endif

#ifdef contest8
#include <stdio.h>
#define SIZE 1000

int main(){
    char arr[SIZE] = {};
    char lasttype;
    int openKRYG = 0, openSQR = 0, openFIG = 0, flag = 1;
    scanf("%s", &arr);
    for (int i = 0; i < SIZE; ++i) {
        if (arr[i] != '\0') {
            if (arr[i] == '(' && openKRYG >= 0)
                openKRYG++;
            if (arr[i] == ')' && openKRYG > 0) {
                openKRYG--;
                if (lasttype == '[' || lasttype == '{')
                    flag = 0;
            }
            else if (arr[i] == ')' && openKRYG == 0)
                openKRYG--;
            if (arr[i] == '[' && openSQR>= 0)
                openSQR++;
            if (arr[i] == ']' && openSQR > 0) {
                openSQR--;
                if (lasttype == '(' || lasttype == '{')
                    flag = 0;
            }
            else if (arr[i] == ']' && openSQR == 0)
                openSQR--;
            if (arr[i] == '{' && openFIG >= 0)
                openFIG++;
            if (arr[i] == '}' && openFIG > 0) {
                openFIG--;
                if (lasttype == '[' || lasttype == '(')
                    flag = 0;
            }
            else if (arr[i] == '}' && openFIG == 0)
                openFIG--;
            lasttype = arr[i];
        } else {
            break;
        }
    }
    if ((openKRYG == 0) && (openSQR == 0) && (openFIG == 0) && flag == 1)
        printf("Yes\n");
    else printf("No\n");
    return 0;
}
#endif