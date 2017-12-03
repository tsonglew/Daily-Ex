#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _KEY_WORD_END "keyword_end"

typedef struct {
	int typenum;
	char* word;
} WORD;

WORD* lex_res[255];
char input[255];
char token[255];
char end;
int p_input;
int p_token;
int p_s;
int p_lr;

char ch;
char* rwtab[] = {"begin", "if", "then", "while", "do", "end", _KEY_WORD_END};

WORD* scanner();
void expression();


void error() {
	printf("error\n");
	exit(-1);
}

void scan() {
	++p_s;
	if (p_s >= p_lr) {
		error();
	}
}

void factor() {
	if ((lex_res[p_s]->typenum== 10) || (lex_res[p_s]->typenum == 20)) {
		scan();
	} else if (lex_res[p_s]->typenum == 26) {
		scan();
		expression();
		if (lex_res[p_s]->typenum == 27) {
			scan();
		} else {
			error();
		}
	} else {
		error();
	}
}

void term() {
	while(1) {
		factor();
		if (lex_res[p_s]->typenum == 24 || lex_res[p_s]->typenum == 25) {
			scan();
		} else {
			return;
		}
	}
}

void expression() {
	while(1) {
		term();
		if (lex_res[p_s]->typenum == 22 || lex_res[p_s]->typenum == 23) {
			scan();
		}
		return;
	}
}

void statement() {
	if (lex_res[p_s]->typenum== 10) {
		scan();
		if (lex_res[p_s]->typenum == 41) {
			scan();
			expression();
		} else {
			error();
		}
	} else {
		error();
	}
}

void yucu() {
	while(1) {
		statement();
		if (lex_res[p_s]->typenum == 34) {
			scan();
			if (lex_res[p_s]->typenum == 6) {
				return;
			}
		} else {
			return;
		}
	}
}

void lrparser() {
	if (lex_res[p_s]->typenum == 1) {
		scan();
		yucu();
		if (lex_res[p_s]->typenum == 6) {
			scan();
			if (p_s >= p_lr) {
				return;
			} else {
				error();
			}
		} else {
			error();
		}
	} else {
		error();
	}
}

int main(void) {
	p_lr = 0;
	int over = 1;
	printf("Enter Your Words(end with #):");
	scanf("%[^#]s", input);
	while (over<1000 && over!=-1) {
		WORD* oneword =  malloc(sizeof(WORD));
		oneword = scanner();
		if (oneword->typenum < 1000) {
			lex_res[p_lr++] = oneword;
		}
		over = oneword->typenum;
	}

	p_s = 0;
	lrparser();
	printf("success\n");
	while(--p_lr >= 0) {
		free(lex_res[p_lr]);
	}
	return(0);
}

char m_getch() {
	ch = input[p_input++];
	return(ch);
}

void getbc() {
	while (ch==' '|| (int)ch==10) {
		ch = input[p_input++];
	}
}

void concat() {
	token[p_token++] = ch;
	token[p_token] = '\0';
}

void retract() {
	--p_input;
}

int reserve() {
	int i = 0;
	while (strcmp(rwtab[i], _KEY_WORD_END)) {
		if (!strcmp(rwtab[i], token)) {
			return(i+1);
		}
		++i;
	}
	return(10);
}

int letter() {
	return ((ch>='a'&&ch<='z') || (ch>='A'&&ch<='Z'))? 1: 0;
}

int digit() {
	return((ch>='0'&&ch<='9')? 1: 0);
}

WORD* scanner() {
	WORD* myword = malloc(sizeof(WORD));
	myword->typenum = 10;
	myword->word = "";
	p_token = 0;
	m_getch();
	getbc();
	if (letter()) {
		while(letter() || digit()) {
			concat();
			m_getch();
		}
		retract();
		myword->typenum = reserve();
		myword->word = token;
		return(myword);
	} else if (digit()) {
		while(digit()) {
			concat();
			m_getch();
		}
		retract();
		myword->typenum = 20;
		myword->word = token;
		return(myword);
	} else {
		switch (ch) {
			case '=': {
				m_getch();
				if (ch == '=') {
					myword->typenum = 39;
					myword->word = "==";
					return(myword);
				}
				retract();
				myword->typenum = 21;
				myword->word = "=";
				return(myword);
				break;
			}
			case '+': {
				myword->typenum = 22;
				myword->word = "+";
				return(myword);
				break;
			}
			case '-': {
				myword->typenum = 23;
				myword->word = "-";
				return(myword);
				break;
			}
			case '*': {
				myword->typenum = 24;
				myword->word = "*";
				return(myword);
				break;
			}
			case '/': {
				myword->typenum = 25;
				myword->word = "/";
				return(myword);
				break;
			}
			case '(': {
				myword->typenum = 26;
				myword->word = "(";
				return(myword);
				break;
			}
			case ')': {
				myword->typenum = 27;
				myword->word = ")";
				return(myword);
				break;
			}
			case ':': {
				m_getch();
				if (ch == '=') {
					myword->typenum = 41;
					myword->word = ":=";
					return(myword);
				}
				retract();
				myword->typenum = 33;
				myword->word = ":";
				return(myword);
				break;
			}
			case ';': {
				myword->typenum = 34;
				myword->word = ";";
				return(myword);
				break;
			}
			case '\0': {
				myword->typenum = 1000;
				myword->word = "OVER";
				return(myword);
				break;
			}
			default: {
				myword->typenum = -1;
				myword->word = "ERROR";
				return(myword);
			}
		}
	}
	return(myword);
}
