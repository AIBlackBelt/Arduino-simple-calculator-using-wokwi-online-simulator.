 This is a simple work to get started with arduino programming. It's an online calculator that makes operation between operand, using a keypad (4*4) and an lcd1602. We used the wokwi online simulator to build it. 

keypad reference : https://docs.wokwi.com/parts/wokwi-lcd1602
lcd 1602 reference : https://docs.wokwi.com/parts/wokwi-lcd1602


you will need first to do the right plugs in correctly between the keypad and the arduino board first then the lcd and arduino.

Note in the code: the fifth row : indicates the plugs in between the lcd and arduino : LiquidCrystal lcd(12, 11, A0, A1, A2, A3);

D4, D5, D6, D7 (lcd pins) should be pluged in respectively to A0, A1, A2, A3 (arduino pins)
 
How to manipulate : 
 
 "A" -> "+"
 "B" -> "-"
 "C" -> "/"
 "D" -> "R" (reset button) this button should be pressed to reset the calculator and start a new operation
 
 "#" -> "=" (equal button) to be pressed after entering the first operand, operator and second operand.
 
 
flow : 
 
First some messages appears in the lcd screen "start","press an operand". wait till these messages disappear before start manipulating.
insert the first operand : 456 for instance, then the operator "-" par exempl, and finally the = sign to get the result, the final result will be displayed right afterward, you must click "D" to restart the calculator in order to keep manipulating and make further operations. the "reset !" message appears followed by "press an operdand", again wait till these messages disappear before conducting the next operation .
