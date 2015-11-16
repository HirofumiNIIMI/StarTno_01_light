/**
 * digitalInOut.ino
 * RTno is RT-middleware and arduino.
 *
 * This is a simple example for RTno begineer.
 * This program just use general I/O pin.
 *
 * I/O pin settings:
 * Pin [ 8,  9, 10, 11, 12, 13] ... Output Pins.
 * Pin [ 2,  3,  4,  5,  6,  7] ... Input Pins.
 *
 * I/O port settings:
 * Port "in0"
 *  -type       : TimedLongSeq
 *  -data length: 6
 *  -description: each data element corresponds to the output pin level.
 *                If data is 0, corresponding output pin will LOW (0 Volt)
 *                If data is non-zero, pin will HIGH (Vcc level).
 *                The 6th element corresponds to the 13th pin (LED pin),
 *                so you can confirm this program's behavior without any 
 *                modification to the arduino board.
 *
 * Port "out0"
 *  -type       : TimedLongSeq
 *  -data length: 6
 *  -description: each data element corresponds to the input pin level.
 *                If data is 0, corresponding output pin will LOW (0 Volt)
 *                If data is non-zero, pin will HIGH (Vcc level).
 *
 */

#include <UART.h>
#include <RTno.h>
#include <Servo.h>

//===============================================
// 定義
//===============================================
Servo Servo09;
Servo Servo10;
Servo Servo11;
Servo Servo12;


int ServoVal09;
int ServoVal10;
int ServoVal11;
int ServoVal12;


/**
 * This function is called at first.
 * conf._default.baudrate: baudrate of serial communication
 * exec_cxt.periodic.type: reserved but not used.
 */
void rtcconf(config_str& conf, exec_cxt_str& exec_cxt) {
  conf._default.connection_type = ConnectionTypeSerial1;
  conf._default.baudrate = 57600;
  exec_cxt.periodic.type = ProxySynchronousExecutionContext;
}

/** 
 * Declaration Division:
 *
 * DataPort and Data Buffer should be placed here.
 *
 * Currently, following 6 types are available.
 * TimedLong:
 * TimedDouble:
 * TimedFloat:
 * TimedLongSeq:
 * TimedDoubleSeq:
 * TimedFloatSeq:
 *
 * Please refer following comments. If you need to use some ports,
 * uncomment the line you want to declare.
 **/
TimedLong in0;
InPort<TimedLong> in0In("DC_motor_243_785", in0); 
TimedLong in1;
InPort<TimedLong> in1In("Servo09", in1);
TimedLong in2;
InPort<TimedLong> in2In("Servo10", in2);
TimedLong in3;
InPort<TimedLong> in3In("Servo11", in3);
TimedLong in4;
InPort<TimedLong> in4In("Servo12", in4);
TimedLong in5;
InPort<TimedLong> in5In("DoReMi1047", in5);

//////////////////////////////////////////
// on_initialize
//
// This function is called in the initialization
// sequence. The sequence is triggered by the
// PC. When the RTnoRTC is launched in the PC,
// then, this function is remotely called
// through the USB cable.
// In on_initialize, usually DataPorts are added.
//
//////////////////////////////////////////
int RTno::onInitialize() {
  /* Data Ports are added in this section.
  */
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(5, OUTPUT); 
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);   
  addInPort(in0In);
  addInPort(in1In);
  addInPort(in2In);
  addInPort(in3In);
  addInPort(in4In);
  addInPort(in5In);  
  return RTC_OK; 
}

////////////////////////////////////////////
// on_activated
// This function is called when the RTnoRTC
// is activated. When the activation, the RTnoRTC
// sends message to call this function remotely.
// If this function is failed (return value 
// is RTC_ERROR), RTno will enter ERROR condition.
////////////////////////////////////////////
int RTno::onActivated() {
  // Write here initialization code.
  Servo09.attach(9);
  Servo10.attach(10);
  Servo11.attach(11);
  Servo12.attach(12);
  
  ServoVal09 = 90;
  ServoVal10 = 90;
  ServoVal11 = 90;
  ServoVal12 = 90;
 
  delay(30);
  return RTC_OK; 
}

/////////////////////////////////////////////
// on_deactfivated
// This function is called when the RTnoRTC
// is deactivated.
/////////////////////////////////////////////
int RTno::onDeactivated()
{
  // Write here finalization code.

  return RTC_OK;
}

