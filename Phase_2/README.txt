# PHASE 2
+----------------------------------------------------------+
|                 PHASE 2 - REMOTE CONTROL                 |
+----------------------------------------------------------+
|                  Overview Block Diagram                  |
+----------------------------------------------------------+
 Si4663F30        Si4663F30                MSP430G2553IN20
+----------+   +-------------+          +------------------+
|          <---+             |8-bit GPIO|                  |
| Reciever |RF | Transmitter <----------+ Data Auto-Sender |
|          +--->             <----------+                  |
+----------+   +----------^--+State_SEL +---+----^---------+
                          |                 |    |
                          +-----------------+    |
+---------------------------+  INT/DONE          |
|    Possible Ideas:        |           +--------+---------+
| 1. The computer only      |           |     Joystick     |
|    sends the image        |           |    (Via ADC10)   |
|    coordination data      |           |                  |
| 2. Computer processes     |           +------------------+
|    the data & sends       |           |     Computer     |
|    the preocessed data.   |           |    (Via SPI)     |
|                           |           |                  |
+---------------------------+           +------------------+
+----------------------------------------------------------+
|               Si4663 Interfacing Diagram                 |
+----------------------------------------------------------+
+--------+  +----------------------------------------------+
|        <==>SPI                                           |
| Si4663 |  |                            MSP430G2553       |
|        +-->INT                                           |
+--------+  +----------------------------------------------+
+----------------------------------------------------------+
## API
All of the API functions processed by MSP430 for Si4663 are
regarded to the official programming guide, which can be
downloaded in the current folder.
## Ideas
The basic ideas of this phase can be summarised into points:
1. Special modules for RF transcieving
2. A specialised module to send the sensed data to the RF module
## Components
1. [Si4663F30](https://www.aliexpress.com/item/32816312908.html "Link to buy Si4663F30, a more powerful RF module")
2. MSP430G2553IN20
3. Joystick
4. Computer
5. [USB-to-SPI interface] ... Not found one, try UART probably.
## Test
Still waiting for the delivery...