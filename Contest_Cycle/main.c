#define con6
#include <stdio.h>
#include <math.h>

#ifdef sovchisl
int main(){
    int n = 0, count = 0, flag;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        flag = 0;
        for (int j = 2; j < (int)sqrt(i) + 1; j++) {
            if (i % j == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            count += 1;
        }
    }
    printf("%d\n", count);
    return 0;
}
#endif

#ifdef con3
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    while (n > 0){
        for (int i = 0; i < n; ++i) {
            printf("*");
        }
        printf("\n");
        n -= 1;
    }
}
#endif

#ifdef con4
#include <stdio.h>

int main(){
    int n, nmax = 0;
    scanf("%d", &n);
    while (n > 0){
        if (n % 10 > nmax)
            nmax = n % 10;
        n = n / 10;
    }
    printf("%d\n", nmax);
}
#endif

#ifdef con5
#include <stdio.h>

int main(){
    int n, m, a, max, min;
    scanf("%d%d", &n, &m);
    a = 0;
    if (n > m) {
        max = n;
        min = m;
    }
    else {
        max = m;
        min = n;
    }
    while (max > 0) {
        a = a * 10 + max % 10;
        max = max / 10;
    }
    if (a == min)
        printf("Yes\n");
    else
        printf("No\n");
}
#endif

#ifdef con6
#include <stdio.h>

int main(){
    int n, m, k;
    scanf("%d %d", &n, &m);
    scanf("%d", &k);
    while (k > 0){
        if (n % k == 0)
            n -= m / k;
        else if (m % k == 0)
            m -= n / k;
        printf("%d %d", n, m);
        scanf("&d", &k);
    }
    return 0;
}
#endif

#ifdef con7
#include <stdio.h>
#include <math.h>

int main (){
    int a, b, c, n;
    scanf("%d", &n);
    for (a = 1; a <= n; a++)
        for (b = 1; b <= n; b++)
            for (c = 1; c <= n; c++)
                if ((c * c == (a * a) + (b * b)) && (a < b))
                    printf("%d %d %d\n", a, b, c);
    return 0;
}
#endif

#ifdef con8
#include <stdio.h>

int main(){
    int a, sum = 0, flag = 0, chetn = 0;
    scanf("%d", &a);
    while (a != -1){
        sum = sum + a;
        if (a % 2 == 0)
        {
            chetn = 1;
        }
        if ((chetn == 1) && (sum % 3 == 0) && (flag == 0))
        {
            printf("Stop\n");
            flag = 1;
        }
        else if (flag != 1)
        {
            printf("No\n");
        }
        scanf("%d", &a);
    }
    return 0;
}
#endif

#ifdef con9
#include <stdio.h>

int main(){
    int n1, n2, res;
    char op;
    scanf("%d", &n1);
    scanf("%c", &op);
    scanf("%c", &op);
    res = n1;
    while (op != '='){
        scanf("%d", &n2);
        if (op == '+') {
            res = res + n2;
        }
        if (op == '-') {
            res = res - n2;
        }
        if (op == '*') {
            res = res * n2;
        }
        if (op == '/') {
            res /= n2;
        }
        if (op == '%') {
            res = res % n2;
        }
        if (op == '=') {
            break;
        }
        scanf("%c", &op);
        scanf("%c", &op);
    }
    printf("%d\n", res);
    return 0;
}
#endif

#ifdef con10
#include <stdio.h>

int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (((a == b) && (a>0)) || ((b == c) && (b>0)) || ((a == c) && (a>0)))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
#endif