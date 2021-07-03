/********************
 * 1-digit 7-segment example
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
int digitPins[]{};// nothing because there is only 1 digit
int segPins[] {pinA,pinB,pinC,pinD,pinE,pinF,pinG,pinDP};//segment pins
int digits = 1;//digits(1-digits 7-segment)
SevenSegment seg(segPins,digitPins,COMMON_ANODE,digits);//(segment pins,digit pins,display type,digits)
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  seg.print("using print for 1 digit is not good",300);
  seg.reset();
  delay(1000);
}
