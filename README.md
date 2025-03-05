# 🚦 STM32 Traffic Light Control System 🌈

Welcome to the **STM32 Traffic Light Control System Project**! 🛠️ In this project, we’re building a fully-featured traffic light simulation for a crossroad, complete with customizable timing and interactive controls! Let’s get started! 💡

## 🌐 Specifications
- **💡 LEDs:** 12 total — 4 Red 🔴, 4 Amber 🟠, 4 Green 🟢
- **🖥️ 7-Segment Displays:** 4 total — 2 per road for time display ⏳
- **🎛️ Buttons:**
  - Mode Selection 🎉
  - Time Adjustment ⏱️
  - Value Confirmation ✅
- **🔄 Modes:**
  1. **Normal Mode:** Traffic lights operate automatically 🚗
  2. **Modify Red LED Time:** Adjust red light duration 🔴
  3. **Modify Amber LED Time:** Adjust amber light duration 🟠
  4. **Modify Green LED Time:** Adjust green light duration 🟢

---

## 📝 Exercises Breakdown

### 🧠 Exercise 1: Sketch an FSM
**🎯 Objective:** Design a **Finite State Machine (FSM)** to map out system behavior.

### 🔧 Exercise 2: Proteus Schematic
**🎯 Objective:** Draw the full **Proteus schematic** for the traffic light system.

### 🛠️ Exercise 3: Create STM32 Project
**🎯 Objective:**
- Set up an STM32 project in **CubeIDE**.
- Map pins according to the **Proteus schematic**.
- Configure a **10ms timer interrupt** ⏱️.

### ⚙️ Exercise 4: Modify Timer Parameters
**🎯 Objective:** Fine-tune the timer to allow flexible **interrupt duration (1ms - 100ms)** without affecting overall system behavior.

### 🎉 Exercise 5: Button Debouncing
**🎯 Objective:**
- Add **input reading** and **output display** modules.
- Implement **button debouncing**.
- Ensure **mode increases** on the first button press.

### 🖥️ Exercise 6: Displaying Modes
**🎯 Objective:**
- Show the current **mode on 7-segment displays**.
- Control **LED blinking behavior** based on the selected mode.

### 🔴 Exercise 7: Modify Red LED Duration
**🎯 Objective:**
- Use the second button to **increase red LED time**.
- Use the third button to **confirm the red LED duration**.

### 🟠 Exercise 8: Modify Amber LED Duration
**🎯 Objective:**
- Use the second button to **increase amber LED time**.
- Use the third button to **confirm the amber LED duration**.

### 🟢 Exercise 9: Modify Green LED Duration
**🎯 Objective:**
- Use the second button to **increase green LED time**.
- Use the third button to **confirm the green LED duration**.

### 🚀 Exercise 10: Final Integration
**🎯 Objective:**
- Combine all previous exercises into a **complete traffic light system**.
- Create a **video demo** showing all features.
- Submit the **final report and code**. 📝💻

---

🛠️ **How to Use:**
1. **📥 Clone this repository.**
2. **🖥️ Open the Proteus simulation files.**
3. **⚡ Flash the STM32 code onto your board.**
4. **🎉 Enjoy controlling and testing the traffic light system!**

👥 **Contributors:**
- Your Name Beckversync

📝 **License:**
HCMUT
