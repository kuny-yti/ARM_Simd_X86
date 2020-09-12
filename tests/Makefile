ARCH = aarch64
CXX = g++
ARCH_CFLAGS = -march=armv8-a+fp+simd+crc+crypto
DIR = $(dir $(lastword $(MAKEFILE_LIST)))
INCLUDE_DIR = $(DIR)../
DATA_DIR = $(DIR)../data
CFLAGS = -Wall -Wcast-qual -DNDEBUG -I $(INCLUDE_DIR) -I $(DATA_DIR) $(ARCH_CFLAGS) -O2
LDFLAGS	= -lm
OBJS = $(wildcard $(DIR)*.c)
EXEC = $(DIR)test
$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $^
clean:
	rm -f *.o $(EXEC) 