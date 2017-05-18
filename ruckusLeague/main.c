#include <stdio.h>

typedef struct person{
    int name;
    struct person *left_person;
    struct person *right_person; 
}Person, *Person;

int main(){
    FILE *fin = fopen("ruckusin.txt", "r");	
    int params[4];
    for(int i = 0; i < 4; i++){
        fscanf(fin, "%d", &params[i]);
    }
   
    int num_links = params[1];

    int initial_links[num_links][2];

    for(int i = 0; i < num_links; i ++){
        fscanf(fin, "%d", &initial_links[i][0]); 
        fscanf(fin, "%d", &initial_links[i][1]); 
    }
    fclose(fin);
    for(int i = 0; i < num_links; i ++){
        printf("%d %d\n", initial_links[i][0], initial_links[i][1]); 
    }
	return 0;
}
