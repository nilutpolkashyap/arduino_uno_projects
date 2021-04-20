#include <RHReliableDatagram.h>
#include <RH_NRF24.h>
 
#include <SPI.h>
 
#define CLIENT_ADDRESS 1   
#define SERVER_ADDRESS 2
 
RH_NRF24 RadioDriver;
 
RHReliableDatagram RadioManager(RadioDriver, SERVER_ADDRESS);
 
uint8_t ReturnMessage[] = "JoyStick Data Received"; 
 
uint8_t buf[RH_NRF24_MAX_MESSAGE_LEN];
 
void setup()
{

  Serial.begin(9600);
  
  if (!RadioManager.init())
    Serial.println("init failed");
} 
 
void loop()
{
  if (RadioManager.available())
  {

    uint8_t len = sizeof(buf);
    uint8_t from;
    if (RadioManager.recvfromAck(buf, &len, &from))

    {
      Serial.print("got request from : 0x");
      Serial.print(from, HEX);
      Serial.print(": X = ");
      Serial.print(buf[0]);
      Serial.print(" Y = ");
      Serial.print(buf[1]);
      Serial.print(" Z = ");
      Serial.println(buf[2]);
 
      if (!RadioManager.sendtoWait(ReturnMessage, sizeof(ReturnMessage), from))
        Serial.println("sendtoWait failed");
    }
  }              
}
