#include <DynamixelWorkbench.h>

DynamixelWorkbench dxl_wb;

String control;
String prev_k;
void forward();
void stopping();
void left();
void right();

#if defined(__OPENCM904__)
  #define DEVICE_NAME "3" //Dynamixel on Serial3(USART3)  <-OpenCM 485EXP
#elif defined(__OPENCR__)
  #define DEVICE_NAME ""
#endif   
#define BAUDRATE  1000000
#define DXL_ID    1
#define DXL_ID2    2
#define DEVICE_NAME ""
uint8_t dxl_id1 = DXL_ID;
  uint8_t dxl_id2 = DXL_ID2;
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
Serial.setTimeout(1);
  const char *log;
  uint8_t dxl_id1 = DXL_ID;
  uint8_t dxl_id2 = DXL_ID2;
  uint16_t model_number = 0;
//dxl_wb.begin("",1000000);
dxl_wb.init(DEVICE_NAME,BAUDRATE, &log);
dxl_wb.ping(dxl_id1,&model_number, &log);
dxl_wb.ping(dxl_id2,&model_number, &log);

dxl_wb.wheelMode(dxl_id1, 0, &log);
dxl_wb.wheelMode(dxl_id2, 0, &log);


}

void loop() {
  // put your main code here, to run repeatedly:
while (!Serial.available());
 control = Serial.readString();
 if (control=="w"){
  if (control!=prev_k){
  forward();
  }
  prev_k = control;
 }else if (control == " "){
  if (control!=prev_k){
  stopping();
  }
  prev_k = control;
  
 }else if (control == "d"){
  if (control!=prev_k){
  right();
  }
  prev_k = control;
  
  
 }else if (control == "a"){
  if (control!=prev_k){
  left();
  }
  prev_k = control;
  
 }else if (control == "s"){
  if (control!=prev_k){
  back();
  }
  prev_k = control;
  
 }
}
//}

void forward(){
dxl_wb.goalVelocity(dxl_id1, (int32_t)-250);
dxl_wb.goalVelocity(dxl_id2, (int32_t)-250);
}
void stopping(){
dxl_wb.goalVelocity(dxl_id1, (int32_t)0);
dxl_wb.goalVelocity(dxl_id2, (int32_t)0);
}
void left(){
  dxl_wb.goalVelocity(dxl_id1, (int32_t)-250);
  dxl_wb.goalVelocity(dxl_id2, (int32_t)-125);
}
void right(){
  dxl_wb.goalVelocity(dxl_id1, (int32_t)-125);
  dxl_wb.goalVelocity(dxl_id2, (int32_t)-250);
}
void back(){
  dxl_wb.goalVelocity(dxl_id1, (int32_t)250);
  dxl_wb.goalVelocity(dxl_id2, (int32_t)250);
}
