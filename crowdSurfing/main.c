#include <stdio.h>
#include <stdlib.h>

void label(int rows, int cols, char grid[rows][cols], int posx, int posy);

int main(void){
	
    FILE *fp;
    fp = fopen("surfin.txt", "r");
    int rows, cols;
    fscanf(fp, "%d", &rows);
    fscanf(fp, "%d", &cols);

    char grid[rows][cols];
    for(int row = 0; row < rows; row ++){
        for(int col = 0; col < cols; col ++){
            fscanf(fp, "%char", &grid[row][col]);
            if(grid[row][col]=='\n') col --;
        }
    }
    
    fclose(fp);

    int start_row = rows - 1;
    int start_col = cols - 1;

    for(int i = 0; i < rows; i ++){
        for(int j = 0; j < cols; j ++){
            label(rows, cols, grid, rows-1-i, cols-1-j);
        }
    }

    int popes = 0;
    
    for(int j = 0; j < cols; j ++){
        for(int i = 0; i < rows; i ++){
            if(grid[i][j]=='+') popes++;
        }
    }

    int badstarts = rows*cols - popes;

    FILE *fout;
    fout = fopen("surfout.txt", "w");
    fprintf(fout, "%d", badstarts);
    fclose(fout);

	return 0;
}

void label(int rows, int cols, char grid[rows][cols], int posx, int posy){
    if(posx < 0 || posy < 0 || posx >= rows || posy >= cols){
        return;
    }

    char curSquare = grid[posx][posy];
    int abovex = posx-1;
    int lefty = posy-1;
    int righty = posy+1;
    int belowx = posx+1;
    
    if(curSquare=='+'){
        if(abovex>=0 ){
            if(grid[abovex][posy] == '+') return;
            if(grid[abovex][posy] == 'v'){
                grid[abovex][posy] = '+';
            }
        }
        if(lefty>=0){
            if(grid[posx][lefty] == '+') return;
            if (grid[posx][lefty] == '>'){ 
                grid[posx][lefty] = '+'; 
            }
        }
        if(belowx<rows){
            if(grid[belowx][posy] == '+' || grid[belowx][posy] == '*') return;
        }
        if(righty<cols){
            if(grid[posx][righty] == '+' || grid[posx][righty] == '*') return;
        }
        label(rows, cols, grid, posx-1, posy);
        label(rows, cols, grid, posx, posy-1);
        label(rows, cols, grid, posx+1, posy);
        label(rows, cols, grid, posx, posy+1);
    }else{
        return;
    }

}
