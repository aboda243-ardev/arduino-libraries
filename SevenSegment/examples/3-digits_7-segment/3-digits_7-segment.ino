/********************
 * 3-digit 7-segment example
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
int digitPins[]{D1,D2,D3};// digit pins
int segPins[] {pinA,pinB,pinC,pinD,pinE,pinF,pinG,pinDP};//segment pins
int digits = 3;//digits(3-digits 7-segment)
SevenSegment seg(segPins,digitPins,COMMON_ANODE,digits);//(segment pins,digit pins,display type,digits)
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  char C = '3';
  seg.printDigit(C,D1);//print any char on any digit
  delay(300);
  seg.printDigit(C,D2);
  delay(300);
  seg.printDigit(C,D3);
  delay(300);
  seg.print("dig",300);//print any string on the display(contains less or more then 3 characters)
  C = '7';
  seg.printDigit(C,D1);
  delay(300);
  seg.printDigit(C,D2);
  delay(300);
  seg.printDigit(C,D3);
  delay(300);
  seg.print("seg",300);
  
}
