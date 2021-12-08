/**
 * @file word.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "word.hpp"

Word::Word(string textWord)
{
    this->textWord = textWord;
    this->occurence = 0;
}

Word::Word()
{
    this->textWord = "";
    this->occurence = 0;
}

void Word::setOccurence(int occurence)
{
    this.occurence = occurence;
}

void Word::setTextWord(string textWord)
{
    this.textWord = textWord;
}

int Word::getOccurence()
{
    return this->occurence;
}

string Word::getTextWord()
{
    return this.textWord;
}