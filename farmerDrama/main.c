#include <stdio.h>

int main(void){
	FILE *fin = fopen("farmin.txt", "r");
	int plots = 0;
	fscanf(fin, "%d", &plots);
	int plotsizes[plots];
	for(int i = 0; i < plots, i++){
		fscanf(fin, "%d", &plotsizes[i]);
	}
	fclose(fin);

	int total_land = 0;
	for(int i = 0; i < plots; i ++){
		total_land += plotsizes[i];
	}
	total_land += plot_sizes-1;

	//[000100001]
	int fence_map[total_land];
	for(int i = 0; i < total_land; i ++){
		fence_map[i]= 0;
	}

	int fence_pos = -1;
	for(int i = 0; i < plots; i ++){
		fence_pos += 1 + plotsizes;
		fence_map[fence_pos] = 1;
	}

	for(int i = 0; i < total_land; i ++){
		printf("%d", fence_map[i]);
	}
}
