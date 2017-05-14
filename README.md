# arduino_esp8266

## 硬件：
  ##### arduino uno r3 + esp8266_01
  物理线路连接
<table>
        <tr>
            <th>Arduino</th>
            <th>v3.3</th>
            <th>v3.3</th>
            <th>D10</th>
            <th>D11</th>
            <th>GND</th>
        </tr>
        <tr>
            <th>esp8266_01</th>
            <th>v3.3</th>
            <th>CH_PD</th>
            <th>TXD</th>
            <th>RXD</th>
            <th>GND</th>
        </tr>        
    </table>
      


## 软件
由于是用的软串口， 传送会丢数据， 把SoftwareSerial.h Rx BUF 加大
设置esp8266的波特率为 9600

虽然速度有点慢，但是不影响 功能的使用

后面在写手机app控制， 并搭建java服务器 实现真正的远程控制。
