
int count_byte;
int adr;
struct data_read read_buff;

void read_data()
{
   if (count_byte>0){
      memcpy(read_buff.buff[read_buff.count], data, count_byte);
      read_buff.count+=count_byte; count_byte=0;
   }
   read_buff.time++;
}

int process_read_data(){
    if(read_buff.count>0){
        if(read_buff.buff[0]==1 && read_buff.buff[1]==2 && read_buff.buff[2]==3 && read_buff.buff[3]==4){
           if(read_buff.buff[4]>=read_buff.count){

           }else{
             if(read_buff.time>10){
                read_buff.count=0;
                return -2;
             } else{
               return 1;
             }
           }
        }else{
          read_buff.count=0; return -1;
        }
    }else {return 0;}
}
