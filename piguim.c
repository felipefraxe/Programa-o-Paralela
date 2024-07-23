
#include <stdio.h>


int main(int argc, char* argv[]) {

   int piguim[5][18] = {
        {0, 0, 1, 1, 0, 0,0,0,0,0,0,0,0,0,0,0,0,15},
        {0, 2, 0, 3, 4, 5,0,0,0,0,0,0,0,0,0,0,0,15},
        {0, 6, 0, 0, 7, 0,0,0,0,0,0,0,0,0,0,0,0,15},
        {0, 8, 0, 0, 8, 0,0,0,0,0,0,0,0,0,0,0,0,15},
        {0, 0, 9, 9, 0, 0,0,0,0,0,0,0,0,0,0,0,0,15}
    };

    for(int k=0; k < 5; k++){
        for(int j=0; j < 18; j++){
            if(piguim[k][j] == 0) printf(" ");
            if(piguim[k][j] == 1) printf("_");
            if(piguim[k][j] == 2) printf("(");
            if(piguim[k][j] == 3) printf("o");
            if(piguim[k][j] == 4) printf("`");
            if(piguim[k][j] == 5) printf("-");
            if(piguim[k][j] == 6) printf("/");
            if(piguim[k][j] == 7) printf("\\");
            if(piguim[k][j] == 8) printf("|");
            if(piguim[k][j] == 9) printf("^");
            if(piguim[k][j] == 15) printf("\n");
        }
    }

    // printf("  __\n");
    // printf(" ( o`-\n");
    // printf(" /  \\\n");
    // printf(" |  |\n");
    // printf("  ^^ \n");

}