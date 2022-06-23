#define contest1

#ifdef contest1
#include <stdio.h>
#define size 10000

void ReverseFile(FILE* read, FILE* write){
    char buffer[size] = { 0 };
    fgets(buffer, size, read);
    if (feof(read))
        return;
    ReverseFile(read, write);
    fputs(buffer, write);
}

int main(){
    FILE* read;
    FILE* write;
    read = fopen("input.txt", "r");
    write = fopen("output.txt", "w");
    ReverseFile(read, write);
    fclose(read);
    fclose(write);
    return 0;
}
#endif

#ifdef contest2
#include <stdio.h>
#define size 10000

void ReverseFile(FILE* read, FILE* write){
    char buffer[2] = { 0 };
    fgets(buffer, 2, read);
    if (feof(read))
        return;
    ReverseFile(read, write);
    fputs(buffer, write);
}

int main(){
    FILE* read;
    FILE* write;
    read = fopen("input.txt", "r");
    write = fopen("output.txt", "w");
    ReverseFile(read, write);
    fclose(read);
    fclose(write);
    return 0;
}
#endif

#ifdef contest3
#include <stdio.h>
#include <string.h>
#define size 100000
int IsDigit(symbol) {
    char a[10] = "1234567890";
    for (int i = 0; a[i]; ++i) {
        if (symbol == a[i] && symbol != '\n')
            return 1;
    }
    return 0;
}

int main(){
    FILE* fr;
    FILE* fw;
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    char buffer[size] = { 0 };
    int count = 0;
    while (fgets(buffer, size, fr)){
        for (int i = 0; i < strlen(buffer); ++i) {
            if (IsDigit(buffer[i])){
                count++;
            }
        }
    }
    fprintf(fw, "%d", count);
    fclose(fr);
    fclose(fw);
    return 0;
}
#endif

#ifdef contest4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 100000

int IsDigit(symbol) {
    char a[10] = "1234567890";
    for (int i = 0; a[i]; ++i) {
        if (symbol == a[i] && symbol != '\n')
            return 1;
    }
    return 0;
}
void null(char *string){
    for (int i = 0; i < strlen(string); ++i) {
        string[i] = '0';
    }
}

int main(){
    FILE* read;
    FILE * write;
    read = fopen("input.txt", "r");
    write = fopen("output.txt", "w+");
    char buffer[size] = { 0 }, find_number[size] = {0};
    int number, sum = 0, j = 0;
    while (fgets(buffer, size, read)) {
        int flag_digit = 1;
        for (int i = 0; i < strlen(buffer); ++i) {
            if (buffer[i] == ' ' || buffer[i] == '\0\n') {
                if (flag_digit) {
                    find_number[j] = '\0';
                    number = atoi(find_number);
                    sum += number;
                    null(find_number);
                }
                j = 0;
                flag_digit = 1;
            } else if (IsDigit(buffer[i]) && flag_digit == 1){
                find_number[j] = buffer[i];
                j++;
                flag_digit = 1;
            } else if (!IsDigit(buffer[i])){
                null(find_number);
                flag_digit = 0;
            }
        }
    }
    fprintf(write, "%d", sum);
    fclose(read);
    fclose(write);
    return 0;
}
#endif

#ifdef contest5
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define size 100000

void my_itoa(long i, char *string)
{
    int power = 0, j = 0;
    j = i;
    for (power = 1; j>10; j /= 10)
        power *= 10;
    for (; power>0; power /= 10)
    {
        *string++ = '0' + i / power;
        i %= power;
    }
    *string = '\0';
}

int AddTeam(char *teams, char *team, int index, char *indeks) {
    if (strstr(teams, team) == NULL) {
        my_itoa(index, indeks);
        strcat(teams, indeks);
        strcat(teams, team);
        strcat(teams, " | ");
        index++;
    }
    return index;
}

void AddDue(char *teams, char *team, char *poss, int pos, int *points){
    poss = strstr(teams, team) - 1;
    pos = atoi(poss);
    points[pos] += 1;
}

void AddWin(char *teams, char *team, char *poss, int pos, int *points, int *diffs, int diff){
    poss = strstr(teams, team) - 1;
    pos = atoi(poss);
    diffs[pos] += diff;
    points[pos] += 3;
}

int FindMax(const int *points, int max, int j, int count, int *max_indexes, const int *diffs, int *max_indexs){
    for (int i = 0; i < 10; ++i) {
        if (points[i] > max)
            max = points[i];
    }
    for (int i = 0; i < 10; ++i) {
        if (points[i] == max){
            count++;
            max_indexes[j] = i;
            j++;
        }
    }
    max = diffs[max_indexes[0]];
    for (int i = 0; i < count; ++i) {
        if (diffs[max_indexes[i]] >= max)
            max = diffs[max_indexes[i]];
    }
    j = 0;
    int count2 = 0;
    for (int i = 0; i < count; ++i) {
        if (diffs[max_indexes[i]] == max){
            count2++;
            max_indexs[j] = max_indexes[i];
            j++;
        }
    }
    return count2;
}

void PrintWinners(int *points, const int *mi, int *diffs, char *teams, FILE* write, int count){
    for (int i = 0; i < count; ++i) {
        int j = 0, index = 0;
        char *poss = NULL, indeks[2] = { 0 };
        index = mi[i];
        my_itoa(index, indeks);
        poss = strstr(teams, indeks) + 1;
        while (poss[j] != ' '){
            fprintf(write,"%c", poss[j]);
            j++;
        }
        fprintf(write, " %d %d\n", points[mi[i]], diffs[mi[i]]);
    }
}

void AddDiff(char *teams, char *team, char *poss, int pos, int *diffs, int diff_minus){
    poss = strstr(teams, team) - 1;
    pos = atoi(poss);
    printf("%d\n", diff_minus);
    diffs[pos] += diff_minus;
}

int main(){
    FILE* read;
    FILE* write;
    read = fopen("input.txt", "rt");
    write = fopen("output.txt", "wt");
    char team1[size] = { 0 }, team2[size] = { 0 };
    char teams[size] = { 0 }, indeks[2] = { 0 }, *poss = NULL;
    int score1 = 0, score2 = 0, index = 0, pos = 0, diff = 0, diff_minus = 0;
    int points[10] = { 0 }, diffs[10] = { 0 };
    while (fscanf(read, "%s - %s %d:%d", team1, team2, &score1, &score2) == 4){
        index = AddTeam(teams, team1, index, indeks);
        index = AddTeam(teams, team2, index, indeks);
        if (score1 == score2){
            AddDue(teams, team1, poss, pos, points);
            AddDue(teams, team2, poss, pos, points);
        }
        if (score1 > score2){
            diff = score1 - score2;
            diff_minus = score2 - score1;
            AddWin(teams, team1, poss, pos, points, diffs, diff);
            AddDiff(teams, team2, poss, pos, diffs, diff_minus);
        }
        if (score2 > score1){
            diff = score2 - score1;
            diff_minus = score1 - score2;
            AddWin(teams, team2, poss, pos, points, diffs, diff);
            AddDiff(teams, team1, poss, pos, diffs, diff_minus);
        }
    }
    int max_indexes[10] = { 0 }, max = points[0], count = 0, j = 0, max_indexs[10] = { 0 };
    count = FindMax(points, max, j, count,max_indexes, diffs, max_indexs);
    PrintWinners(points, max_indexs, diffs, teams, write, count);
    fclose(read);
    fclose(write);
    return 0;
}
#endif