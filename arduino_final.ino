#include <LiquidCrystal.h>  //包含LiquidCrystal.h標頭檔
#include <Keypad.h>         //包含Keypad.h標頭檔
#include <Servo.h>          //包含Servo.h標頭檔
#define LockAngle 90        //定義上鎖角度
#define UnlockAngle 0       //定義解鎖角度

Servo myservo;              //建構Servo物件
int servostate;             //伺服馬達狀態
int a=0, b=0, c=0, d=0;
int var=0; 
int C1=1,C2=2,C3=3,C4=4;    //設定密碼為1234

const byte ROWS = 4; 
const byte COLS = 4;

//定義鍵盤陣列
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

//鍵盤對應的pin
byte pinRows[ROWS] = {0, 6, 5, 4}; 
byte pinCols[COLS] = {3, 2, 1};

Keypad keypad = Keypad( makeKeymap(keys), pinRows, pinCols, ROWS, COLS );
LiquidCrystal LCD(8,9,10,11,12,13);

void setup(){
  LCD.begin(16,2); 
  pinMode(A0,OUTPUT); 
  pinMode(A1,OUTPUT); 
  myservo.attach(7); 
  myservo.write(LockAngle);
  servostate = 1;
}
  
void loop(){  
  char key = keypad.getKey();
  if (key){
    LCD.setCursor(11+var,1);
    LCD.print(key);
    LCD.setCursor(11+var,1);
    LCD.print('*');
    key=key-48;
    var++; 
    switch(var){
      case 1:
      	a=key; 
    	break;
      case 2:
    	b=key; 
    	break;
      case 3:
    	c=key; 
    	break;
      case 4:
    	d=key; 
   		delay(50);
      if(a==C1 && b==C2 && c==C3 && d==C4){  //輸入密碼＝密碼正確
          LCD.clear();                       //清空螢幕
    	  LCD.setCursor(4,0);
    	  LCD.print("Door");
          LCD.setCursor(4,1);
                         					 //門解鎖
          LCD.print("UnLock");
          myservo.write(UnlockAngle);
          servostate = 0;
          
          digitalWrite(A0,HIGH);             
    	  delay(1000); 
          LCD.clear();
          digitalWrite(A0,LOW);             //亮綠燈
          myservo.write(LockAngle);			//門上鎖
          servostate = 1;
        }
      else{                                 //密碼錯誤
        LCD.clear();
        LCD.setCursor(4,0);
        LCD.print("Password");
        LCD.setCursor(4,1);
        LCD.print("Incorrect");
        myservo.write(LockAngle);			//門上鎖
        servostate = 1;
        digitalWrite(A1,HIGH);              
        delay(1000); 
        LCD.clear();
        digitalWrite(A1,LOW);              //亮紅燈 
      }
      var=0;
   	  LCD.clear();
      break;
    }
  }
  if(!key){                               //未輸入密碼
    LCD.setCursor(0,0);
    LCD.print("Enter Password");
    LCD.setCursor(0,1);
    LCD.print("to UnLock:");
    
  }
  delay(2);
}
