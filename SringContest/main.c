#define contest5

#ifdef contest1
#include <stdio.h>
#define SIZE 100000

int main(){
    char str[SIZE] = { 0 };
    gets(str);
    int flag = 0, count = 0;
    for (int i  = 0; str[i] ;++i) {
        if (str[i] == ' ') {
            flag = 0;
            continue;
        }
        if (str[i] != ' ' && flag == 0) {
            flag = 1;
            count += 1;
        }
    }
    printf("%d\n", count);
    return 0;
}
#endif

#ifdef contest2
#include <stdio.h>
#include <string.h>
#define SIZE 100000
void ReverseWord(char *copy, const char *str, int start, int end){
    int c = 0;
    for (int j = start; j < end + 1; ++j) {
        copy[j] = str[end - c];
        c++;
    }
}

int main(){
    char str[SIZE] = { 0 };
    char copy[SIZE] = { 0 };
    gets(str);
    strcpy(copy, str);
    int start = 0, end = 0, count = 0, flag = 0;
    for (int i  = 0; str[i] ;++i) {
        if (str[i] == ' ') {
            flag = 0;
            if (count % 2 == 1) {
                ReverseWord(copy, str, start, end);
            }
        }
        if (str[i] != ' ') {
            if (flag == 0) {
                count += 1;
                flag = 1;
                start = i;
            }
            end = i;
        }
    }
    if (count % 2 == 1) {
        ReverseWord(copy, str, start, end);
    }
    printf("%s\n", copy);
    return 0;
}
#endif

#ifdef contest3
#include <stdio.h>
#define SIZE 100000

int main(){
    char str[SIZE] = { 0 };
    char ans[SIZE] = { 0 };
    gets(str);
    int j = 0;
    char a = "\0";
    for (int i = 0; str[i]; ++i) {
        if (str[i] != a) {
            ans[j] = str[i];
            a = str[i];
            j++;
        }
    }
    printf("%s\n", ans);
    return 0;
}
#endif

#ifdef contest4
#include <stdio.h>
#define SIZE 100000

int main() {
    char str[SIZE] = {0};
    gets(str);
    int count = 1;
    char a;
    for (int i = 0; str[i]; ++i) {
        if (str[i] != a) {
            if (count > 1){
                printf("(%d)", count);
                count = 1;
            }
            printf("%c", str[i]);
            a = str[i];
        } else {
            count++;
        }
    }
    if (count != 1)
        printf("(%d)", count);
    printf("\n");
    return 0;
}
#endif

#ifdef contest5
#include <stdio.h>
#define SIZE 100000
int CharIndex(const char *symols, char symbol){
    int index;
    for (int i = 0; symols[i]; ++i) {
        if (symols[i] == symbol)
            index = i;
    }
    return index;
}

int main() {
    char str[SIZE] = { 0 };
    char symbols[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890"};
    int universal[62] = { 0 };
    int slovo[62] = { 0 };
    gets(str);
    int count = 0, flag = 0, univ = 0, uniq = 0;
    for (int i  = 0; str[i] ;++i) {
        if (str[i] == ' ') {
            flag = 0;
        }
        if (str[i] != ' ') {
            int indeks = CharIndex(symbols, str[i]);
            if (flag == 0) {
                count += 1;
                flag = 1;
                for (int j = 0; j < 62; ++j) {
                    slovo[j] = 0;
                }
            }
            if (slovo[indeks] != 1){
                universal[indeks] += 1;
                slovo[indeks] += 1;
            }
        }
    }
    printf("Universal: ");
    for (int i = 0; i < 62; ++i) {
        if (universal[i] == count){
            printf("%c ", symbols[i]);
            univ = 1;
        }
    }
    if (univ == 0)
        printf("no");
    printf("\nUnique: ");
    for (int i = 0; i < 62; ++i) {
        if (universal[i] == 1){
            printf("%c ", symbols[i]);
            uniq = 1;
        }
    }
    if (uniq == 0)
        printf("no");
    return 0;
}
#endif