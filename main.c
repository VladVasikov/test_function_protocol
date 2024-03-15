#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Transfer_data.h"
char data[150];
struct data_read read_buff;
struct data buff_data;

int main()
{
    char name[250];
    set_adr(7);
    char * filename = "input.txt";
    char buffer[256];
    FILE *fp = fopen(filename, "r");
    if(fp)
    {
        while((fgets(buffer, 256, fp))!=NULL)
        {
            int i=0, num;
            char *p, *p1;
            char p2[]=" ";
            p=&buffer[0];
            i=0;
            while(p1=strstr(p, p2)){
               sscanf(p, "%d", &num);
               name[i] = (char)num;
               p=p1+1;
               i++;
            }
            read_data(&name[0], i, &read_buff);
           // for(int i=0; i<read_buff.count; i++){printf("%d ",read_buff.buff[i]);}
           // printf("  **** time: %d \n",read_buff.time);
            process_read_data(&read_buff, &buff_data);
            if(buff_data.count>0){
               printf("count: %d  source: %d  data: ", buff_data.count, buff_data.adr_source);
               for(int i=0; i<buff_data.count; i++){printf("%d ",buff_data.buff[i]);}
            printf("\n");
               buff_data.count=0;
            }
        }
        fclose(fp);
    }
    return 0;
}
