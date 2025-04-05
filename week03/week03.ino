// 미세먼지 센서 연결 GND -> GND, OUT -> A5, LED -> 10, VCC -> 5V
// "http://localhost:8086에서 앱 GUI 실행 dust 만들기 token 주소 저장
// 데이터 조회 : new dashboard 생성

// Arduino 실행 코드
int Vo = A0;
int V_led = 12;

float Vo_value = 0;
float Voltage = 0;
float dustDensity = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(V_led, OUTPUT);
  pinMode(Vo, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(V_led, LOW);
  delayMicroseconds(280);
  Vo_value = analogRead(Vo);
  delayMicroseconds(40);
  digitalWrite(V_led, HIGH);
  delayMicroseconds(9680);

  Voltage = Vo_value * 5.0 / 1023.0;
  dustDensity = (Voltage - 0.5) / 0.005;

  Serial.print("dust=");
  Serial.println(dustDensity);

  delay(1000);
}

// python 실행 코드
import serial
from influxdb_client import InfluxDBClient
import time

serial_port = 'COM15' //COM 확인
baud_rate = 9600
timeout = 2

# InfluxDB v2 설정
influxdb_url = "http://localhost:8086"
influxdb_token = "wrlQ06uKKNfPpxbklp-R3rJhMETDZrCWJGMlucqUT_yBcXT8vaC-1GdrjdpQFPD4NTKoMPbpW3wVj38pvJ2V6w==" // token 주소 저장한거 가져오기
influxdb_org = "test"
influxdb_bucket = "dust"


// InfluxDB 클라이언트 초기화
client = InfluxDBClient(url=influxdb_url, token=influxdb_token, org=influxdb_org)
write_api = client.write_api()

try:
    ser = serial.Serial(serial_port, baud_rate, timeout = timeout)
    print(f"Connected to {serial_port} at {baud_rate} baud")
except:
    print("Failed to connect to serial port") // 이 문장이 계속 나올 경우 이부분 삭제해서 오류 이유 보기
    exit()

try:
    while True:
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').strip()

            if "=" in line:
                key, value = line.split("=")
                try:
                    value = float(value)
                    data=f"sensor_data,device=arduino {key}={value}"
                    write_api.write(bucket=influxdb_bucket, record=data)
                    print(f"Data written to influxDB: {key}={value}")
                except ValueError:
                    print("Invalid data format")
        time.sleep(1)

except KeyboardInterrupt:
    print("프로그램이 종료되었습니다.")

finally:
    ser.close()
