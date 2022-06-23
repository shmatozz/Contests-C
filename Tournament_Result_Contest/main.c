#define task2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef task2
typedef struct team
{
    char name[100];
    char enemies[10][100];
    int games_played[10];
    int games_played_ef[10]; // Enemy field
    int games_win[10];
    int count_goals[10];
    int cur;
}TEAM;

typedef struct ArrayOfTeams
{
    TEAM* arr;
    int max_size;
    int current;
}ARRAY_OF_TEAMS;

void PrintTeamInfo(TEAM *t, FILE *write);

void InitCur(TEAM a);

int NotIn2(TEAM* t, char* teamName);

void InitCur(TEAM a) {
    a.cur = 0;
}

void InitTeamsArray(ARRAY_OF_TEAMS* ta)
{
    ta->current = ta->max_size = 0;
    ta->arr = NULL;
}

void ReallocationArray(ARRAY_OF_TEAMS * ta)
{
    TEAM * temp = (TEAM *)calloc(ta->max_size * 2 + 1, sizeof(TEAM));
    for (int i = 0; i < ta->current; ++i)
        temp[i] = ta->arr[i];
    free(ta->arr);
    ta->arr = temp;
    ta->max_size = ta->max_size * 2 + 1;
}

void AddTeam(ARRAY_OF_TEAMS * ta, char* teamName, char* teamName2, int score1, int score2, int HomeTeam)
{

    if (ta->current == ta->max_size)
    {
        ReallocationArray(ta);
    }
    strcpy(ta->arr[ta->current].name, teamName);
    InitCur(ta->arr[ta->current]);
    strcpy(ta->arr[ta->current].enemies[ta->arr[ta->current].cur], teamName2);
    ta->arr[ta->current].games_played[ta->arr[ta->current].cur]++;
    ta->arr[ta->current].count_goals[ta->arr[ta->current].cur] += score1;
    if (score1 > score2)
    {
        ta->arr[ta->current].games_win[ta->arr[ta->current].cur]++;
    }
    if (HomeTeam == 0)
    {
        ta->arr[ta->current].games_played_ef[ta->arr[ta->current].cur]++;
    }
    ta->arr[ta->current].cur++;
    ta->current++;
}

void AddResults(ARRAY_OF_TEAMS * ta, int position, char* teamName2, int score1, int score2, int HomeTeam)
{
    int ind = NotIn2(&ta->arr[position], teamName2);
    if (ind == -1) {
        strcpy(ta->arr[position].enemies[ta->arr[position].cur], teamName2);
        ind = ta->arr[position].cur;
        ta->arr[position].cur++;
    }
    ta->arr[position].games_played[ind]++;
    ta->arr[position].count_goals[ind] += score1;
    if (score1 > score2){
        ta->arr[position].games_win[ind]++;
    }
    if (HomeTeam == 0){
        ta->arr[position].games_played_ef[ind]++;
    }
}

int NotIn2(TEAM* t, char* teamName) {
    for (int i = 0; i < t->cur; ++i) {
        if (strcmp(t->enemies[i], teamName) == 0)
            return i;
    }
    return -1;
}

void PrintTeamsArray(const ARRAY_OF_TEAMS *ta, FILE* write)
{
    for (int i = 0; i < ta->current; ++i)
    {
        PrintTeamInfo(&ta->arr[i], write);
    }
}

void PrintTeamInfo(TEAM *t, FILE* write) {
    fprintf(write, "%s\n", t->name);
    for (int i = 0; i < t->cur; ++i) {
        fprintf(write, "%s %d %d %d %d\n", t->enemies[i], t->games_played[i], t->games_played_ef[i], t->games_win[i], t->count_goals[i]);
    }
}

int FindPosition(ARRAY_OF_TEAMS* ta, const char* teamName)
{
    for (int i = 0; i < ta->current; ++i) {
        if (strcmp(ta->arr[i].name, teamName) == 0)
            return i;
    }
    return -1;
}

int main() {
    FILE* read;
    FILE* write;
    read = fopen("input.txt", "r");
    write = fopen("output.txt", "w");
    ARRAY_OF_TEAMS array;
    InitTeamsArray(&array);
    char team1[100], team2[100];
    int score1, score2, index;
    while (fscanf(read, "%s - %s %d:%d", team1, team2, &score1, &score2) == 4)
    {
        index = FindPosition(&array, team1);
        if (index == -1)
        {
            AddTeam(&array, team1, team2, score1, score2, 1);
        } else {
            AddResults(&array, index, team2, score1, score2, 1);
        }
        index = FindPosition(&array, team2);
        if (index == -1)
        {
            AddTeam(&array, team2, team1, score2, score1, 0);
        } else {
            AddResults(&array, index, team1, score2, score1, 0);
        }
    }
    PrintTeamsArray(&array, write);
    fclose(read);
    fclose(write);
    return 0;
}
#endif

#ifdef task1
typedef struct team
{
    char name[100];
    int games_played, games_played_hf; // Home field
    int games_win, games_lose;
    int count_goals, count_lose_goals;
    int enemies;
    char enemies_list[10][100];
    int cur;
}TEAM;

typedef struct ArrayOfTeams
{
    TEAM* arr;
    int max_size;
    int current;
}ARRAY_OF_TEAMS;

