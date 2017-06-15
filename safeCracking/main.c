#include <stdio.h>
#include <stdlib.h>

int main(void){

    FILE *fin;
    fin = fopen("safein.txt", "r");

    int code_length;
    fscanf(fin, "%d", &code_length);
    int sub_length;
    fscanf(fin, "%d", &sub_length);

    int code[code_length];
    int sub[sub_length];

    for(int i = 0; i < code_length; i ++){
        fscanf(fin, "%d", &code[i]);       
    }

    for(int i = 0; i < sub_length; i ++){
        fscanf(fin, "%d", &sub[i]);
    }


    int offset = code_length - sub_length; 
    int solved = 0;
    int difference = 0;

    while(!solved){

        solved = 1;
        difference = code[offset] - sub[0];
        for(int i = 0; i < sub_length; i ++){
            if(code[offset+i] - sub[i] != difference){
                solved = 0;
                offset --;
                break;
            }
        }
    }
    
    for(int i = 0; i < code_length; i ++){
        code[i] -= difference;   
    }
     
    FILE *fout = fopen("safeout.txt", "w");
    for(int i = 0; i < code_length; i ++){
        fprintf(fout, "%d\n", code[i]);
    }
    fclose(fout);
    fclose(fin);
}
