all : reverse removeComments

reverse : reverse.c
	gcc -o reverse reverse.c

removeComments : removeComments.c
	gcc -o removeComments removeComments.c

test :
	./reverse < inputlines
	./removeComments < removeComments.c 

clean :
	/bin/rm reverse removeComments
