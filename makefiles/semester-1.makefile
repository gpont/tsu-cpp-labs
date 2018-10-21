CC      = g++
CFLAGS  = -Wall
SOURCES = main.cpp source/task3.cpp source/task4.cpp source/task5.cpp source/task6.cpp source/task7.cpp

all:
	$(CC) -Iheaders $(CFLAGS) $(SOURCES) -o start
