🔌 Circuit Connections
🔹 MQ-2 Sensor

VCC → Arduino 5V

GND → Arduino GND

A0 → Arduino A0

🔹 Buzzer

Positive → Pin 8 (Arduino)

Negative → GND

🔹 Servo Motor

Signal → Pin 9 (Arduino)

VCC → 5V

GND → GND

🔹 Fan (Controlled via IRF740 MOSFET)

Positive → 5V (Arduino)

Negative → Drain (MOSFET)

🔹 MOSFET (IRF740)

Gate → Arduino Pin 10 (via 10Ω resistor)

Drain → Fan negative terminal

Source → Arduino GND

🔹 Flyback Diode (Optional, across fan terminals)

Cathode (marked side) → Fan Positive

Anode → Fan Negative

⚙️ Working Steps

Gas Detection

MQ-2 sensor monitors environment continuously.

Analog signal output changes with gas concentration.

If Gas Detected (Above Threshold):

🔔 Buzzer turns ON to alert users.

⚙️ Servo motor rotates (closes valve/regulator).

💨 Fan switches ON to disperse gas.

If No Gas Detected:

Buzzer OFF.

Servo motor remains in initial position.

Fan remains OFF.
