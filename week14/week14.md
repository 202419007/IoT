# 사물인터넷 14주차
## Wi-Fi
* Wi-Fi 구성
  - IEEE 802.11 Working Group에서 표준화 작업
  - AP(Access Point)와 station (STA)으로 구성
    * AP: 유무선 공유기
    * STA: 노트북, 스마트폰 등

* Wi-Fi Service Set
  - BSS(Basic Service Set)
    * AP가 없으면 ad hoc 모드
    * AP가 있으면 infrastructure 모드
  - ESS(Extended Service Set)
    * 두 개 이상의 BSS들이 모여서 구성

* MAC 방식
  - PCF(Point coordination function)
    * Option
    * 중앙집중식 Polling 방식 사용
  - DCF(Distributed coordination function)
    * CSMA/CA 사용. Station에서 사용
  * CSMA-CA
    - CS(Carrier Sense) : 네트워크가 현재 사용 중인지 알아냄
    - MA(Multiple Access) : 네트워크가 비어있으면 누구든 사용 가능
    - CA(Collision Avoidance) : 충돌 회피 (충돌 감지X)
  * CSMA-CD(Collision Detection)
    - 이더넷 (Ethernet)에 쓰이는 채널 접근 방식
    - 송신 중 충돌이 감지(detection)되면, 전송을 중지하고 랜덤한 시간 동안 기다리고 (백오프), 다시 전송 시도
    - 유선에서는 구현이 쉬우나, 무선에서는 어려움
      * Why? : 유선에서는 송신 중에, 수신기를 켜 둘 수 있으나, 무선에서는 송신 중, 수신기를 켜두기 어렵다.
  * CSMA-CA의 CSMA-CD와 비교한 장단점
    - <ins>장점: 저 가격으로 구현</ins>
    - <ins>단점: 데이터 전송이 많이 지연될 수 있음</ins>
      * (전송 빈도가 높아지면, 충돌 방지 신호의 전송 속도가 느려짐)


## ZigBee
* 스택 - 프로토골, 소프트웨어 관한 집합체라 볼 수 있음
* 지그비 스택 - 지그비에서 정의한 프로토콜들의 구현
* 물리(PHY) 계층 - DSSS(Direct Sequence Spread Spectrum)
* 매체 접근제어(MAC) 계층 - 다수의 기기들이 전송할 때 서로 충돌을 회피
* 네트워크(NWK) 계층 - 다수의 노드들이 네트워크를 형성
* 응용지원(APS) 계층 - 응용(Application)이 네트워크를 사용할 수 있도록 지원
* 응용(APL, APpLication) - 응용 프로그램 동작





