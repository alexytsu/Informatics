#include <stdio.h>
#include <stdlib.h>

typedef struct city{
    struct city *t1_in;
    struct city *t1_out;
    struct city *t2_in;
    struct city *t2_out;
    struct city *t3_in;
    struct city *t3_out;
    struct city *t4_in;
    struct city *t4_out;
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
    }
}
