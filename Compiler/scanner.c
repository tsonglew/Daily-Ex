#include <stdio.h>

void scanner() {
    token = NULL;
    getch();
    getbc();
    if (letter(ch)) {
        while(letter(ch) || digit(ch)) {
            concat();
            getch();
        }
        retract();
        c = reserve();
        if (c!=10) {
            return (c, token);
        } else {
            return (10, token);
        }
    } else if (digit(ch)) {
        while(digit(ch)) {
            concat();
            getch();
        }
        retract();
        return (11, dtb());
    } else {
        switch(ch) {
            case '+': return(13, NULL); break;
            case '-': return(14, NULL); break;
            case '*': return(15, NULL); break;
            case '/': return(16, NULL); break;
            case '<': {
                getch();
                if (ch=='=') {
                    return (17, NULL);
                } else if (ch=='>') {
                    return (18, NULL);
                }
                retract();
                return (19, NULL);
                break;
            }
            case ':': {
                getch();
                if(ch=='=') {
                    return (22, NULL);
                }
                retract();
                return (21, NULL);
                break;
            }
            case ';': {
                return (23, NULL);
                break;
            }
            default: {
                error();
                break;
            }
        } 
    }
}
