//
// Created by bdela on 08/12/2021.
//

#include "word.h"

using namespace std;

Word::Word(string text) {
    textWord = text;
    occurence = 0;
}

void Word::setOccurence(int occ) {
    occurence = occ;
}

void Word::setTextWord(string text) {
    textWord = text;
}

int Word::getOccurence() {
    return  occurence;
}

string Word::getTextWord() {
    return textWord;
}

Word Word::operator+(const int i) const {
    Word temp(textWord);
    temp.occurence += 1;
    return temp;
}

ostream& operator<<(ostream& lhs, const Word& rhs){
    lhs << rhs.textWord << string(": ") << int(rhs.occurence);
    return lhs;
}