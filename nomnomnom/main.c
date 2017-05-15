#include <stdio.h>

int main(int argc, char *argv[]){
    
    FILE *fin;
    fin = fopen("nomin.txt", "r");
    int n_dishes;
    fscanf(fin, "%d", &n_dishes);
    printf("%d\n", n_dishes);
    
    int dishes[n_dishes];
    for(int i = 0; i < n_dishes; i ++){
        fscanf(fin, "%d", &dishes[i]);
    }
    
    fclose(fin);

    int lastmeal = 0;
    int current_total = 0;
    int fed = 0;
    for(int i = 0; i < n_dishes; i ++){
        current_total += dishes[i];
        if(current_total >= lastmeal){
           fed ++;
           lastmeal = current_total;
           current_total = 0;
        }
    }

    FILE *fout;
    fout = fopen("nomout.txt", "w");
    fprintf(fout, "%d", fed);
    fclose(fout);
    return 0;
}
