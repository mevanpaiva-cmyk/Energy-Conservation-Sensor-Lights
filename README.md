# Energy Conservation Using Sensor Lights

An ESP32-based smart lighting system that automatically turns an LED ON when motion/presence is detected nearby and OFF when the area is empty — helping reduce unnecessary electricity usage.

##  Overview

Traditional lights are often left on even when no one is around, wasting electricity. This project uses an **ultrasonic sensor** to continuously measure distance and detect nearby presence, automatically controlling an LED accordingly. It's designed for spaces like **hallways, washrooms, offices, and parking areas**, where occupancy is short and intermittent.

##  How It Works

1. The ultrasonic sensor sends a trigger pulse and measures the time for the echo to return, calculating distance in real time.
2. The distance reading is continuously printed to the Serial Monitor for debugging.
3. After an initial warm-up period (first few loop cycles), the system begins checking distance:
   - **If distance ≤ 14 cm** → object/person detected nearby → LED turns **ON** and stays on for 12 seconds.
   - **If distance > 14 cm** → no one nearby → LED turns **OFF**.
4. This loop runs continuously, enabling real-time automated lighting control.

   
##  Components Used

| Component | Purpose |
|---|---|
| ESP32 (NodeMCU 1.0) | Microcontroller |
| Ultrasonic Sensor (HC-SR04) | Distance/presence detection |
| LED Lights (2x 12V) | Output lighting |
| Voltage Booster | Power regulation for LEDs |
| Transistor | Switching control for LED circuit |
| Breadboard | Circuit prototyping |

##  Tech Stack

- **Language:** C/C++ (Arduino variant)
- **IDE:** Arduino IDE
- **Board:** NodeMCU 1.0 (ESP-12E Module)

##  Pin Configuration

| Pin | GPIO | Function |
|---|---|---|
| D5 | GPIO14 | Trigger (Ultrasonic) |
| D6 | GPIO12 | Echo (Ultrasonic) |
| D1 | GPIO5  | LED Output |

##  How to Run

1. Open `Sensor_lights.ino` in Arduino IDE
2. Install ESP32 board support via **Board Manager** (if not already installed)
3. Select board: **NodeMCU 1.0 (ESP-12E Module)**
4. Connect the ESP32 via USB and select the correct COM port
5. Upload the sketch
6. Open **Serial Monitor** (baud rate: `115200`) to view live distance readings and LED status

##  Code Structure

- `setup()` — Initializes serial communication and configures sensor/LED pins
- `loop()` — Continuously reads distance and controls the LED based on proximity threshold
- `Read_Ultrasonic()` — Sends trigger pulse, measures echo duration, and returns calculated distance in cm

##  Impact

This project demonstrates a low-cost, sensor-driven IoT solution for automating lighting based on occupancy — reducing unnecessary power consumption and extending bulb lifespan in real-world settings.

##  Future Improvements

- Replace fixed 12-second ON delay with a dynamic timeout based on continued motion
- Add adjustable detection threshold via potentiometer
- Integrate with a mobile app or dashboard for remote monitoring
- Add data logging to track energy savings over time
