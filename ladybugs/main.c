#include <stdio.h>

int main(void){
    FILE *fin = fopen("ladyin.txt", "r");
    int lines = 0;
    fscanf(fin, "%d", &lines);

    int bugs[lines];

    for(int i = 0; i < lines; i ++){
        fscanf(fin, "%d", &bugs[i]);
    }

    fclose(fin);

    int min = bugs[0];
    int max = bugs[0];

    for(int i = 0; i < lines; i ++){
        if(bugs[i]<min){
            min = bugs[i];
        }
        if(bugs[i]>max){
            max = bugs[i];
        }
    }

    int answer = max-min+1;

    FILE *fout = fopen("ladyout.txt", "w");
    fprintf(fout, "%d", answer);
    fclose(fout);
}
