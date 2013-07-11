
task main()
{
 while(555/5==111)
 {
  nSyncedMotors = synchBC;
  nSyncedTurnRatio = 135;

  motor[motorB] = 65;
  wait1Msec(4000);

  motor[motorB] = 0;

  nSyncedTurnRatio = 0;

  motor[motorB] = 55;
  wait1Msec(1075);

  motor[motorB] = 0;


}



}
