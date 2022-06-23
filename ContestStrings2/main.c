#define contest4

#ifdef contest1
#include <stdio.h>
#include <string.h>
#define size 100000

int main(){
    char str[size] = { 0 };
    char chet[size] = { 0 }, nechet[size] = { 0 };
    int n = 0, m = 0;
    gets(str);
    for (int i = 0; str[i]; ++i) {
        if (i % 2 == 0){
            chet[n] = str[i];
            n++;
        }
        else if (i % 2 != 0){
            nechet[m] = str[i];
            m++;
        }
    }
    printf("%s", strcat(chet,nechet));
    return 0;
}
#endif

#ifdef contest2
#include <stdio.h>
#include <string.h>
#define size 100000
int IsDigit(symbol){
    char a[10] = "1234567890";
    for (int i = 0; a[i]; ++i) {
        if (a[i] == symbol)
            return 1;
    }
    return 0;
}

int main(){
    char str[size] = { 0 };
    char letters[size] = { 0 }, numbers[size] = { 0 };
    int n = 0, m = 0;
    gets(str);
    for (int i = 0; str[i]; ++i) {
        if (IsDigit(str[i])) {
            numbers[n] = str[i];
            n++;
        }
        else {
            letters[m] = str[i];
            m++;
        }
    }
    printf("%s", strcat(letters,numbers));
    return 0;
}
#endif

#ifdef contest3
#include <stdio.h>
#include <string.h>
#define size 100000
int main(){
    char str[size] = { 0 }, no_space[size] = { 0 };
    int n = 0;
    gets(str);
    for (int i = 0; str[i] ; ++i) {
        if (str[i] != ' '){
            no_space[n] = str[i];
            n++;
        }
    }
    for (int i = 0; i < strlen(no_space)/2; ++i) {
        if(no_space[i] != no_space[strlen(no_space) - i - 1]){
            printf("no");
            return 0;
        }
    }
    printf("yes");
    return 0;
}
#endif

#ifdef contest4
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define size 100
int PrintResult(int goool1, int goool2, char *team_1, char *team_2, char *otv, int c1){
    if (goool1 == goool2){
        strcat(otv, "draw");
        strcat(otv, "\n");
    } else if (goool1 > goool2){
        strcat(otv, team_1);
        strcat(otv, "\n");
        c1 += 1;
        return c1;
    } else if (goool1 < goool2){
        strcat(otv, team_2);
        strcat(otv, "\n");
        return c1;
    }
}

int main(){
    char team1[size] = { 0 }, team2[size] = { 0 }, x[1] = { 0 }, otv[size] = { 0 };
    char score_all[10] = { 0 }, score1[10] = { 0 }, sc1[5] = { 0}, sc2[5] = {0};
    int flag = 0, n = 0, gol1, gol2, all1, all2, c = 0;
    scanf("%s", team1);
    scanf("%s%s", x, team2);
    scanf("%s", score_all);
    scanf("%s", score1);
    for (int i = 1; i < strlen(score1) - 1; ++i) {
        if (score1[i] == ':') {
            flag = 1;
            n = 0;
            continue;
        }
        if (flag == 0) {
            sc1[n] = score1[i];
            n++;
        }
        if (flag == 1) {
            sc2[n] = score1[i];
            n++;
        }
    }
    gol1 = atoi(sc1);
    gol2 = atoi(sc2);
    n = 0;
    flag = 0;
    for (int i = 0; i < strlen(score_all); ++i) {
        if (score_all[i] == ':') {
            flag = 1;
            n = 0;
            continue;
        }
        if (flag == 0) {
            sc1[n] = score_all[i];
            n++;
        }
        if (flag == 1) {
            sc2[n] = score_all[i];
            n++;
        }
    }
    all1 = atoi(sc1);
    all2 = atoi(sc2);
    c = PrintResult(gol1, gol2, team1, team2, otv, c);
    c = PrintResult(all1 - gol1, all2 - gol2, team1, team2, otv, c);
    c = PrintResult(all1, all2, team1, team2, otv, c);
    if (c == 3){
        printf("%s\n", team1);
    } else if (c == 0)
        printf("%s\n", team2);
    else
        printf("%s\n", otv);
    return 0;
}
#endif

#ifdef contest5
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int IsDigit(symbol) {
    char a[10] = "1234567890";
    for (int i = 0; a[i]; ++i) {
        if (symbol == a[i])
            return 1;
    }
    return 0;
}
void null(char *string){
    for (int i = 0; i < strlen(string); ++i) {
        string[i] = '0';
    }
}

int main() {
    char expression[1000000] = {0}, number[100000] = {0};
    int ans = 0, n = 0, intnum;
    gets(expression);
    for (int i = 0; i < strlen(expression); ++i) {
        if (IsDigit(expression[i]) == 0) {
            number[n] = '\0';
            intnum = atoi(number);
            ans += intnum;
            null(number);
            n = 0;
        }
        number[n] = expression[i];
        n++;
    }
    number[n] = '\0';
    intnum = atoi(number);
    ans += intnum;
    printf("%d", ans);
    return 0;
}
#endif