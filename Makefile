CC = clang++

CFLAGS = -L /data/data/com.termux/files/lib -l curl -I /data/data/com.termux/files/usr/include

TARGET = schedule

OBJECTS =  main.o mycurl.o

$(TARGET) : $(OBJECTS)
	$(CC) -o $(TARGET) $(CFLAGS) $(OBJECTS)

main.o : mycurl.h
mycurl.o : mycurl.h

.PHONY : clean
clean :
	-rm -f $(OBJECTS)

.PHONY : cleaner
cleaner :
	-rm -f $(TARGET) $(OBJECTS)