//////////////////////////////////////////////
// This function is repeatedly called when the 
// RTno is in the ACTIVE condition.
// If this function is failed (return value is
// RTC_ERROR), RTno immediately enter into the 
// ERROR condition.r
//////////////////////////////////////////////
int RTno::onExecute() {
  /*
   * Input digital data
   */
  if(in0In.isNew()) {
    in0In.read();
    if(in0.data ==1){
      digitalWrite(2, HIGH); 
      digitalWrite(4, LOW);
      analogWrite(3, 255);     
      digitalWrite(7, HIGH); 
      digitalWrite(8, LOW);
      analogWrite(5, 255); 
    }
    else if(in0.data ==2){
      digitalWrite(2, HIGH); 
      digitalWrite(4, LOW);
      analogWrite(3, 255);    
      digitalWrite(7, HIGH); 
      digitalWrite(8, LOW);
      analogWrite(5, 128);   
    }
    else if(in0.data ==3){
      digitalWrite(2, HIGH); 
      digitalWrite(4, LOW);
      analogWrite(3, 255);     
      digitalWrite(7, LOW); 
      digitalWrite(8, HIGH);
      analogWrite(5, 255);   
    }
    else if(in0.data ==4){
      digitalWrite(2, LOW); 
      digitalWrite(4, HIGH);
      analogWrite(3, 255);      
      digitalWrite(7, LOW); 
      digitalWrite(8, HIGH);
      analogWrite(5, 128);   
    }    
    else if(in0.data ==5){
      digitalWrite(2, LOW); 
      digitalWrite(4, HIGH);
      analogWrite(3, 255);      
      digitalWrite(7, LOW); 
      digitalWrite(8, HIGH);
      analogWrite(5, 255);     
    }   
    else if(in0.data ==6){
      digitalWrite(2, LOW); 
      digitalWrite(4, HIGH);
      analogWrite(3, 128);      
      digitalWrite(7, LOW); 
      digitalWrite(8, HIGH);
      analogWrite(5, 255);       
    } 
    else if(in0.data ==7){
      digitalWrite(2, LOW); 
      digitalWrite(4, HIGH);
      analogWrite(3, 255);      
      digitalWrite(7, HIGH); 
      digitalWrite(8, LOW);
      analogWrite(5, 255);   
    }       
    else if(in0.data ==8){
      digitalWrite(2, HIGH); 
      digitalWrite(4, LOW);
      analogWrite(3, 128); 
      digitalWrite(7, HIGH); 
      digitalWrite(8, LOW);
      analogWrite(5, 255); 
    }
    else{
      analogWrite(3, 0);
      analogWrite(5, 0); 
    }
  }
  delay(3);

   
  if(in1In.isNew()) {
    in1In.read();
    ServoVal09 = in1.data;
    //ServoVal09 = map(ServoVal09,0,180,45,135);
  }
  Servo09.write(ServoVal09);
  delay(3);
  
  if(in2In.isNew()) {
    in2In.read();
    ServoVal10 = in2.data;
  //  ServoVal10 = map(ServoVal10,0,180,45,135);
  }
  Servo10.write(ServoVal10);
  delay(3);
  
  if(in3In.isNew()) {
    in3In.read();
    ServoVal11 = in3.data;
    ServoVal11 = map(ServoVal11,0,180,45,150);
  }
  Servo11.write(ServoVal11);
  delay(3);
  
  if(in4In.isNew()) {
    in4In.read();
    ServoVal12 = in4.data;
    ServoVal12 = map(ServoVal12,0,180,135,30);
  }
  Servo12.write(ServoVal12);
  delay(3);
  
  if(in5In.isNew()) {
    in5In.read();
    if(in5.data ==1 || in5.data ==180){
      digitalWrite(A0,HIGH);
      tone(A1,1047,300) ;  //do
    }
    else if(in5.data ==2){
      digitalWrite(A0,HIGH);
      tone(A1,1175,300) ;  //re
    }
    else if(in5.data ==3){
      digitalWrite(A0,HIGH);
      tone(A1,1319,300) ;  //me
    }
    else if(in5.data ==4){
      digitalWrite(A0,HIGH);
      tone(A1,1397,300);  //fa
    }    
    else if(in5.data ==5){
      digitalWrite(A0,HIGH);
      tone(A1,1568,300) ;  //so
    }    
    else if(in5.data ==6){
      digitalWrite(A0,HIGH);
      tone(A1,1760,300) ;  //la
    }    
    else if(in5.data ==7){
      digitalWrite(A0,HIGH);
      tone(A1,1976,300) ;  //ti
    }    
    else if(in5.data ==8){
      digitalWrite(A0,HIGH);
      tone(A1,2093,300) ;  //do
    }
    else {
      digitalWrite(A0,LOW);
      noTone(A1);
    }    
  }
  return RTC_OK; 
}


//////////////////////////////////////
// on_error
// This function is repeatedly called when
// the RTno is in the ERROR condition.
// The ERROR condition can be recovered,
// when the RTno is reset.
///////////////////////////////////////
int RTno::onError()
{
  return RTC_OK;
}

////////////////////////////////////////
// This function is called when 
// the RTno is reset. If on_reset is
// succeeded, the RTno will enter into
// the INACTIVE condition. If failed 
// (return value is RTC_ERROR), RTno
// will stay in ERROR condition.ec
///////////////////////////////////////
int RTno::onReset()
{
  return RTC_OK;
}


