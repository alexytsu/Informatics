#include <stdio.h>
#include <stdlib.h>

typedef struct city{
    struct city *t1;
    struct city *t2;
    struct city *t3;
    struct city *t4;
}City;


int main(void){
    FILE *fin = fopen("wherein.txt", "r");
    int n_cities = 0;
    fscanf(fin, "%d", &n_cities);
    int lines = 0; 
    fscanf(fin, "%d", &lines);
    City *city_array[n_cities];

    for(int i = 0; i < n_cities; i ++){
        city_array[i] = malloc(sizeof(City));
        city_array[i]->t1=NULL;
        city_array[i]->t2=NULL;
        city_array[i]->t3=NULL;
        city_array[i]->t4=NULL;
    }

    for(int i = 0; i < lines; i ++){
        int city1;
        fscanf(fin, "%d", &city1);
        city1--;
        int city2;
        fscanf(fin, "%d", &city2);
        city2--;
        int transport;
        fscanf(fin, "%d", &transport);

        if(transport == 1){
            city_array[city1]->t1 = &city_array[city2];
            city_array[city2]->t1 = &city_array[city1];
        }else if(transport == 2){
            city_array[city1]->t2 = &city_array[city2];
            city_array[city2]->t2 = &city_array[city1];
        }else if(transport == 3){
            city_array[city1]->t3 = &city_array[city2];
            city_array[city2]->t3 = &city_array[city1];
        }
        else if(transport == 4){
            city_array[city1]->t4 = &city_array[city2];
            city_array[city2]->t4 = &city_array[city1];
        }else{
            fprintf(stderr, "Invalid transport on line %d. Exiting...\n", i);
            exit(1);
        }
    }

    int n = 0;
    fscanf(fin, "%d", &n);
    int sighting[n];
    for(int i = 0; i < n; i ++){
        fscanf(fin, "%d", &sighting[i]);
    }

    fclose(fin);

    for(int i = 0; i < n_cities; i ++){
        printf("City %d @pointer %p\n", i, &city_array[i]);
        printf("\t Transport 1: %p\n", city_array[i]->t1);
        printf("\t Transport 2: %p\n", city_array[i]->t2);
        printf("\t Transport 3: %p\n", city_array[i]->t3);
        printf("\t Transport 4: %p\n", city_array[i]->t4);
    }

    return 0;
}
