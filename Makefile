CC=gcc
TARGET=my_preprocessor
OBJS=main.o comments_removal.o headerfile_inclusion.o macro_replacement.o

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

main.o: main.c header.h
	$(CC) -c main.c

comments_removal.o: comments_removal.c header.h
	$(CC) -c comments_removal.c

headerfile_inclusion.o: headerfile_inclusion.c header.h
	$(CC) -c headerfile_inclusion.c

macro_replacement.o: macro_replacement.c header.h
	$(CC) -c macro_replacement.c

clean:
	rm -f *.o my_preprocessor abc.i
