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
由于是用的软串口， 通讯会丢数据， 修改SoftwareSerial.h文件，把 Rx BUF定义加大
并设置esp8266的波特率为 9600

虽然速度有点慢，但是不影响 功能的使用

已完成手机app远程控制arduino开关灯逻辑
app 源代码： https://github.com/laibinluo/Arduino_Esp8266_android
#### 操作方式： 
手机app 安装apk，手机连接 esp8662 WIFI
点击连接， 即可发送灯亮，灯灭控制


后面在写手机app控制， 并搭建java服务器 实现真正的远程控制。
