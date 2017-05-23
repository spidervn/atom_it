TARGET=sort_2017
CC=g++
LDFLAGS=-lpthread
CFLAGS=-I/usr/include -std=c++11

OBJS=sort_2017.o
SRC=sort_2017.cpp
INCLUDES=

sort_2017: $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)


$(OBJS): $(SRC) $(INCLUDES)
	$(CC) $(CFLAGS) -c $(@:.o=.cpp) $(LDFLAGS)

clean:
	@rm -f $(OBJS) $(LDFLAGS)
