#$@：目前的目標項目名稱。
#$<：代表目前的相依性項目。
#$*：代表目前的相依性項目，但不含副檔名。
#$?：代表需要重建（被修改）的相依性項目。
CC=gcc
CFLAGS=-I.
DEPS= RemoveLeftRecursion.h
OBJS= main.o
EXE=vc_chapter_5

all: $(OBJS)
	$(CC) -o $(EXE) $(OBJS)

%.o: %.c $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -rf $(OBJS) $(EXE) 