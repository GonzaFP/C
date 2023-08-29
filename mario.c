/*
! functio that prints a rightsided pyramid
*/

#include <stdio.h>

int main(void)
{
 int height = 4;

 for (int i = 1; i <= 4; i++)
 {

 for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }
        for (int a = 0; a < i; a++)
        {
            printf("#");
        }
        printf("\n");
 }
}