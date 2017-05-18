#include <stdio.h>

int main(int argc, char *argv[]){

    FILE *fin;
    fin = fopen("safein.txt", "r");
    int code_length;
    fscanf(fin, "%d", &code_length);
    int sub_length;
    fscanf(fin, "%d", &sub_length);

    int code[code_length];
    int sub[sub_length];

    for(int i = 0, i < code_length; i ++){
        fscanf(fin, "%d", &code[i]);       
    }

    for(int i = 0; i < sub_length; i ++){
        fscanf(fin, "%d", &sub[i]);
    }

    int shift = 0;

    for(int shift = 0; shift < code_length - sub_length; i ++){
        for(int i = 0; i < sub_length; i ++){
            
                        

        }
    }

    return 0;
}
