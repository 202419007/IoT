int a1 = 2;
int a2 = 3;
int a3;

void setup() {
  Serial.begin(115200);
  Serial.println();

  //아래 a1, a2, a3는 인수(argument)임
  sum(a1,a2,a3);
  Serial.println(a3);
}

void loop() {
}

//아래 a,b,c는 매개 변수(parameter)임
void sum(int a, int b, int& c) {
  c = a + b;
}

// 실행 결과 : 5
