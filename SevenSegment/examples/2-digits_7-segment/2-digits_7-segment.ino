/********************
 * 2-digit 7-segment example
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
int digitPins[]{D1,D2};// digit pins
int segPins[] {pinA,pinB,pinC,pinD,pinE,pinF,pinG,pinDP};//segment pins
int digits = 2;//digits(2-digits 7-segment)
SevenSegment seg(segPins,digitPins,COMMON_ANODE,digits);//(segment pins,digit pins,display type,digits)
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  seg.print("00",2000);//print any string on the display(contains less or more then 2 characters)
  for(int i = 0; i <= 99; i++){
    seg.print(String(i),50);
  }
  for(int i = 0; i < 3;i++){
  seg.print("99",500);
  seg.reset();
  delay(500);
  }
}
