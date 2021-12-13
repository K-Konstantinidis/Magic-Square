/*************************************************************************
        Copyright © 2021 Konstantinidis Konstantinos

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.
*************************************************************************/
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main(){
    long a, b, summary, c, d;
    int i,j;

    printf("Insert number a:");
    a = GetLong();
    printf("Insert number b:");
    b = GetLong();

    long magic_square[4][4] = {a, a+14, b, a+3, b-2, a+5, a+6, a+8, a+7, b-4, a+10, a+4, a+12, a+2, a+1, b+2};
    print_square(magic_square);
    printf("--------------------------\n");
    for(i=0; i<4; i++){
        summary = 0;
        for(j=0; j<4; j++)
            summary += magic_square[i][j];
    }

    for(i=0; i<4; i++)
        printf("%-5ld ",summary);

    c = diagonal1(magic_square);
    d = diagonal2(magic_square);
    printf("\nDiagonal(L->R): %ld \nDiagonal(R->L): %ld", c, d);
    if (summary == c && summary == d && c == d)
        printf("\nMAGIC\n");
    else
        printf("\nNOT MAGIC\n");

    system("PAUSE");
}

void print_square(long magic_square[4][4]){
    int i, j;
    long summary;

    for(i=0; i<4; i++){
        summary = 0;
        for(j=0; j<4; j++){
            summary += magic_square[i][j];
            printf("%-5ld ", magic_square[i][j]);
        }
        printf(" | %-2ld \n", summary);
    }
}

void diagonal1(long magic_square[4][4]){
    int a = -1, b = -1, i, j, c;
    long summary = 0;

    for(i=0; i<4; i++){
        a++;
        b++;
        summary += magic_square[a][b];
    }
    c = summary;

    return c;
}

void diagonal2(long magic_square[4][4]){
    int a = -1, b = 4, i, j, c;
    long summary = 0;

    for(i=0; i<4; i++){
        a++;
        b--;
        summary += magic_square[a][b];
    }
    c = summary;

    return c;
}
