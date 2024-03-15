#include "Transfer_data.h"

int adr=1;
//struct data buff_data;

void read_data(char *data_, int count_byte, struct data_read* read_buff)
{
   if (count_byte>0){
      for(int i=0; i<count_byte; i++ )  {
        read_buff->buff[i+read_buff->count]=data_[i];
      }
      read_buff->count+=count_byte;
   }
}

int process_read_data(struct data_read* read_buff, struct data* buff_data){
    if(read_buff->count>8){
        if( (read_buff->buff[0]==1) && (read_buff->buff[1]==2) && (read_buff->buff[2]==3) && (read_buff->buff[3]==4) ){
           if(read_buff->buff[4]<=read_buff->count){
               if(read_buff->buff[6]==adr){
                  //printf("crc %d \n",crc(&read_buff->buff, read_buff->buff[4]-1));
                  if(crc(&read_buff->buff, read_buff->buff[4]-1)==read_buff->buff[read_buff->buff[4]-1]) {
                      for(int i=0; i< read_buff->buff[4]-8; i++){ buff_data->buff[i]=read_buff->buff[i+7];}

                      //memcpy(&buff_data->buff, &read_buff->buff[7], read_buff->buff[4]-8);
                      buff_data->adr_source= read_buff->buff[5];
                      buff_data->count =read_buff->buff[4]-8;
                      read_buff->count-=read_buff->buff[4];
                      read_buff->time=0;
                  }else{ read_buff->count=0;}
               } else{ read_buff->count=0;}
           }
        }else{
          read_buff->count=0;
        }
    }
    if(read_buff->count>0){
      if(read_buff->time>10){
        read_buff->count=0;
        read_buff->time=0;
      }
    }
    read_buff->time++;
    return 1;
}

char crc(char *data, int count){
 char char_var;
 char_var=data[0];
 for(int i=1; i<count; i++){
    char_var ^=data[i];
 }
 return char_var;
}

void set_adr(int data){adr=data;}
