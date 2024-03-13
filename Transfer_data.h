#ifndef TRANSFER_DATA_H_INCLUDED
#define TRANSFER_DATA_H_INCLUDED


struct data_read{
   int count;
   char buff[255];
   int time;
};

struct data{
   int count;
   char buff[255];
   int adr_source;
};
void set_adr(int data);
void read_data(char *data_, int count_byte, struct data_read* read_buff);
int process_read_data(struct data_read* read_buff, struct data* buff_data );
char crc(char *data, int count);
#endif // TRANSFER_DATA_H_INCLUDED
