//이론
//I2C는 Low로만 움직일 수 있어서 풀업 저항으로 HIGH을 유지해 줘서 움직일 수 있다.


//실습
// Tinkercad에서 Arduino와 LCD 16 x 2 (I2C)을 이용해 유형과 주소를, 전선을 알맞게 설정한뒤에 밑에 코드로 실행한다.
// 아두이노 외부라이브러리를 추가한다.

#include <Wire.h>               // I2C 통신을 위한 기본 라이브러리
#include <LiquidCrystal_I2C.h>  // I2C LCD 라이브러리


LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  lcd.init();
  lcd.backlight();        // I2C LCD 초기화
  lcd.print("LCD init");  // 백라이트 켜기
  delay (2000);
  lcd.clear();
}

void loop()
{
  lcd.setCursor(0,0);
  lcd.print("Hello, World!");
  
  for (int position = 0; position < 16; position++) {
    lcd.scrollDisplayLeft();
    delay(150);
  }
}


// 미세먼지 데이터 LCD 표시
// 전선 미세먼지센서와 LCD를 브레드보드를 사용해 연결하기
#include <Wire.h>               // I2C 통신을 위한 기본 라이브러리
#include <LiquidCrystal_I2C.h>  // I2C LCD 라이브러리

LiquidCrystal_I2C lcd(0x27, 16, 2);

int Vo = A0;
int V_led = 7;

float Vo_value = 0;
float Voltage = 0;
float dustDensity = 0;

void setup()
{
  pinMode(V_led, OUTPUT);
  pinMode(Vo, INPUT);
  lcd.init();
  lcd.backlight();        // I2C LCD 초기화
  lcd.print("LCD init");  // 백라이트 켜기
  delay (2000);
  lcd.clear();
}

void loop()
{
  digitalWrite(V_led, LOW);
  delayMicroseconds(280);
  Vo_value = analogRead(Vo);
  delayMicroseconds(40);
  digitalWrite(V_led, HIGH);
  delayMicroseconds(9680);

  Voltage = Vo_value*5.0 / 1023.0;
  dustDensity = (Voltage - 0.5) / 0.005;
  lcd.setCursor(0,0);

  lcd.print(dustDensity);
  lcd.print("um");
  delay(1000);
  lcd.clear();
}


// 아두이노 1602 LCD I2C 주소 찾기
#include <Wire.h>               // I2C 통신을 위한 기본 라이브러리
#include <LiquidCrystal_I2C.h>  // I2C LCD 라이브러리

void setup()
{
  Serial.begin(9600); // 시리얼 모니터 시작 (속도: 9600 baud)
  wire.begin();
  Serial.println("I2C Scanner Running...");
}

void loop()
{
  Serial.println("Scanning...");

  for (byte address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    if (Wire.endTransmission() == 0) {
      Serial.print("I2C 장치 발견: 0x");
      Serial.println(address, HEX);
      delay(500);
    }
  }
  
  Serial.println("Scan Complete! Retrying in 5 seconds...\n");
  delay(5000);
}
