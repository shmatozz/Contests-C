#define contest7   // <-----  ВЫБЕРИ ПРОГУ ТУТ

#ifdef practice
#include <stdio.h>

int main(){
    int n, cchet = 0, cnechet = 0;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0)
            cchet++;
        else
            cnechet++;
    }
    if (cchet > cnechet)
        printf("Chet\n");
    else if (cchet == cnechet)
        printf("=\n");
    else
        printf("Nechet\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}
#endif

#ifdef contest1
#include <stdio.h>

int main(){
    int n, elements, change;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &elements);
        arr[i] = elements;
    }
    for (int i = 0; i < n / 2; ++i) {
        change = arr[n-1-i];
        arr[n-1-i] = arr[i];
        arr[i] = change;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d\n", arr[i]*arr[i]);
    }
    return 0;
}
#endif

#ifdef contest2
#include <stdio.h>

int main(){
    int n, m, count = 0, flag = 1;
    scanf("%d", &n);
    int x[n];
    for (int i = 0; i < n; ++i) {    // Ввод массива Х
        scanf("%d", &x[i]);
    }
    scanf("%d", &m);
    int y[m], z[1000];
    for (int i = 0; i < m; ++i) {    // Ввод массива Y
        scanf("%d", &y[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            flag = 1;
            if (x[i] == y[j]) {
                for (int k = 0; k < count; ++k) {
                    if (x[i] == z[k])
                        flag = 0;
                }
                if (flag == 1) {
                    z[count] = y[j];
                    count += 1;
                }
            }
        }
    }
    printf("%d\n", count);
    for (int i = 0; i < count; ++i) {
        printf("%d\n", z[i]);
    }
    return 0;
}
#endif

#ifdef contest3
#include <stdio.h>
#include <math.h>

int main(){
    long long n, element, k, minlen, otv;
    scanf("%lld", &n);
    long long arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &element);
        arr[i] = element;
    }
    scanf("%lld", &k);
    k = abs(k);
    minlen = k;
    for (long long i = 0; i < n; ++i) {
        if (abs(k - abs(arr[i])) < minlen) {
            minlen = abs(k - abs(arr[i]));
            otv = i + 1;
        }
    }
    printf("%lld", otv);
    return 0;
}
#endif

#ifdef contest4
#include <stdio.h>

int main() {
    int n, element, count = 0;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &element);
        arr[i] = element;
    }
    for (int i = 1; i < n-1; ++i) {
        if ((arr[i-1] > arr[i]) && (arr[i+1] > arr [i]))
            count += 1;
    }
    if (arr[0] < arr[1] && arr[0] < arr[n-1])
        count += 1;
    if (arr[n-1] < arr[n-2] && arr[n-1] < arr[0])
        count += 1;
    printf("%d\n", count);
    return 0;
}
#endif

#ifdef contest5
#include <stdio.h>

int main(){
    int n, element;
    float count, sum = 0;
    scanf("%d", &n);
    int arr[n];
    float z[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &element);
        arr[i] = element;
        sum += element;
    }
    count = sum / n ;
    printf("%.2f", count);
    for (int i = 0; i < n; ++i) {
        z[i] = arr[i] - count;
        printf("%.2f\n", z[i]);
    }
}
#endif

#ifdef contest6
#include <stdio.h>

int main() {
    int n, p;
    float element, change;
    scanf("%d", &n);
    float arr[n];
    scanf("%d", &p);
    for (int i = 0; i < n; i++) {
        scanf("%f", &element);
        arr[i] = element;
    }
    for(int i = 0; i < p; i++){
        change = arr[0];
        arr[0] = arr[n-1];
        for (int i = n-1; i > 1; --i) {
            arr[i] = arr[i-1];
        }
        arr[1] = change;
    }
    for(int i = 0; i < n;i++) {
        printf("%.2f\n", arr[i]);
    }
    return 0;
}
#endif

#ifdef contest7
#include <stdio.h>
enum stack {stack_push, stack_pop, stack_top, stack_max, stack_min, stack_exit};

#define n 100000
int main() {
    int arr[n], maxa[n], mina[n];
    int count = 0, max = -2147483648, min = 2147483647;
    enum stack act = stack_exit;
    while (1) {
        scanf("%d", &act);
        switch (act) {
            case stack_push:
                if (count == n) {
                    printf("Overflow\n");
                } else {
                    count++;
                    scanf("%d", &arr[count]);
                    max = arr[count] > max ? arr[count] : max;
                    maxa[count] = max;
                    min = arr[count] < min ? arr[count] : min;
                    mina[count] = min;
                    }
                break;
            case stack_pop:
                if (count == 0) {
                    printf("Underflow\n");
                    max = -2147483648;
                    min = 2147483647;
                } else {
                    count--;
                    if (count == 0){
                        max = -2147483648;
                        min = 2147483647;
                    } else {
                        max = maxa[count];
                        min = mina[count];
                    }
                }
                break;
            case stack_top:
                if (count == 0) {
                    printf("Stack is empty\n");
                } else {
                    printf("%d\n", arr[count]);
                }
                break;
            case stack_max:
                if (count == 0) {
                    printf("Stack is empty\n");
                } else {
                    printf("%d\n", maxa[count]);
                }
                break;
            case stack_min:
                if (count == 0) {
                    printf("Stack is empty\n");
                } else {
                    printf("%d\n", mina[count]);
                }
                break;
            case stack_exit:
                return 0;
                }
        }
    }
