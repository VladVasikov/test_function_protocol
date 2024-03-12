#include <stdio.h>
#include <stdlib.h>
#include "Transfer_data.h"
char data[150];




int main()
{
    char name[150];
    printf("Input transfer data: ");
    count_byte= scanf("%[^\n]", data);

    printf("\n \n %s %d", data, count_byte);
    return 0;
}
