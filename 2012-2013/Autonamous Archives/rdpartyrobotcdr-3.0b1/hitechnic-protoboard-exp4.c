#pragma config(Sensor, S1,     HTPB,                sensorI2CCustom9V)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: hitechnic-protoboard-exp4.c 112 2012-10-04 17:44:38Z xander $
 */

/**
 * hitechnic-protoboard.h provides an API for the HiTechnic Protoboard.  This is program 4
 * for the HTPB experimenter's kit.
 *
 * Changelog:
 * - 0.1: Initial release
 *
 * Credits:
 * - Big thanks to HiTechnic for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 3.51 AND HIGHER.
 * Xander Soldaat (xander_at_botbench.com)
 * 07 May 2010
 * version 0.1
 */

#include "drivers/hitechnic-protoboard.h"

task main() {
  // Local variables
  int inputdata;

  while(true) {
    // Read a 10bit wide analogue value from A0
    inputdata = HTPBreadADC(HTPB, 0, 10);

    eraseDisplay();
    nxtDisplayTextLine(1, "%d", inputdata);

    wait1Msec(50);
  }
}

/*
 * $Id: hitechnic-protoboard-exp4.c 112 2012-10-04 17:44:38Z xander $
 */
