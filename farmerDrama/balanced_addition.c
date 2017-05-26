#include <stdio.h>

int main(void){
    FILE *fin = fopen("farmin.txt", "r");

    int plots = 0;
    fscanf(fin, "%d", &plots);

    int sizes[plots];
    for(int i = 0; i < plots; i ++){
       fscanf(fin, "%d", &sizes[i]);
    }

    fclose(fin);

    int lindex = 0;
    int rindex = plots-1;
    int lsum = sizes[lindex];
    int rsum = sizes[rindex];
    int fences_kept = 0;
    int fences = plots - 1;
    int fences_removed = 0;

    while(lindex < plots-1 && rindex > 0){
        if(lsum < rsum){
            lindex ++;
            lsum += sizes[lindex];
            fences_removed ++;
            continue;
        }
        if(rsum < lsum){
            rindex --;
            rsum += sizes[rindex];
            fences_removed ++;
            continue;
        }
        if(rsum == lsum){
            fences_kept ++;
            lindex ++;
            lsum += sizes[lindex];
            continue;
        }
    }
    
    int removed = fences-fences_kept;
    printf("Fences: %d, Kept: %d, Removed %d\n", fences, fences_kept, fences-fences_kept);
    FILE *fout = fopen("farmout.txt", "w");
    fprintf(fout, "%d", removed);
    fclose(fout);
}
