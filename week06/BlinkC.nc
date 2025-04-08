#include "Timer.h"

module BlinkC @safe()
  4 {
  5         uses interface Timer<TMilli> as Timer0;
  6         uses interface Leds;
  7         uses interface Boot;
  8 }
  9 implementation
 10 {
 11         event void Boot.booted()
 12         {
 13                 call Timer0.startPeriodic( 250 );
 14         }
 15
 16         event void Timer0.fired()
 17         {
 18                 call Leds.led0Toggle();
 19         }
 20 }