void PrintTeamInfo(TEAM *t, FILE *write);

void InitCur(TEAM a);

int NotIn2(TEAM* t, char* teamName);

void InitCur(TEAM a) {
    a.cur = 0;
}

void ReallocationArray(ARRAY_OF_TEAMS * ta)
{
    TEAM * temp = (TEAM *)calloc(ta->max_size * 2 + 1, sizeof(TEAM));
    for (int i = 0; i < ta->current; ++i)
        temp[i] = ta->arr[i];
    free(ta->arr);
    ta->arr = temp;
    ta->max_size = ta->max_size * 2 + 1;
}

void AddTeam(ARRAY_OF_TEAMS * ta, char* teamName, char* teamName2, int score1, int score2, int HomeTeam)
{
    if (ta->current == ta->max_size)
    {
        ReallocationArray(ta);
    }
    strcpy(ta->arr[ta->current].name, teamName);
    InitCur(ta->arr[ta->current]);
    strcpy(ta->arr[ta->current].enemies_list[ta->arr[ta->current].cur], teamName2);
    ta->arr[ta->current].games_played++;
    if (HomeTeam == 1){
        ta->arr[ta->current].games_played_hf++;
    }
    if (score1 > score2){
        ta->arr[ta->current].games_win++;
    } else if (score1 < score2){
        ta->arr[ta->current].games_lose++;
    }
    ta->arr[ta->current].count_goals += score1;
    ta->arr[ta->current].count_lose_goals += score2;
    ta->arr[ta->current].enemies++;
    ta->arr[ta->current].cur++;
    ta->current++;
}

void AddResults(ARRAY_OF_TEAMS * ta, int position, char* teamName2, int score1, int score2, int HomeTeam)
{
    if (NotIn2(&ta->arr[position], teamName2) == -1){
        ta->arr[position].enemies++;
        strcpy(ta->arr[position].enemies_list[ta->arr[position].cur], teamName2);
        ta->arr[position].cur++;
    }
    ta->arr[position].games_played++;
    if (HomeTeam == 1){
        ta->arr[position].games_played_hf++;
    }
    if (score1 > score2){
        ta->arr[position].games_win++;
    } else if (score1 < score2){
        ta->arr[position].games_lose++;
    }
    ta->arr[position].count_goals += score1;
    ta->arr[position].count_lose_goals += score2;
}

int NotIn2(TEAM* t, char* teamName) {
    for (int i = 0; i < t->cur; ++i) {
        if (strcmp(t->enemies_list[i], teamName) == 0)
            return i;
    }
    return -1;
}

void InitTeamsArray(ARRAY_OF_TEAMS* ta)
{
    ta->current = ta->max_size = 0;
    ta->arr = NULL;
}

void PrintTeamsArray(const ARRAY_OF_TEAMS *ta, FILE* wr)
{
    for (int i = 0; i < ta->current; ++i)
    {
        PrintTeamInfo(&ta->arr[i], wr);
    }
}

void PrintTeamInfo(TEAM *t, FILE* write) {
    fprintf(write, "%s ", t->name);
    fprintf(write, "%d ", t->games_played);
    fprintf(write, "%d ", t->games_played_hf);
    fprintf(write, "%d ", t->games_win);
    fprintf(write, "%d ", t->games_lose);
    fprintf(write, "%d ", t->count_goals);
    fprintf(write, "%d ", t->count_lose_goals);
    fprintf(write, "%d\n", t->enemies);
}

int FindPosition(ARRAY_OF_TEAMS* ta, const char* teamName)
{
    for (int i = 0; i < ta->current; ++i) {
        if (strcmp(ta->arr[i].name, teamName) == 0)
            return i;
    }
    return -1;
}

int main() {
    FILE* read;
    FILE* write;
    read = fopen("input.txt", "r");
    write = fopen("output.txt", "w");
    ARRAY_OF_TEAMS array;
    InitTeamsArray(&array);
    char team1[100], team2[100];
    int score1, score2, index;
    while (fscanf(read, "%s - %s %d:%d", team1, team2, &score1, &score2) == 4)
    {
        index = FindPosition(&array, team1);
        if (index == -1)
        {
            AddTeam(&array, team1, team2, score1, score2, 1);
        } else {
            AddResults(&array, index, team2, score1, score2, 1);
        }
        index = FindPosition(&array, team2);
        if (index == -1)
        {
            AddTeam(&array, team2, team1, score2, score1, 0);
        } else {
            AddResults(&array, index, team1, score2, score1, 0);
        }
    }
    PrintTeamsArray(&array, write);
    fclose(read);
    fclose(write);
    return 0;
}
#endif

if (start[i] < end[j]) {
strcat(peresadka, base->buses_arr[start[i]].number);
strcat(peresadka, " ");
strcat(peresadka, base->buses_arr[end[j]].number);
strcat(peresadka, "\n");
count_per++;
flag = 1;
break;
} else {
strcat(peresadka, base->buses_arr[end[j]].number);
strcat(peresadka, " ");
strcat(peresadka, base->buses_arr[start[i]].number);
strcat(peresadka, "\n");
count_per++;
flag = 1;
break;
}
