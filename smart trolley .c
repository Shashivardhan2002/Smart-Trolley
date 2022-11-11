#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <string.h>
LiquidCrystal_I2C lcd ( 0x27 , 16 , 2 ) ;
int count = 0 ;
char input [ 12 ] ;
double total = 0 ;
int count_prod = 0 ;
void setup ( ) {
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
lcd.print ( " HITAM SHOPPING " ) ;
} 
void loop ( ) {
if ( Serial.available ( ) )
{
count = 0 ;
while ( Serial.available ( ) && count < 12 )
{
input [ count ] = Serial.read ( ) ;
count ++ ;
delay ( 5 ) ;
}
    if(input[12]="270058FE2EAF")
{
lcd.setCursor ( 0 , 0 ) ;
lcd.print ( " Biscuit Added ");
lcd.setCursor ( 0 , 1 ) ;
lcd.print ( " Price: 4(Rs) ");
digitalWrite ( 4 , HIGH ) ;
digitalWrite ( 5 , HIGH ) ;
delay ( 1000 ) ;
total=total + 4.00 ;
count_prod ++ ;
digitalWrite ( 4 , LOW ) ;
digitalWrite ( 5 , LOW ) ;
}
    if(input[12]="")
{
lcd.setCursor ( 0 , 0 ) ;
lcd.print ( " Icecream added ");
lcd.setCursor ( 0 , 1 ) ;
lcd.print ( " Price:50(Rs) ");
digitalWrite ( 4 , HIGH ) ;
digitalWrite ( 5 , HIGH ) ;
delay ( 1000 ) ;
total=total + 50.00 ;
count_prod ++ ;
digitalWrite ( 4 , LOW ) ;
digitalWrite ( 5 , LOW ) ;
}
    if(input[12]="")
{
lcd.setCursor ( 0 , 0 ) ;
lcd.print ( " ");
lcd.setCursor ( 0 , 1 ) ;
//lcd.print ( " Price: (Rs) ");
digitalWrite ( 4 , HIGH ) ;
digitalWrite ( 5 , HIGH ) ;
delay ( 1000 ) ;
total=total + 20.00 ;
count_prod ++ ;
digitalWrite ( 4 , LOW ) ;
digitalWrite ( 5 , LOW ) ;
}
    if(input[12]="270059204B15")
{
lcd.setCursor ( 0 , 0 ) ;
lcd.print ( " Chocolate Added ");
lcd.setCursor ( 0 , 1 ) ;
lcd.print ( " Price: 20(Rs) ");
digitalWrite ( 4 , HIGH ) ;
digitalWrite ( 5 , HIGH ) ;
delay ( 1000 ) ;
total=total + 20.00 ;
count_prod ++ ;
digitalWrite ( 4 , LOW ) ;
digitalWrite ( 5 , LOW ) ;
}

    if(input[12]="27005986B52D")
{
lcd.setCursor ( 0 , 0 ) ;
digitalWrite ( 6 , HIGH ) ;
digitalWrite ( 5 , HIGH ) ;
delay ( 1000 ) ;
lcd.print ( " Total Price : - ") ;
digitalWrite ( 6 , LOW ) ;
digitalWrite ( 5 , LOW ) ;
lcd.setCursor ( 0 , 1 ) ;
lcd.print (total) ;
delay ( 5000 ) ;
lcd.clear ( ) ;
lcd.setCursor ( 0 , 0 ) ;
lcd.print ( " THANKS FOR " ) ;
lcd.setCursor ( 0 , 1 );
lcd.print ( " VISITING " ) ;
}
}
}