#endif

#ifdef chet_index
#include <stdio.h>

int main(){
    int n, element;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &element);
        arr[i] = element;
    }
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0)
            printf("%d ", arr[i]);
    }
    return 0;
}
#endif

#ifdef chet_element
#include <stdio.h>

int main(){
    int n, count = 0;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (arr[i] % 2 == 0)
            count++;
    }
    printf("%d", count);
    return 0;
}
#endif

#ifdef polozit_element
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int arr[n], elements;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &elements);
        arr[i] = elements;
    }
    for (int i = 0; i < n; ++i) {
        if (arr[i] > 0)
            printf("%d ", arr[i]);
    }
    return 0;
}
#endif

#ifdef kolvo_bol_prev
#include <stdio.h>

int main(){
    int n, element, count = 0;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &element);
        arr[i] = element;
    }
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i+1] > arr[i])
            count += 1;
    }
    printf("%d\n", count);
    return 0;
}
#endif

#ifdef same_znak
#include <stdio.h>

int main(){
    int n, flag = 0, elements;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &elements);
        arr[i] = elements;
    }
    for (int i = 0; i < n - 1; ++i) {
        if ((arr[i] > 0 && arr[i+1] > 0) || (arr[i] < 0 && arr[i+1] < 0))
            flag = 1;
    }
    if (flag)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
#endif

#ifdef perestanovka_obr
#include <stdio.h>

int main(){
    int n, elements, change;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &elements);
        arr[i] = elements;
    }
    for (int i = 0; i < n / 2; ++i) {
        change = arr[n-1-i];
        arr[n-1-i] = arr[i];
        arr[i] = change;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}
#endif

#ifdef perestanovka_sosedei
#include <stdio.h>

int main(){
    int n, elements, change;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &elements);
        arr[i] = elements;
    }
    for (int i = 0; i < n-1; ++i) {
        if (i % 2 == 0){
            change = arr[i+1];
            arr[i+1] = arr[i];
            arr[i] = change;
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}
#endif

#ifdef sdvig
#include <stdio.h>

int main(){
    int n, elements, change;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &elements);
        arr[i] = elements;
    }
    change = arr[0];
    arr[0] = arr[n-1];
    for (int i = n-1; i > 1; --i) {
        arr[i] = arr[i-1];
    }
    arr[1] = change;
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}
#endif

#ifdef kolvo_razlich
#include <stdio.h>

int main(){
    int n, element, count = 1, current;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &element);
        arr[i] = element;
    }
    current = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > current) {
            current = arr[i];
            count += 1;
        }
    }
    printf("%d\n", count);
    return 0;
}
#endif

#ifdef fizra
#include <stdio.h>

int main(){
    int n, element, rostpeti, otv;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &element);
        arr[i] = element;
    }
    scanf("%d", &rostpeti);
    for (int i = 0; i < n-1; ++i) {
        if ((rostpeti <= arr[i]) && (rostpeti > arr[i+1]))
            otv = i + 2;
        else if (rostpeti <= arr[n-1])
            otv = n+1;
    }
    printf("%d", otv);
    return 0;
}
#endif

#ifdef double_perevorot
#include <stdio.h>

int main(){
    int n, a, b, c, d, element, change;
    scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &element);
        arr[i] = element;
    }
    for (int i = 0; i < (b-a) / 2 + 1; ++i) {
        change = arr[i+a-1];
        arr[i+a-1] = arr[b-i-1];
        arr[b-i-1] = change;
    }
    for (int i = 0; i < (d-c) / 2 + 1; ++i) {
        change = arr[i+c-1];
        arr[i+c-1] = arr[d-i-1];
        arr[d-i-1] = change;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}
#endif

#ifdef super_sdvig
#include <stdio.h>

int main(){
    int n, k, element, change;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &element);
        arr[i] = element;
    }
    scanf("%d", &k);
    for (int i = 0; i < (k % n); ++i) {
        change = arr[0];
        arr[0] = arr[n-1];
        for (int j = 1; j < n - 1; ++j) {
            arr[j] = change;
            printf("s");
            change = arr[j+1];
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d", arr[i]);
    }
    return 0;
}
#endif

#ifdef shariki
#include <stdio.h>

int main(){
    int n, element, count = 1, otv = 0;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &element);
        arr[i] = element;
    }
    for (int i = 0; i < n-1; ++i) {
        if (arr[i] == arr[i+1])
            count += 1;
        else {
            if (count >= 3) {
                otv += count;
                count = 1;
            }
        }
    }
    printf("%d", otv);
    return 0;
}
#endif