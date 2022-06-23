#include <stdio.h>
#include <string.h>
#define size 100

int main(){
    FILE* read;
    FILE* write;
    read = fopen("input.txt", "r");
    write = fopen("output.txt", "w");
    char field[size][size], buffer[size];
    int j = 0, all_points = 0, count_points = 0, ball[2] = {1,1}, x = 0, y = 1, z;
    while (fgets(buffer, size, read)){
        for (int i = 0; buffer[i]; ++i) {
            field[j][i] = buffer[i];
            if (buffer[i] == '*')
                all_points++;
        }
        j++;
    }
    while (1){
        if (ball[0] == j - 2 && ball[1] == strlen(buffer) - 3){
            fprintf(write, "yes\n");
            break;
        }
        switch (field[ball[0]][ball[1]]) {
            case '*':{
                count_points++;
                break;
            }
            case '\\':{
                z = y;
                y = x;
                x = z;
                break;
            }
            case '/':{
                z = -y;
                y = -x;
                x = z;
                break;
            }
            case '#':{
                fprintf(write, "no\n");
                return 0;
            }
        }
        ball[0] += x;
        ball[1] += y;
    }
    if (count_points == all_points){
        fprintf(write, "yes\n");
    } else {
        fprintf(write, "no\n");
    }
    fclose(read);
    fclose(write);
    return 0;
}