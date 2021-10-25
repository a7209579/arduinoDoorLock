# 單晶片系統實作期末專案-密碼鎖
## 摘要
此專案結合一個4x4鍵盤、一個 LCD 顯示器、一個伺服馬達和雨個LED燈而成。Arduino 微控板通電後，伺服馬達從0度逆時針轉向90度上鎖，LCD 顯示："Enter•Password:to: UnLock"請使用者輸入密
碼來解鎖，使用者必須輸入長度為四的數宇密碼，輸入時 LCD 會以星號提示使用者輸入多少個數字。
![image](https://github.com/a7209579/arduino-door-lock/blob/main/images/tinkercad.png)
## 使用設備
* Arduino Uno R3
* 4x4鍵盤
* 紅色LED, 綠色LED
* 伺服馬達
* LCD 16x2
## 系統流程
當使用者輸入密碼正確時，LCD 顯示“Door UnLock”表示解鎖，同時綠色 LED 燈發亮，伺服馬達角度會從90度的狀態順時針轉回 0度解鎖，綠色 LED 燈熄燈後，伺服馬達會重新上鎖。當使用者輸入密碼錯誤時，ICD 會顯示”Password: Incorrect表示密碼錯誤，紅色LED燈亮燈，伺服馬達維持上鎖狀態不運作，等到紅色LED燈熄燈後，LCD 重新顯示?Enter Password to UnLock” 請使用者重新輸入密碼。
![image](https://github.com/a7209579/arduino-door-lock/blob/main/images/flowchart.jpg)
