#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _KEY_WORD_END "keyword_end"

typedef struct {
	int typenum;
	char* word;
} WORD;

char input[255]; // 输入缓冲
char token[255]; // 单词缓冲
char end;
int p_input;
int p_token;

char ch;
char* rwtab[] = {"begin", "if", "then", "while", "do", "end", _KEY_WORD_END};

// 取input中下一个字符
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

// 检索关键字表格
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

// 判断是否字母
int letter() {
	return ((ch>='a'&&ch<='z') || (ch>='A'&&ch<='Z'))? 1: 0;
}

// 判断是否数字
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
			case '[': {
				myword->typenum = 28;
				myword->word = "[";
				return(myword);
				break;
			}
			case ']': {
				myword->typenum = 29;
				myword->word = "]";
				return(myword);
				break;
			}
			case '{': {
				myword->typenum = 30;
				myword->word = "{";
				return(myword);
				break;
			}
			case '}': {
				myword->typenum = 31;
				myword->word = "}";
				return(myword);
				break;
			}
			case ',': {
				myword->typenum = 32;
				myword->word = ",";
				return(myword);
				break;
			}
			case ':': {
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
			case '>': {
				m_getch();
				if (ch == '=') {
					myword->typenum = 37;
					myword->word = ">=";
					return(myword);
				}
				retract();
				myword->typenum = 35;
				myword->word = ">";
				return(myword);
				break;
			}
			case '<': {
				m_getch();
				if (ch == '=') {
					myword->typenum = 38;
					myword->word = "<=";
					return(myword);
				}
				retract();
				myword->typenum = 36;
				myword->word = "<";
				return(myword);
				break;
			}
			case '!': {
				m_getch();
				if (ch == '=') {
					myword->typenum = 40;
					myword->word = "!=";
					return(myword);
				}
				retract();
				myword->typenum = -1;
				myword->word = "ERROR";
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

int main(void) {
	int over = 1;
	WORD* oneword =  malloc(sizeof(WORD));
	printf("Enter Your Words(end with #):");
	scanf("%[^#]s", input);
	p_input = 0;
	printf("Your Wrods: \n%s\n", input);
	while (over<1000 && over!=-1) {
		oneword = scanner();
		if (oneword->typenum < 1000) {
			printf("(%d, %s)", oneword->typenum, oneword->word);
		}
		over = oneword->typenum;
	}
	return(0);
}