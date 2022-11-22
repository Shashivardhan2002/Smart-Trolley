#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <Wire.h>
#include <string.h>
LiquidCrystal_I2C lcd ( 0x27 , 16 , 2 ) ;
int count = 0 ;
char input [ 12 ] ;
double total = 0 ;
int buttonState = 0;  
int count_prod = 0 ;
const int buttonPin = 2;  
void setup ( )
 {
Serial.begin ( 9600 ) ;
//Pin direction
pinMode ( 4 , OUTPUT ) ;// RED LED
pinMode ( 5 , OUTPUT ) ;// BUZZER
pinMode ( 6 , OUTPUT ) ;// GREEN LED
// Initialization
Serial.begin ( 9600 ) ;
// lcd.begin ( ) ;
lcd.init( );
lcd.backlight ( ) ;
lcd.setCursor ( 0 , 0 ) ;
lcd.print ( " AUTOMATIC BILL " ) ;
delay ( 2000 ) ;
lcd.setCursor ( 0 , 1 ) ;
lcd.print ( " SHOPPING CART");
delay ( 2000 ) ;
lcd.clear ( ) ;
lcd.setCursor ( 0 , 0 ) ;
lcd.print ( "WELCOME TO");
lcd.setCursor ( 0 , 1 ) ;
lcd.print ( " BIG BAZAAR " ) ;
pinMode(buttonPin, INPUT);
} 
void loop ( )
{
  
if ( Serial.available ( ) )
 {
  count = 0 ;
 while ( Serial.available ( ) && count < 12 )
 {
 input [ count ] = Serial.read ( ) ;
 count ++ ;
 delay ( 5 ) ;
 }
 
 if (input[0] == '2' && input[1] == '7' && input[2] == '0' && input[3] == '0'&&
    input[4] == '5' && input[5]=='8' && input[6] == 'F' && input[7] == 'E' &&
    input[8] == '2' && input[9]=='E' && input[10] == 'A' && input[11] == 'F' )
  {
    
   lcd.clear();
   lcd.setCursor ( 0 , 0 ) ;
   lcd.print ( " Biscuit Added ");
   lcd.setCursor ( 0 , 1 ) ;
   lcd.print ("Price:4.00Rs");
   digitalWrite ( 4 , HIGH ) ;
   digitalWrite ( 5 , HIGH ) ;
   delay ( 1000 ) ;
   total=total+4.00 ;
   count_prod++ ;
   digitalWrite ( 4 , LOW ) ;
   digitalWrite ( 5 , LOW ) ;
  
  }
  if (input[0] == '2' && input[1] == '7' && input[2] == '0' && input[3] == '0'&&
    input[4] == '5' && input[5]=='9' && input[6] == '2' && input[7] == '0' &&
    input[8] == '4' && input[9]=='1' && input[10] == 'A' && input[11] == '6' )
  {
       if (buttonState == HIGH)
 {
   lcd.clear(); 
   lcd.setCursor ( 0 , 0 ) ;
   lcd.print ( " Biscuit del ");
   lcd.setCursor ( 0 , 1 ) ;
   lcd.print ("Price:2.00Rs");
   digitalWrite ( 4 , HIGH ) ;
   digitalWrite ( 5 , HIGH ) ;
   delay ( 1000 ) ;
   total=total-4.00 ;
   count_prod++;
   digitalWrite ( 4 , LOW ) ;
   digitalWrite ( 5 , LOW ) ;
  }
  }  
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
 
    if (input[0] == '2' && input[1] == '7' && input[2] == '0' && input[3] == '0'&&
    input[4]== '5' && input[5]=='9' && input[6] == '4' && input[7] == 'A' &&
    input[8] == '0' && input[9]=='2' && input[10] == '3' && input[11] == '6' )
    {
        if (buttonState == LOW)
  {
        lcd.setCursor ( 0 , 0 ) ;
        lcd.print ( " Choclate del");
        lcd.setCursor ( 0 , 1 ) ;
        lcd.print ("Price:4.00Rs");
        digitalWrite ( 4 , HIGH ) ;
        digitalWrite ( 5 , HIGH ) ;
        delay ( 1000 ) ;
        total=total-2.00 ;
        count_prod++ ;
        digitalWrite ( 4 , LOW ) ;
       digitalWrite ( 5 , LOW ) ;
    }
    }

    if (input[0] == '2' && input[1] == '7' && input[2] == '0' && input[3] == '0'&&
    input[4] == '5' && input[5]=='9' && input[6] == '2' && input[7] == '0' &&
    input[8] == '4' && input[9]=='B' && input[10] == '1' && input[11] == '5' )
  {
     if (buttonState == LOW)
     {
   lcd.setCursor ( 0 , 0 ) ;
   lcd.print ( " Chocolate added ");
   lcd.setCursor ( 0 , 1 ) ;
   lcd.print ("Price:2.00Rs");
   digitalWrite ( 4 , HIGH ) ;
   digitalWrite ( 5 , HIGH ) ;
   delay ( 1000 ) ;
   total=total+2.00 ;
   count_prod++;
   digitalWrite ( 4 , LOW ) ;
   digitalWrite ( 5 , LOW ) ;
  }
  }
 
     if (input[0] == '2' && input[1] == '7' && input[2] == '0' && input[3] == '0'&&
    input[4] == 'F' && input[5]=='2' && input[6] == '8' && input[7] == '1' &&
    input[8] == '8' && input[9]=='7' && input[10] == 'D' && input[11] == '3' )
  {
     if (buttonState == LOW)
     {
   lcd.setCursor ( 0 , 0 ) ;
   lcd.print ( " Chips added ");
   lcd.setCursor ( 0 , 1 ) ;
   lcd.print ("Price:10.00Rs");
   digitalWrite ( 4 , HIGH ) ;
   digitalWrite ( 5 , HIGH ) ;
   delay ( 1000 ) ;
   total=total+10.00 ;
   count_prod++;
   digitalWrite ( 4 , LOW ) ;
   digitalWrite ( 5 , LOW ) ;
  }
  }

   if (input[0] == '2' && input[1] == '7' && input[2] == '0' && input[3] == '0'&&
    input[4] == 'F' && input[5]=='2' && input[6] == '8' && input[7] == '6' &&
    input[8] == '1' && input[9]=='8' && input[10] == '4' && input[11] == 'B' )
  {
     if (buttonState == LOW)
     {
   lcd.setCursor ( 0 , 0 ) ;
   lcd.print ( " Chips del ");
   lcd.setCursor ( 0 , 1 ) ;
   lcd.print ("Price:10.00Rs");
   digitalWrite ( 4 , HIGH ) ;
   digitalWrite ( 5 , HIGH ) ;
   delay ( 1000 ) ;
   total=total-10.00 ;
   count_prod++;
   digitalWrite ( 4 , LOW ) ;
   digitalWrite ( 5 , LOW ) ;
  }
  }
}
  else
   {
    // turn LED off:
   // digitalWrite(ledPin, LOW);
  if(input[0] == '2' && input[1] == '7' && input[2] == '0' && input[3] == '0'&&
    input[4] == 'F' && input [5]=='2' && input[6] == '6' && input[7] == 'F' &&
    input[8] == '6' && input[9]=='9' && input[10] == 'D' && input[11] == '3' )
    {
  

       lcd.clear(); 
       lcd.print ( " total price is" ) ;
       digitalWrite ( 6 , LOW ) ;
       digitalWrite ( 5 , LOW ) ;
       lcd.setCursor ( 0 , 3 ) ;
       lcd.print (total) ;
       delay (5000);
       lcd.clear( );
       lcd.setCursor ( 0 , 0 ) ;
       lcd.print ( " THANKS FOR " ) ;
       lcd.setCursor ( 0 , 1 );
       lcd.print ( " VISITING " ) ;
       
    }
   }
    }
