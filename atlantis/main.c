#include <stdio.h>

int main(void){
    FILE *fin = fopen("atlanin.txt", "r");
    int lines;
    fscanf(fin, "%d", &lines);
    int heights[lines];
    for(int i = 0; i < lines; i ++){
        fscanf(fin, "%d", &heights[i]); 
    }
    fclose(fin);

    int habitable = 0;
    int current_left_wall = 0;
    int in_valley = 0;
    for(int i = 0; i < lines; i ++){
        int current_habitable = 0;
        if(heights[i] > current_left_wall){
            current_left_wall = heights[i];
            habitable += current_habitable;
            current_habitable = 0;
        }
        if(heights[i] < current_left_wall){
            if(current_left_wall){
                current_habitable ++;
            }
        }
    }

    printf("%d\n", habitable);
}

