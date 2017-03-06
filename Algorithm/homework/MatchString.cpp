#include <iostream>
using namespace std;

class MatchCharacter {
private:
    void KMPNext(char Template[], int next[]) {
        int count = 0, nextIndex = 0;
        next[0] = -1;
        next[1] = 0;
        while(Template[count] != '\0') {
            if(count<1) {
                count++;
                continue;
            }
            if(Template[count]==Template[nextIndex]) {
                count++;
                nextIndex++;
                next[count] = nextIndex;
            } else {
                nextIndex = next[nextIndex];
                next[++count] = nextIndex+1;
            }
        }
    }
public:
    int BF(char Search[], char Template[]) {
        int startIndex = 0, cmpS = 0, cmpT = 0;
        while(Search[cmpS]!='\0'&&Template[cmpT]!='\0'){
            if(Search[cmpS]==Template[cmpT]) {
                cmpS++;
                cmpT++;
            } else {
                startIndex++;
                cmpS = startIndex;
                cmpT=0;
            }
        }
        if(Template[cmpT]=='\0') {
            return startIndex;
        }
        return -1;
    }
    
    int KMP(char Search[], char Template[]){
        int cmpS = 0, cmpT = 0;
        int next[1000];
        KMPNext(Template, next);
        while(Search[cmpS]!='\0'&&Template[cmpT]!='\0') {
            if(Search[cmpS]==Template[cmpT]) {
                cmpS++;
                cmpT++;
            } else {
                cmpT = next[cmpT];
                if(cmpT==-1) {
                    cmpT++;
                    cmpS++;
                }
            }
        }
        if(Template[cmpT]=='\0') {
            
            return cmpS-(int)strlen(Template);
        }
        return -1;
    }
};
