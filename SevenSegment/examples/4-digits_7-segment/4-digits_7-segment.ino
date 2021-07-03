/********************
 * 4-digit 7-segment example
 * example by aboda243 2021/July/2
 * public.
 */
#include <SevenSegment.h>

#define pinA 2
#define pinB 3
#define pinC 4
#define pinD 5
#define pinE 6
#define pinF 7
#define pinG 8
#define pinDP 9
#define D1 10
#define D2 11 
#define D3 12
#define D4 13
int digitPins[]{D1,D2,D3,D4};// digit pins
int segPins[] {pinA,pinB,pinC,pinD,pinE,pinF,pinG,pinDP};//segment pins
int digits = 4;//digits(4-digits 7-segment)
SevenSegment seg(segPins,digitPins,COMMON_ANODE,digits);//(segment pins,digit pins,display type,digits)
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  seg.print("2021",1000);// use this function to print a string (has numbers, characters or phrases) when the length of string is 4 or less than 4, the second variable is the time for printing on display
  seg.reset();// use this function to reset the display
  delay(1000);
  seg.print("all usable characters [[ 1 2 3 4 5 6 7 8 9 0 a b c d e f g h i j l n o p q r s t u y - _ . [ ] ? ]]",300);// when the length of string is more than 4, the second variable is custom speed for movement
  delay(1000);
  seg.printDigit('y',D1);//print any char on any digit
  delay(1000);
}
