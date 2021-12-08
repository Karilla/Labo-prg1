/**
 * @file word.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef _WORD_H_
#define _WORD_H__
#include <string>

using namespace std;

class Word{
    public:
        Word(string textWord);
        Word();

        //Setter
        void setOccurence(int occurence);
        void setTextWord(string textWord);

        //Getter
        string getTextWord();
        int getOccurence();

    private:
        string textWord;
        int occurence;
};

#endif
