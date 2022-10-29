CC = gcc
FLAGS = -g

all:	linkedList.c
	$(CC) $(FLAGS) linkedList.c 
	./a.out
	
clean:
	rm a.out
	
commit:
	gcc linkedList.c
	rm a.out
	git add .
	git commit . -m $(MSG)
	git push
	
	
