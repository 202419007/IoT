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



## ZigBee
