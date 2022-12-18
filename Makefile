TARGET = app
.PHONY: all clean run
all: $(TARGET)
clean:
	rm $(TARGET) *.o
run: $(TARGET)
	./$(TARGET)
main.o: main.c
	gcc -c main.c
funcs.o: main.c
	gcc -c funcs.c
bin.o: main.c
	gcc -c bin.c
hex.o: main.c
	gcc -c hex.c
oct.o: main.c
	gcc -c oct.c
$(TARGET): main.o funcs.o bin.o hex.o oct.o
	gcc main.o funcs.o bin.o hex.o oct.o -o $(TARGET)
