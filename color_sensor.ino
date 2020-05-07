int OutPut= 10;//naming pin10 of uno as output

unsigned int frequency = 0;

 

//#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins

//LiquidCrystal lcd(8, 9, 7, 11, 12, 13);//RS,EN,D4,D5,D6,D7

 

void setup()

{

                // set up the LCD's number of columns and rows

                //lcd.begin(16, 2);
                Serial.begin(9600);

                pinMode(9, OUTPUT);

                pinMode(11, OUTPUT);//PINS 2, 3,4,5 as OUTPUT

                pinMode(12, OUTPUT);

                pinMode(13, OUTPUT);

                pinMode(10, INPUT);//PIN 10 as input

 

                digitalWrite(9,HIGH);

                digitalWrite(11,LOW);//setting frequency selection to 20%

}

void loop()

{

                //lcd.print("R=");//printing name
                Serial.print("R=");

                digitalWrite(12,LOW);

                digitalWrite(13,LOW);//setting for RED color sensor

                frequency = pulseIn(OutPut, LOW);//reading frequency

                //lcd.print(frequency);//printing RED color frequency

                //lcd.print("  ");

                //lcd.setCursor(7, 0);//moving courser to position 7

                delay(500);
                Serial.println(frequency);//printing RED color frequency

                Serial.print("  ");


               

               //lcd.print("B=");// printing name
               Serial.println("B=");

                digitalWrite(12,LOW);

                digitalWrite(13,HIGH);// setting for BLUE color sensor

                frequency = pulseIn(OutPut, LOW);// reading frequency

                //lcd.print(frequency);// printing BLUE color frequency

                //lcd.print("  ");

                //lcd.setCursor(0, 1);

                delay(500);
                Serial.println(frequency);//printing RED color frequency

                Serial.print("  ");


               

               //lcd.print("G=");// printing name
               Serial.print("G=");

                digitalWrite(12,HIGH);

                digitalWrite(13,HIGH);// setting for GREEN color sensor

                frequency = pulseIn(OutPut, LOW);// reading frequency

                //lcd.print(frequency);// printing GREEN color frequency

                //lcd.print("    ");

                //lcd.setCursor(0, 0);

                delay(500);
                Serial.println(frequency);//printing RED color frequency

                Serial.print("  ");
        

}              

