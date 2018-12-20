#include<MeShield.h>
MeJoystick joystick(8);
MeRGBLed rgbled_1(6,4);
MePotentiometer potentiometer(7);
MeUltrasonicSensor ultraSensor(4);
Me7SegmentDisplay disp(3);
int bright=0;
int x = 0;
int r[]={28,0,0};
int g[]={0,28,0};
int b[]={0,0,28};
int joy;
int y;
int t;

void setup() {
Serial.begin(9600);
}
void loop(){
for(;;){

bright = potentiometer.read()/100;
for(y=1;y<10;y++){
joy=joystick.readX();
delay(20);
if(joy>20)
x++;
if(joy<-20)
x--;
if (x>2)
x=0;
if (x<0)
x=2;
disp.display(y);
LED(r[x],g[x],b[x],bright);
disp.display((y*10));
delay(50);
LED(r[x],g[x],b[x],bright);
disp.display((y*100));
delay(50);
LED(r[x],g[x],b[x],bright);
disp.display((y*1000));
delay(50);
if(ultraSensor.distanceCm()<15)
break;
LED(r[x],g[x],b[x],bright);
disp.display((y*100));
delay(50);
LED(r[x],g[x],b[x],bright);
disp.display((y*10));
delay(50);
LED(r[x],g[x],b[x],bright);
disp.display(y);
delay(50);
}
if(ultraSensor.distanceCm()<15)
break;
}

    rgbled_1.setColor(0, 60, 0 , 0);
    rgbled_1.show();
    for(t=5;t>=0;t--)
    {
      disp.display(t);
      delay(1000);
    }
      rgbled_1.setColor(0, 0, 60 , 0);
    rgbled_1.show();
     for(t=5;t>=0;t--)
    {
      disp.display(t);
      delay(1000);
    }
      rgbled_1.setColor(0, 255, 255 , 0);
    rgbled_1.show();
     for(t=2;t>=0;t--)
    {
      disp.display(t);
      delay(1000);
    }

}
void LED(int r,int g,int b,int bright) {
 for(int i=1;i<5;i++){
 
 rgbled_1.setColor(0, 0, 0 , 0);
 rgbled_1.show();
 rgbled_1.setColor(i, (r*bright), (g*bright) , (b*bright));
 rgbled_1.show();
 
 delay(100);
  }
}
void seg(int x){
if(x=1)
for(y=1;y<10;y++){
disp.display(y);
disp.display((y*10));
disp.display((y*100));
disp.display((y*1000));}}
