gcc.exe -Wall -g  -c Transfer_data.c -o Transfer_data.o
gcc.exe -Wall -g  -c main.c -o main.o
gcc.exe  -o Test_protocol.exe main.o Transfer_data.o
