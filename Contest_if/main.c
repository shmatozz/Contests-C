#define deadinside
#include <stdio.h>

#ifdef numbers2
  int main() {
    int a, b, a1, a2, b1, b2;
    printf("Input 2 numbers:\n");
    scanf("%d%d", &a, &b);
    a1 = a % 10;
    a2 = a / 10;
    b1 = b % 10;
    b2 = b / 10;
    if (((a1 == b1) && (a2 == b2)) || ((a2 == b1) && (a1 == b2)))
        printf("Yes!\n");
    else
        printf("No\n");
    return 0;
}
#endif

#ifdef deadinside
#include <stdio.h>
#include <windows.h>

int main(){
    int i = 1000;
    while (i > 0) {
        if (i == 6)
            printf("%d - 7\n%d\n", i, i - 7);
        else
            printf("%d - 7\n", i);
        i = i -7;
        fflush(stdin);
        Sleep(100);
    }
    return 0;
}
#endif

#ifdef contest_if1
int main(){
    int a;
    scanf("%d", &a);
    if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
#endif

#ifdef contest_if2
int main(){
    int a, a1, a2 , a3, a4, a5, a6;
    scanf("%d", &a);
    a1 = a % 10;
    a2 = a % 100 / 10;
    a3 = a % 1000 / 100;
    a4 = a % 10000 / 1000;
    a5 = a % 100000 / 10000;
    a6 = a % 1000000 / 100000;
    if ((a1 + a2 + a3) == (a4 + a5 + a6))
        printf("Happy");
    else
        printf("Unhappy");
    return 0;
}
#endif

#ifdef contest_if3
int main(){
    int a, a1, a2 , a3, a4, a5, a6;
    scanf("%d", &a);
    a1 = a % 10;
    a2 = a % 100 / 10;
    a3 = a % 1000 / 100;
    a4 = a % 10000 / 1000;
    a5 = a % 100000 / 10000;
    a6 = a % 1000000 / 100000;
    if ((a1 == a6) && (a2 == a5) && (a3 == a4))
        printf("Palindrom\n");
    else
        printf("Non palindrom\n");
    return 0;
}
#endif

#ifdef contest_if4
int main() {
    int a, c = 0;
    scanf("%d", &a);
    for (int i = 0; i < 5; ++i) {
        if ((a % 10) % 2 == 1 || (a % 10) % 2 == -1)
            c += 1;
        a /= 10;
    }
    printf("%d\n", c);
    return 0;
}
#endif

#ifdef contest_if5
#include <math.h>

int main(){
    int s, r;
    scanf("%d%d", &s, &r);
    double squareprice, circleprice;
    squareprice = s*s;
    circleprice = 3.14 * r * r;
    printf("%.2f %.2f\n", squareprice, circleprice);
    if (squareprice > circleprice)
        printf("Square is bigger\n");
    if (circleprice > squareprice)
        printf("Circle is bigger\n");
    if (circleprice == squareprice)
        printf("Equal\n");
    if (s >= 2 * r)
        printf("Circle in square\n");
    else if (2 * r >= sqrt(s*s + s*s))
        printf("Square in circle\n");
    else
        printf("Impossible\n");
    return 0;
}
#endif

#ifdef contest_if6
#include <math.h>

int main() {
    float a, b, c, s, polup, max, sum;
    scanf("%f%f%f", &a, &b, &c);
    if (a > b)
        if (a > c)
            max = a;
        else
            max = c;
    else if (b > c)
        max = b;
    else
        max = c;
    sum = a + b + c;
    polup = (a + b + c) / 2;
    if (sum - max > max) {
        s = sqrt(polup * (polup - a) * (polup - b) * (polup - c));
        printf("%.2f\n", s);
    } else
        printf("0\n");
    return 0;
}
#endif

#ifdef contest_if7
int main(){
    int a;
    scanf("%d", &a);
    switch (a) {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
        case 7:
            printf("Sunday\n");
            break;
        default:
            printf("Wrong day number\n");
            break;
    }
    return 0;
}
#endif

#ifdef contest_if8
int main(){
    float c, t, p, n;
    scanf("%f%f%f", &t, &p, &n);
    if (n != 7 && n != 6)
        c = t * p;
    else {
        if (t >= 10)
            c = (t * p) * 0.8;
        else
            c = t * p;
    }
    printf("%.2f", c);
    return 0;
}
#endif

#ifdef contest_if9
int main(){
    float health, damage;
    scanf("%f%f", &health, &damage);
    if (health - damage > 0.01)
        printf("%.2f\n", health - damage);
    else
        printf("0\n");
    return 0;
}
#endif

#ifdef contest_if10
int main(){
    float n, m;
    char op;
    scanf("%f%c%f", &n, &op, &m);
    if (op == '+')
        printf("%.2f", n + m);
    else if (op == '-')
        printf("%.2f", n - m);
    return 0;
}
#endif