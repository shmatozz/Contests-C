#include <stdio.h>
#include <string.h>

typedef struct bus_info {
    char number[100];
    char stops[50][50];
    int curr;
} BUS;

typedef struct buses_base{
    BUS buses_arr[50];
    int curr_bus;
} BASE;

void InitCur(BASE *pBase, int bus);

int BusNotIn(BASE *pBase, const char *name);

void AddStop(BASE* base, const char* stop_name, int index);

int StopNotIn(BASE* base, int index, const char* name);

void PrintBus(BASE * base, int ind, int count, FILE * write);

void InitBase(BASE* b) {
    b->curr_bus = 0;
}

int Split(const char* buffer, char split_buf[][50], int count){
    char ch;
    int j = 0;
    unsigned int c;
    c = strlen(buffer) - 1;
    for (int i = 0; i < c; ++i) {
        ch = buffer[i];
        if (ch == ' ' && j != 0) {
            j = 0;
        } else if (ch != ' ') {
            if (j == 0) count++;
            split_buf[count - 1][j] = ch;
            j++;
        }
    }
    return count;
}

void AddBus(BASE* base, const char* bus_name, FILE* write) {
    if (BusNotIn(base, bus_name) == -1) {
        strcpy(base->buses_arr[base->curr_bus].number, bus_name);
        InitCur(base, base->curr_bus);
        base->curr_bus++;
    } else fprintf(write, "BUS %s ALREADY EXISTS\n", bus_name);
}

void AddStop(BASE* base, const char* stop_name, int index) {
    strcpy(base->buses_arr[index].stops[base->buses_arr[index].curr], stop_name);
    base->buses_arr[index].curr++;
}

int StopNotIn(BASE* base, int index, const char* name) {
    for (int i = 0; i < base->buses_arr[index].curr; ++i) {
        if (strcmp(base->buses_arr[index].stops[i], name) == 0) return i;
    }
    return -1;
}

int BusNotIn(BASE *pBase, const char *name) {
    for (int i = 0; i < pBase->curr_bus; ++i) {
        if (strcmp(pBase->buses_arr[i].number, name) == 0) return i;
    }
    return -1;
}

void PrintBus(BASE * base, int ind, int count, FILE* write) {
    if (count == 1) {
        fprintf(write, "%s\n", base->buses_arr[ind].number);
        fprintf(write, "STOPS:");
        for (int i = 0; i < base->buses_arr[ind].curr; ++i) {
            fprintf(write, " %s", base->buses_arr[ind].stops[i]);
        }
        fprintf(write, "\n");
    } else {
        for (int i = 0; i < count; ++i) {
            fprintf(write, "%s\n", base->buses_arr[i].number);
            fprintf(write, "STOPS:");
            for (int j = 0; j < base->buses_arr[i].curr; ++j) {
                fprintf(write, " %s", base->buses_arr[i].stops[j]);
            }
            fprintf(write, "\n");
        }
    }
}

void InitCur(BASE *pBase, int bus) {
    pBase->buses_arr[bus].curr = 0;
}

void PrintStop(BASE * base, const char* stop_name, FILE * write) {
    int count = 0;
    fprintf(write, "%s:", stop_name);
    for (int i = 0; i < base->curr_bus; ++i) {
        for (int j = 0; j < base->buses_arr[i].curr; ++j) {
            if (strcmp(base->buses_arr[i].stops[j], stop_name) == 0) {
                fprintf(write, " %s", base->buses_arr[i].number);
                count++;
            }
        }
    }
    if (count == 0) fprintf(write, " NO BUSES GO TO STOP\n");
    else fprintf(write, "\n");
}

