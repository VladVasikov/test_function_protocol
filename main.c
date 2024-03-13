#include <stdio.h>
#include <stdlib.h>
#include "Transfer_data.h"
char data[150];


static struct data_read read_buff;
static struct data buff_data;

int main()
{
    char name[150];
    while(1){
        printf("Input transfer data: ");
        set_adr(7);
       // int count_byte= scanf("%[^\n]", data);
        int count_byte= scanf("%d", data);
        read_data(data, count_byte, &read_buff);
        process_read_data(&read_buff, &buff_data);
        if(buff_data.count>0){
         printf("data: %d  count: %d  source: %d \n", buff_data.buff[0], buff_data.count, buff_data.adr_source);
        }

    }



    return 0;
}
