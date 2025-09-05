🔥 Auto-Off Gas Leakage Detection System

An Arduino UNO and MQ-2 sensor–based safety system that automatically detects gas leakage and prevents hazards by shutting down the regulator and alerting users.

✨ Features:

🔔 Triggered Buzzer on gas detection

⚙️ Automatic Shut-off via Servo Motor

💨 Ventilation Fan Activation with MOSFET

🛡️ Enhanced Safety with Real-Time Monitoring

⚡ Working Principle

The Auto-Off Gas Leakage Detection System continuously monitors the environment using an MQ-2 gas sensor.

When combustible gases like LPG, methane, or butane are detected, the sensor sends signals to the Arduino.

The Arduino processes this data and performs safety actions:

🔔 Activates a buzzer to alert about gas leakage.

⚙️ Rotates a servo motor to simulate closing a gas valve.

💨 Turns on a 5V fan to ventilate the environment, controlled via an IRF740 MOSFET.

This ensures early detection, immediate alerts, and preventive measures to avoid fire hazards.

🧩 Components Used

Arduino Uno – Microcontroller to process sensor data and control devices.

MQ-2 Gas Sensor – Detects LPG, methane, and propane gases.

Pins: VCC, GND, A0 (analog output)

Buzzer – Provides an audible alarm.

Pins: Positive, Negative

Servo Motor – Simulates turning off the gas regulator.

Pins: Signal, VCC, GND

5V Fan – Provides ventilation when leakage is detected.

Controlled via MOSFET.

IRF740 MOSFET – Works as an electronic switch to control the fan.

Pins: Gate, Drain, Source

Resistor (10Ω) – Placed between Arduino pin and MOSFET Gate for protection.

Diode (1N4007, optional) – Flyback diode to prevent voltage spikes from the fan.

Breadboard & Jumper Wires – For easy prototyping and connections.

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
