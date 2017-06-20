#include <stdio.h>
#include <stdlib.h>

struct turn{
    int time;
    int width;
    int height;
};

int main(void){
    FILE *fin = fopen("artin.txt", "r");
    int lines;
    fscanf(fin, "%d", &lines);
    struct turn * turns = malloc(lines*sizeof(struct turn));
    for(int i = 0; i < lines; i ++){
        fscanf(fin, "%d", &turns[i].time); 
        fscanf(fin, "%d", &turns[i].width); 
        fscanf(fin, "%d", &turns[i].height); 
    }
    fclose(fin);

    for(int i = 0; i < lines; i ++){
        printf("%d %d %d\n", turns[i].time, turns[i].width, turns[i].height);
    
    }

     

    return 0;
}
