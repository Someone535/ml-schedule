CC = clang++

CFLAGS = -L /data/data/com.termux/files/lib -l curl -I /data/data/com.termux/files/usr/include

TARGET = schedule

OBJECTS =  main.o mycurl.o jsonToken.o jsonStrScanner.o jsonStrParser.o

$(TARGET) : $(OBJECTS)
	$(CC) -o $(TARGET) $(CFLAGS) $(OBJECTS)

main.o : mycurl.h jsonStrScanner.h
mycurl.o : mycurl.h
jsonToken.o : jsonToken.h
jsonStrScanner.o : jsonToken.h jsonStrScanner.h
jsonStrParser.o : jsonToken.h jsonStrParser.h jsonValue.h

.PHONY : clean
clean :
	-rm -f $(OBJECTS)

.PHONY : cleaner
cleaner :
	-rm -f $(TARGET) $(OBJECTS)
