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

    /*
	int total_land = 0;
	for(int i = 0; i < plots; i ++){
		total_land += plotsizes[i];
	}
	total_land += plots-1;

	//[000100001]
	int fence_map[total_land];
	for(int i = 0; i < total_land; i ++){
		fence_map[i]= 0;
	}

	int fence_pos = -1;
	for(int i = 0; i < plots; i ++){
		fence_pos += 1 + plotsizes[i];
		fence_map[fence_pos] = 1;
	}
   
    printf("FARM MAP: ");
    for(int i = 0; i < total_land; i ++){
        printf("%d ", fence_map[i]);
    }
    printf("\n");

    int i = 0;
    int j = total_land -1;
    int removed = 0;
    while(j >= 0 && i < total_land){
        if(fence_map[i] == 1 && fence_map[j] == 0){
            removed ++;
        }
        i++;
        j--;
    }
    */
    
    FILE *fout = fopen("farmout.txt", "w");
    fprintf(fout, "%d", removed);
    fclose(fout);
}
