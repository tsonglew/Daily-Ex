#include <stdio.h>
#include <string.h>

void alltrim(char *psstr, char *astr);

void main()
{
	char *pstr, str[20];
	pstr="   Hello World!  ";

	printf("Before alltrim: %s\n", pstr);
	alltrim(pstr, str);
	printf("After alltrim: %s\n", str);
	getchar();
}

void alltrim(char *psstr, char *astr)
{
	char *pend;

	//remove the blanks before the string
	while(*psstr==' ')
		psstr++;

	//remove the blanks after the string
	pend = psstr+strlen(psstr)-1;
	while(*pend==' ')
		pend--;

	//assignment
	while(psstr<=pend)
		*astr++ = *psstr++;
	*astr = '\0';
}
