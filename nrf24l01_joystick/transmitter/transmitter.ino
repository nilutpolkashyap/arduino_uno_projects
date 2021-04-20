#include <RHReliableDatagram.h>
#include <RH_NRF24.h>


#include <SPI.h>


#define JoyStick_X_PIN     A0 
#define JoyStick_Y_PIN     A1

#define CLIENT_ADDRESS 1   
#define SERVER_ADDRESS 2

RH_NRF24 RadioDriver;

RHReliableDatagram RadioManager(RadioDriver, CLIENT_ADDRESS);

uint8_t joystick[3]; 

uint8_t buf[RH_NRF24_MAX_MESSAGE_LEN];

void setup()
{
  Serial.begin(9600);

  if (!RadioManager.init())
    Serial.println("init failed");
}

void loop()
{
  Serial.println("Reading joystick values ");

  joystick[0] = map(analogRead(JoyStick_X_PIN), 0, 1023, 0, 255);
  joystick[1] = map(analogRead(JoyStick_Y_PIN), 0, 1023, 0, 255);
  joystick[2] = 100;

  Serial.println("-----------");
  Serial.print("x:");
  Serial.println(joystick[0]);
  Serial.print("y:");
  Serial.println(joystick[1]);

  Serial.println("Sending Joystick data to nrf24_reliable_datagram_server");
  
  if (RadioManager.sendtoWait(joystick, sizeof(joystick), SERVER_ADDRESS))
  {
    uint8_t len = sizeof(buf);
    uint8_t from;
    if (RadioManager.recvfromAckTimeout(buf, &len, 2000, &from))
    {
      Serial.print("got reply from : 0x");
      Serial.print(from, HEX);
      Serial.print(": ");
      Serial.println((char*)buf);
    }
    else
    {
      Serial.println("No reply, is nrf24_reliable_datagram_server running?");
    }
  }
  else
    Serial.println("sendtoWait failed");

  delay(100);  
}
