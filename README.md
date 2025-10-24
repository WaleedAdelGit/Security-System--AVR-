# Secured Door Access System (ATmega32)

A security system built using **ATmega32**, where users must enter a **username and password** to unlock a **motor-controlled door**.  
The system allows **three login attempts** before it locks. After successful login, the user can control **LEDs**, check **temperature**, and manage **cameras**.  
It also supports **erase** and **return** functions while typing.

##  Features
- Username & password authentication (3 trials then lock)
- Door motor control on successful login
- LED, temperature, and camera control options
- Erase and return keys for input correction
- Lockout for unauthorized access

##  Hardware Used
- ATmega32 microcontroller  
- LCD (16x2)  
- Keypad  
- DC motor + driver (for door)  
- Temperature sensor (e.g., LM35)  
- LEDs and camera module  

##  How It Works
1. Enter username and password using the keypad.  
2. If valid → door motor opens and menu appears.  
3. Choose commands: control LEDs, get temperature, or operate camera.  
4. 3 failed attempts → system locks.

## 🔹 Author
**Waleed** – Embedded Systems Engineer
