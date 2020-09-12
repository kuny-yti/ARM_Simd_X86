CC = gcc
DIR = $(dir $(lastword $(MAKEFILE_LIST)))
INCLUDE_DIR = $(DIR)../../
DATA_DIR = $(DIR)../../data
ARCH_CFLAGS = -Wall -Wcast-qual -DNDEBUG -mavx512f -mavx512vl -mavx512bw -mavx512dq -mavx512vnni
CFLAGS = -I $(INCLUDE_DIR) -I $(DATA_DIR) -I ../ $(ARCH_CFLAGS) -D X86_TEST -O2
OBJS = $(wildcard $(DIR)*.c) ../*.c
EXEC = $(DIR)test
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
clean:
	rm -f *.o $(EXEC) 
