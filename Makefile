CC = clang++

CFLAGS = -L /data/data/com.termux/files/lib -l curl -I /data/data/com.termux/files/usr/include

TARGET = schedule

OBJECTS =  main.o mycurl.o jsonToken.o jsonStrScanner.o jsonStrParser.o jsonValue.o task.o jsonStr.o myTime.o

$(TARGET) : $(OBJECTS)
	$(CC) -o $(TARGET) $(CFLAGS) $(OBJECTS)

main.o : mycurl.h jsonStrScanner.h
mycurl.o : mycurl.h
jsonToken.o : jsonToken.h
jsonStrScanner.o : jsonToken.h jsonStrScanner.h
jsonStrParser.o : jsonToken.h jsonStrParser.h jsonValue.h
jsonValue.o : jsonValue.h jsonToken.h
task.o : task.h
jsonStr.o : jsonValue.h jsonStrScanner.h jsonStrParser.h
myTime.o : myTime.h

.PHONY : clean
clean :
	-rm -f $(OBJECTS)

.PHONY : cleaner
cleaner :
	-rm -f $(TARGET) $(OBJECTS)
