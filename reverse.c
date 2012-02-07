#include<stdio.h>
#include<string.h>

#define MAXLINE 500

int mygetline(char s[])
{
	int c, i;
	i = 0;

	while((c = getchar()) != EOF) {
    	if (c == '\n')
      		break;
		s[i] = c;
		i++;
	}

	s[i] ='\0';

	if (c == EOF)
		return -1;
	else
    	return i;
}


void reverse(char s[], int len)
{
	int i;
	char temp;


	for (i = 0; len > i; i++) {
	  temp = s[i];
	  s[i] = s[len-1];
	  s[len-1] = temp;
	  len--;
	}
	
	//	s[len] = '\0';
}


int main(void)
{
	char str[MAXLINE];
	int len;
 
	while ((len = mygetline(str)) >= 0) {
		reverse(str, len);
		printf("%s\n", str); 
	}
	
	printf("\n");
  
	return 0;
}
