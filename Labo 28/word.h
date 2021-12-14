//
// Created by bdela on 08/12/2021.
//

#ifndef LABO_28_WORD_H
#define LABO_28_WORD_H
#include <string>
#include <iostream>

class Word {
    friend std::ostream& operator<<(std::ostream& lhs, const Word& rhs);
public:
    Word(std::string text);

    void setTextWord(std::string text);
    void setOccurence(int occ);

    std::string getTextWord();
    int getOccurence();

    Word operator+(const int i) const;
private:
    std::string textWord;
    int occurence;
};

#endif //LABO_28_WORD_H
