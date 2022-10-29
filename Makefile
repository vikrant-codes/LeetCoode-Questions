CC = gcc
FLAGS = -g

all:	linkedList.c
	$(CC) $(FLAGS) linkedList.c 
	./a.out
	
clean:
	rm a.out
	
commit:
	rm a.out
	git add .
	git commit . -m $(msg)
	git push
	
	
