#ifndef TRANSFER_DATA_H_INCLUDED
#define TRANSFER_DATA_H_INCLUDED

struct data_read{
   int count;
   char buff[255];
   int time;
   int source_adr;
};

void read_data();
int process_read_data();

#endif // TRANSFER_DATA_H_INCLUDED
