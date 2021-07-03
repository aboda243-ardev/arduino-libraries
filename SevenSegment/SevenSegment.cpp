#include "Arduino.h"
#include "SevenSegment.h"
int charsInArray = 37;
int Char[37][9] { 
            
            {1,1,1,1,1,1,0,0,'0'},//0
            {0,1,1,0,0,0,0,0,'1'},//1
            {1,1,0,1,1,0,1,0,'2'},//2
            {1,1,1,1,0,0,1,0,'3'},//3
            {0,1,1,0,0,1,1,0,'4'},//4
            {1,0,1,1,0,1,1,0,'5'},//5
            {1,0,1,1,1,1,1,0,'6'},//6
            {1,1,1,0,0,0,0,0,'7'},//7
            {1,1,1,1,1,1,1,0,'8'},//8
            {1,1,1,1,0,1,1,0,'9'}, //9
            {1,1,1,0,1,1,1,0,'a'},//A/1
            {0,0,1,1,1,1,1,0,'b'},//b/2
            {0,0,0,1,1,0,1,0,'c'},//C/3
            {0,1,1,1,1,0,1,0,'d'},//d/4
            {1,0,0,1,1,1,1,0,'e'},//E/5
            {1,0,0,0,1,1,1,0,'f'},//F/6
            {1,0,1,1,1,1,0,0,'g'},//G/7
            {0,1,1,0,1,1,1,0,'h'},//H/8
            {0,0,0,0,1,1,0,0,'i'},//I/9
            {0,1,1,1,1,0,0,0,'j'},//J/10
            {0,0,0,1,1,1,0,0,'l'},//L/11
            {0,0,1,0,1,0,1,0,'n'},//n/12
            {0,0,1,1,1,0,1,0,'o'},//o/13
            {1,1,0,0,1,1,1,0,'p'},//P/14
            {1,1,1,0,0,1,1,0,'q'},//q/15
            {0,0,0,0,1,0,1,0,'r'},//r/16
            {1,0,1,1,0,1,1,0,'s'},//S/17   looks like number 5
            {0,0,0,1,1,1,1,0,'t'},//t/18
            {0,1,1,1,1,1,0,0,'u'},//U/19
            {0,1,1,1,0,1,1,0,'y'},//y/20
            {0,0,0,0,0,0,0,1,'.'},//.
            {0,0,0,0,0,0,1,0,'-'},//dash/negative
            {0,0,0,1,0,0,0,0,'_'},//underscore
            {1,0,0,1,1,1,0,0,'['},//[
            {1,1,1,1,0,0,0,0,']'},//]
            {1,1,0,0,1,0,1,0,'?'},//?
            {0,0,0,0,0,0,0,0,' '}//blank
            
            };
SevenSegment::SevenSegment(int segPins[],int digitPins[],bool segMode,int digit){
pinMode(segPins[0], OUTPUT);     
pinMode(segPins[1], OUTPUT);     
pinMode(segPins[2], OUTPUT);     
pinMode(segPins[3], OUTPUT);     
pinMode(segPins[4], OUTPUT);     
pinMode(segPins[5], OUTPUT);     
pinMode(segPins[6], OUTPUT); 
pinMode(segPins[7], OUTPUT);  
if(digit == 4){
  
  pinMode(digitPins[0], OUTPUT);  
  pinMode(digitPins[1], OUTPUT);  
  pinMode(digitPins[2], OUTPUT);  
  pinMode(digitPins[3], OUTPUT); 
} else if(digit == 3){
  
  pinMode(digitPins[0], OUTPUT);  
  pinMode(digitPins[1], OUTPUT);  
  pinMode(digitPins[2], OUTPUT);  
  
} else if(digit == 2){
  pinMode(digitPins[0], OUTPUT);  
  pinMode(digitPins[1], OUTPUT);  
  
}
for(int i = 0; i < 8; i++) seg[i] = segPins[i];
for(int i = 0; i < digit; i++) digits[i] = digitPins[i];
mode = segMode;
digitCost = digit;
}

void SevenSegment::reset(){
  if(digitCost == 4){
  
  digitalWrite(digits[0], !mode);
  digitalWrite(digits[1], !mode);
  digitalWrite(digits[2], !mode);
  digitalWrite(digits[3], !mode); 
} else if(digitCost == 3){
  
  digitalWrite(digits[0], !mode);
  digitalWrite(digits[1], !mode);
  digitalWrite(digits[2], !mode);
  
} else if(digitCost == 2){
  digitalWrite(digits[0], !mode);
  digitalWrite(digits[1], !mode);
  
}
  for(byte i = 0 ; i < 8 ; i++){
  digitalWrite(seg[i],mode);
  }
}


void SevenSegment::printDigit(char Chara,int digitPort=-1)// for more than 1 digit
{ 
  reset(); 
  int character = -1;
  if(digitPort != -1) digitalWrite(digitPort,mode);
  for(int i = 0 ; i < charsInArray ; i++){
    
    if(Chara == Char[i][8]){
      character = i;
    }
  }
  if (character == -1){
    digitalWrite(seg[6],!mode);
  }else{
for(int i = 0;i<= 7;i++)
    {if(mode == COMMON_ANODE) digitalWrite(seg[i],!Char[character][i]);     
    else if(mode == COMMON_CATHODE) digitalWrite(seg[i],Char[character][i]);
      
    }
  }
}

