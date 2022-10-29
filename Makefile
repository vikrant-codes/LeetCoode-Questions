all:	linkedList.c
	gcc linkedList.c 
	./a.out
	
	
	
commit:
	rm *.out
	git add .
	git commit . -m "commit by vikrant"
	git push
	gcc linkedList.c 
	
	
