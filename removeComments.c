#include<stdio.h>
#define MAXLINE 500

/*This program outputs the text of a program without the comments
handles single line comments, multi-line comments,
and comments on the same line as code */


int myGetline(char s[])
{
	int c, i;
	i = 0;
    
  	while ((c = getchar()) != EOF) {
		if (c == '\n')
	  		break;
	  
		s[i] = c;
		i++;
  	}
    
	s[i] = '\0';
		
	if (c == EOF)
		return -1;
	else
		return i;
}


/* Remove comments from string s, put result into string nc */
void removeComments(char s[])
{
	int i, n;
	i = n = 0;

	while (s[i] != '\0') {

	    /* look for beginning of comment */
		if (s[i] == '/' && s[i+1] != '\0' && s[i+1] == '*') {
			i += 2;
	        
	        /* while loop runs until end of comment */
	        	while (!(s[i] == '*' && s[i+1] == '/')) {
	        		
	        		/* if end of line get new line */
	        		if (s[i] == '\0') {
	        			myGetline(s);					
	        			i = 0;
	        		}
	        		
	            	i++;
				}
				
				i += 2;
		}
	    
	    
	    s[n] = s[i];
	    n++; 
	    i++;
	}	
    
	s[n] = '\0';
}

int main(void)
{
	char str[MAXLINE];					/* input String */
        
	while(myGetline(str) >= 0) {
		removeComments(str);
		printf("%s\n", str);
	}
	
	return 0;
}
