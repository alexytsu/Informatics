#include <stdio.h>

int main(void){
	FILE *fin = fopen("farmin.txt", "r");
	int plots = 0;
	fscanf(fin, "%d", &plots);
	int plotsizes[plots];
	for(int i = 0; i < plots; i++){
		fscanf(fin, "%d", &plotsizes[i]);
        printf("%d ",plotsizes[i]);
	}
	fclose(fin);
    printf("\n");

    /*
    int plotsum[plots];
    int rplotsum[plots];
    for(int i = 0; i < plots; i ++){
        int sum = 0;
        int rsum = 0;
        for(int j = i; j>=0; j--){
            sum += plotsizes[j];
            rsum += rplotsizes[j];
        }
        plotsum[i] = sum;
        rplotsum[i] = rsum;
    }
    
    printf("Plotsum: ");
    for(int i = 0; i < plots; i ++){
        printf("%d ", plotsum[i]);
    }
    printf("\n");

    printf("Rplotsum: ");
    for(int i = 0; i < plots; i ++){
        printf("%d ", rplotsum[i]);
    }
    printf("\n");

    int kept_fences = 0;
    for(int i = 0; i < plots; i ++){
        int keep = 0;    
        for(int j = 0; j < plots; j ++){
            if(plotsum[j] == rplotsum[i]){
                keep = 1;
            }
        }
        if(keep) kept_fences += 1;
    }
    kept_fences --;

    int fences = plots-1;
    printf("Kept fences = %d\n", kept_fences);
    printf("Removed fences = %d\n", fences-kept_fences);

    FILE *fout = fopen("farmout.txt", "w");
    fprintf(fout, "%d", fences-kept_fences);
    fclose(fout);
    */
    /*
    int fences = plots - 1;
    int fences_kept = 0;

    int right_i = fences;
    int left_i = 0;

    int edge_to_l = 0;
    int edge_to_r = 0;

    int sum = 0;
    for(int i = 0; i < plots; i ++){
        sum += plotsizes[i];
    }
    int half = sum/2;

    while((right_i > 0 || left_i < fences)){
        if(edge_to_l == edge_to_r){
            fences_kept ++;
            edge_to_l += plotsizes[left_i];
            left_i ++;
        }else if(edge_to_l < edge_to_r){
            edge_to_l += plotsizes[left_i];
            left_i ++;
        }else{
            edge_to_r += plotsizes[right_i];
            right_i --;
        }
    }
    
    fences_kept --;
    int removed = fences - fences_kept;
    printf("%d\n", removed);
    */

    int plotsum = 0;
    for(int i = 0; i < plots; i ++){
        plotsum += plotsizes[i];
    }
	int total_land = 2*plotsum-1;

	//[000100001]
	int fence_map[total_land];
	for(int i = 0; i < total_land; i ++){
		if(i%2)fence_map[i]= 0;
        else fence_map[i] = 1;
	}

    int last_fence_pos = -1;
    for(int i = 0; i < plots; i ++){
        last_fence_pos += 2*plotsizes[i];
        fence_map[last_fence_pos] = 2;
    }
   
    printf("FARM MAP: ");
    for(int i = 0; i < total_land; i ++){
        printf("%d ", fence_map[i]);
    }
    printf("\n");

    /*
    int rfence_map[total_land];
    for(int i = 0; i < total_land; i++){
        rfence_map[i] = fence_map[total_land - 1 - i]; 
    }
    */
    /*
    printf("FARM MAP: ");
    for(int i = 0; i < total_land; i ++){
        printf("%d ", rfence_map[i]);
    }
    printf("\n");
    int fences_kept = 0;
    */
    int fences_kept = 0;
    printf("FARM MAP: ");
    for(int i = 0; i < total_land; i ++){
        if(fence_map[i] == 2 && fence_map[total_land - i -1] == 2){
            fences_kept ++;
            printf("X ");
        }else{
            printf("0 ");
        }
    }
    printf("fences_kept %d\n", fences_kept);
    int fences = plots - 1;
    int fences_removed = fences- fences_kept;
    FILE *fout = fopen("farmout.txt", "w");
    fprintf(fout, "%d", fences_removed);
    fclose(fout);
}