/*
void SevenSegment::printDigit(char Chara) // for 1 digit
{ reset(); 
  int character = -1;
  for(int i = 0 ; i < charsInArray ; i++){
    
    if(Chara == Char[i][8]){
      character = i;
    }
  }
  if (character == -1){
    digitalWrite(seg[6],!mode);
  }else{
for(int i = 0;i<= 7;i++)
    {if(mode == COMMON_ANODE) digitalWrite(seg[i],!Char[character][i]);     
    else if(mode == COMMON_CATHODE) digitalWrite(seg[i],Char[character][i]);
      
    }
  }
};
*/

void SevenSegment::print(String Phrase,int Delay)
{
 if(digitCost == 4){
char char1 = Phrase.charAt(0);
char char2 = Phrase.charAt(1);
char char3 = Phrase.charAt(2);
char char4 = Phrase.charAt(3);

int stringLength = Phrase.length();

if(stringLength < 5){
  for(int ti = 0 ; ti <= (Delay / 8) ; ti++){
  if(1 > stringLength) char1 = ' ';
  else char1 = Phrase.charAt(0);
  if(2 > stringLength) char2 = ' ';
  else char2 = Phrase.charAt(1);
  if(3 > stringLength) char3 = ' ';
  else char3 = Phrase.charAt(2);
  if(4 > stringLength) char4 = ' ';
  else char4 = Phrase.charAt(3);

  printDigit(char1,digits[0]);
  delay(2);
  printDigit(char2,digits[1]);
  delay(2);
  printDigit(char3,digits[2]);
  delay(2);
  printDigit(char4,digits[3]);
  delay(2);
  }
}else{
for(int t = 0 ; t <= stringLength ; t++){
  for(int ti = 0 ; ti <= (Delay / 8) ; ti++){
 
  printDigit(char1,digits[0]);
  delay(2);
  printDigit(char2,digits[1]);
  delay(2);
  printDigit(char3,digits[2]);
  delay(2);
  printDigit(char4,digits[3]);
  delay(2);
}
  if(t + 1 > stringLength) char1 = ' ';
  else char1 = Phrase.charAt(t);
  if((t + 2) > stringLength) char2 = ' ';
  else char2 = Phrase.charAt(t + 1);
  if((t + 3) > stringLength) char3 = ' ';
  else char3 = Phrase.charAt(t + 2);
  if((t + 4) > stringLength) char4 = ' ';
  else char4 = Phrase.charAt(t + 3);
  
  
  
}
}
}else if (digitCost == 3){
char char1 = Phrase.charAt(0);
char char2 = Phrase.charAt(1);
char char3 = Phrase.charAt(2);
int stringLength = Phrase.length();

if(stringLength <= 3){
  for(int ti = 0 ; ti <= (Delay / 4) ; ti++){
  if(1 > stringLength) char1 = ' ';
  else char1 = Phrase.charAt(0);
  if(2 > stringLength) char2 = ' ';
  else char2 = Phrase.charAt(1);
  if(3 > stringLength) char3 = ' ';
  else char3 = Phrase.charAt(2);
  
 
  printDigit(char1,digits[0]);
  delay(2);
  printDigit(char2,digits[1]);
  delay(2);
  printDigit(char3,digits[2]);
  delay(2);
 
  }
}else{
for(int t = 0 ; t <= stringLength ; t++){
  for(int ti = 0 ; ti <= (Delay / 4) ; ti++){
 
   printDigit(char1,digits[0]);
  delay(2);
  printDigit(char2,digits[1]);
  delay(2);
  printDigit(char3,digits[2]);
  delay(2);
 
}
  if(t + 1 > stringLength) char1 = ' ';
  else char1 = Phrase.charAt(t);
  if((t + 2) > stringLength) char2 = ' ';
  else char2 = Phrase.charAt(t + 1);
  if((t + 3) > stringLength) char3 = ' ';
  else char3 = Phrase.charAt(t + 2);
  
  
  
  
}
}
}else if (digitCost == 2){
char char1 = Phrase.charAt(0);
char char2 = Phrase.charAt(1);


int stringLength = Phrase.length();

if(stringLength <= 2){
  for(int ti = 0 ; ti <= (Delay / 4) ; ti++){
  if(1 > stringLength) char1 = ' ';
  else char1 = Phrase.charAt(0);
  if(2 > stringLength) char2 = ' ';
  else char2 = Phrase.charAt(1);
  
  
  printDigit(char1,digits[0]);
  delay(2);
  printDigit(char2,digits[1]);
  delay(2);
  
  
  }
}else{
for(int t = 0 ; t <= stringLength ; t++){
  for(int ti = 0 ; ti <= (Delay / 4) ; ti++){
  
  printDigit(char1,digits[0]);
  delay(2);
  printDigit(char2,digits[1]);
  delay(2);
  
 
}
  if(t + 1 > stringLength) char1 = ' ';
  else char1 = Phrase.charAt(t);
  if((t + 2) > stringLength) char2 = ' ';
  else char2 = Phrase.charAt(t + 1);
  
  
  
  
  
}
}
}else if (digitCost == 1){
char char1 = Phrase.charAt(0);

int stringLength = Phrase.length();

if(stringLength <= 1){
  for(int ti = 0 ; ti <= (Delay / 2) ; ti++){
  if(1 > stringLength) char1 = ' ';
  else char1 = Phrase.charAt(0);
  
  
  printDigit(char1);
  delay(2);

  }
}else{
for(int t = 0 ; t <= stringLength ; t++){
  for(int ti = 0 ; ti <= (Delay / 2) ; ti++){
  
  printDigit(char1);
  delay(2);

 
 
}
  if(t + 1 > stringLength) char1 = ' ';
  else char1 = Phrase.charAt(t);
  
  
  
  
  
}
}
} 
}
