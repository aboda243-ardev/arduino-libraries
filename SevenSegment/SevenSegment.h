/************
*SevenSegment library by aboda243
*published 2021/july/3
*this library is public
************/
#ifndef SevenSegment_h
#define SevenSegment_h

#include <Arduino.h>
#include "array.h"
class SevenSegment
{
  public:
  SevenSegment(int segPins[],int digitPins[],bool segMode,int digit);
  void reset();
  void printDigit(char Chara,int digitPort=-1);
  void print(String Phrase,int Delay);
  private:
  int seg[8];
  int digits[4];
  bool mode;
  int digitCost;
};

#endif
