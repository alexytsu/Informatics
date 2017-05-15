#include <stdio.h>
#include <stdlib.h>

int findScore(int startingFence, int parameters, int *fences){
    
    int startingHeight = fences[startingFence];
    
    int max = startingHeight;
    int posMax = startingFence;

    for(int i = startingFence; i < parameters; i ++){
        if(fences[i] > max){
            posMax = i;
            max = fences[i];
        }
    }
    
    int min = max;
    int posMin = posMax;
    for(int i = posMax; i < parameters; i ++){
        if(fences[i] < min){
            min = fences[i];
        }
    }

    int score = max - startingHeight + max - min;
    return score;

}

int valid(int startingFence, int *fences, int parameters){
    int largerHeight = fences[startingFence];
    int largerFound = 0;
    int lowerFound = 0;
    for(int i = startingFence; i < parameters; i ++){
        if(!largerFound){
            if(fences[i] > largerHeight){
                largerHeight = fences[i];
                largerFound = 1;
            }
        }if(largerFound){
            if(fences[i] < largerHeight){
                lowerFound = 1;
            }
        }
    }
    if(lowerFound && largerFound) return 1;
    else return 0;
}

int main(void){

    FILE *stream;
    int parameters;
    
    stream = fopen("frogin.txt", "r");
    fscanf(stream, "%d", &parameters);
    int fences[parameters];
    for(int i = 0; i < parameters; i ++){
        fscanf(stream, "%d", &fences[i]);
    }
    fclose(stream);
    

    for(int i = 0; i < parameters; i ++){
        printf("%d\n", fences[i]);
    }
    int maxTotalScore = 0;
    int tempMax;
    for(int i = 0; i < parameters-2; i ++){
        if(valid(i, fences, parameters)){
            tempMax = findScore(i, parameters, fences);
        }
    }

}
