all:	linkedList.c
	gcc linkedList.c 
	./a.out
	
	
	
commit:
	rm a.out
	git add .
	git commit . -m "commit by vikrant"
	git push
	
	