void FindWay(BASE *base, const char *name_begin, const char *name_stop, FILE* write) {
    int count = 0, count_per = 0;
    char busss[10000] = { 0 };
    char peresadka[10000] = { 0 };
    int start[10] = { 0 }, end[10] = { 0 }, cs = 0, ce = 0;
    for (int i = 0; i < base->curr_bus; ++i) {
        for (int j = 0; j < base->buses_arr[i].curr; ++j) {
            if (strcmp(name_begin, base->buses_arr[i].stops[j]) == 0) {
                start[cs] = i;
                cs++;
            }
            if (strcmp(name_stop, base->buses_arr[i].stops[j]) == 0) {
                end[ce] = i;
                ce++;
            }
        }
    }
    for (int i = 0; i < base->curr_bus; ++i) {
        int flag_begin = 0, flag_stop = 0;
        for (int j = 0; j < base->buses_arr[i].curr; ++j) {
            if (strcmp(name_begin, base->buses_arr[i].stops[j]) == 0) {
                flag_begin = 1;
            } else if (strcmp(name_stop, base->buses_arr[i].stops[j]) == 0) {
                flag_stop = 1;
            }
        }
        if (flag_begin == 1 && flag_stop == 1) {
            strcat(busss, base->buses_arr[i].number);
            strcat(busss, "\n");
            count++;
        }
    }
    if (strlen(busss) > 0) fprintf(write, "BUSES FROM %s TO %s:\n%s",  name_begin, name_stop, busss);
    else {
        for (int i = 0; i < cs; ++i) {
            for (int j = 0; j < ce; ++j) {
                int flag = 0;
                for (int k = 0; k < base->buses_arr[start[i]].curr; ++k) {
                    for (int l = 0; l < base->buses_arr[end[j]].curr; ++l) {
                        printf("%s %s\n",base->buses_arr[start[i]].stops[k], base->buses_arr[end[j]].stops[l]);
                        if (strcmp(base->buses_arr[start[i]].stops[k], base->buses_arr[end[j]].stops[l]) == 0) {
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
                        }
                    }
                    if (flag == 1) break;
                }
            }
        }
        if (strlen(peresadka) > 0) fprintf(write, "BUSES FROM %s TO %s:\n%s", name_begin, name_stop, peresadka);
        else fprintf(write, "THERE ARE NO BUSES FROM %s TO %s\n", name_begin, name_stop);
    }
}

int main() {
    FILE* read;
    FILE* write;
    read = fopen("input.txt", "r");
    write = fopen("output.txt", "w");
    BASE base[10];
    InitBase(base);
    char buffer[1000];
    while (fgets(buffer, 1000, read)) {
        char split_buf[50][50] = { 0 };
        int count = 0;
        count = Split(buffer, split_buf, count);
        if (strcmp(split_buf[0], "ADD") == 0) {
            if (strcmp(split_buf[1], "BUS") == 0 && count == 3)  // ADD BUS
            {
                if (base->curr_bus < 10) AddBus(base, split_buf[2], write);
                else fprintf(write, "CAN'T ADD BUS %s. BUSPARK IS FULL\n", split_buf[2]); // +
            }
            else if (strcmp(split_buf[1], "STOP") == 0 && count == 4)   // ADD STOP
            {
                int ind = BusNotIn(base, split_buf[2]);
                if (ind == -1) fprintf(write, "BUS %s DOESN'T EXIST\n", split_buf[2]); // +
                else {
                    int in = StopNotIn(base, ind, split_buf[3]);
                    if (in != -1) fprintf(write, "BUS %s ALREADY HAS STOP %s\n", split_buf[2], split_buf[3]); // +
                    else if (base->buses_arr[ind].curr < 30) {
                        AddStop(base, split_buf[3], ind);
                    } else fprintf(write, "CAN'T ADD STOP %s TO BUS %s. BUS IS FULL\n", split_buf[3], split_buf[2]); // +
                }
            }
            else fprintf(write, "WRONG ADD FORMAT\n"); // +
        } else if (strcmp(split_buf[0], "PRINT") == 0) {
            if (strcmp(split_buf[1], "BUS") == 0 && count == 3) {
                int ind = BusNotIn(base, split_buf[2]);
                if (ind == -1) fprintf(write, "BUS %s DOESN'T EXIST\n", split_buf[2]); // +
                else PrintBus(base, ind, 1, write);
            } else if (strcmp(split_buf[1], "STOP") == 0 && count == 3) {
                PrintStop(base, split_buf[2], write);
            } else if (strcmp(split_buf[1], "ALL") == 0 && count == 2) {
                if (base->curr_bus != 0) PrintBus(base, 0, base->curr_bus, write);
            } else fprintf(write, "WRONG PRINT FORMAT\n"); // +
        }
        else if (strcmp(split_buf[0], "FIND") == 0) {
            if (count != 3) fprintf(write, "WRONG FIND FORMAT\n"); // +
            else if (strcmp(split_buf[2], split_buf[1]) == 0) fprintf(write, "STOPS %s ARE THE SAME\n", split_buf[1]); // +
            else {
                FindWay(base, split_buf[1], split_buf[2], write);
            }
        }
        else fprintf(write, "WRONG %s FORMAT\n", split_buf[0]);
    }
    fclose(read);
    fclose(write);
    return 0;
}
