# 🏎 Racing Car Game – C & raylib Project

A simple yet engaging 2D racing game built using the C programming language and the [raylib](https://www.raylib.com/) graphics library. Designed as part of the *PSAP Course Project* at Vishwakarma Institute of Technology, this project introduces core concepts in game development, including graphics rendering, user input, collision detection, and score management.

## 🎮 Game Overview

Control a red car, avoid oncoming traffic (blue rectangles), and score as high as you can! As the game progresses, randomized obstacles challenge your reflexes while trees and striped roads enhance the visual experience.


## 🛠 Features

- ✅ Player movement using arrow keys
- 🔁 Countdown timer before game start
- 🎯 Score tracking with real-time display
- 💥 Collision detection and game-over state
- 🌳 Moving trees and road stripes for realism
- 🚧 Randomized obstacle generation
- 🎮 Continuous gameplay loop at 60 FPS

---

## 🧰 Technologies Used

- *Language:* C
- *Editor:* Notepad++
- *Graphics Library:* raylib
- *Standard Libraries:* stdlib.h, time.h
- *Tools:* GCC / Code::Blocks / VS Code / Notepad ++ for raylib

---

## 🗂 Project Structure


📁 RacingCarGame/

├── main.c
├── raylib.h
├── README.md           

---

🚀 Getting Started

🔧 Installation

1. Install raylib
   
raylib setup guide

On Ubuntu/Debian:
sudo apt install libraylib-dev



2. Clone the Repository

git clone https://github.com/your-username/RacingCarGame.git
cd RacingCarGame


3. Compile & Run

gcc main.c -o racing -lraylib -lm -lpthread -ldl -lrt -lX11
./racing


> Make sure raylib is linked properly, especially if you're on Windows. Refer to the official guide.




---

🖼 Screenshots

Game Start  
<img src="https://github.com/user-attachments/assets/b0d13a00-597e-47b4-a676-548b30826549" alt="Game Start" width="960" height="360" />

In-Game  
<img src="https://github.com/user-attachments/assets/ed4c90e9-7b90-4864-acf8-ae1fc2e8ee86" alt="In-Game" width="960" height="360" />

Game Over  
<img src="https://github.com/user-attachments/assets/13d77d26-fba6-468b-979e-f2d82e413ffa" alt="Game Over" width="960" height="360" />


👨‍💻 Contributors

Vedant Mehar
Anushka Mangade
Riya Mote
Naaz Tadavi

🧑‍🏫 Guide: Prof. Lokesh Khedekar
🎓 Department of Engineering Sciences and Humanities
🏫 Vishwakarma Institute of Technology, Pune


---

📌 Future Enhancements

1. Add sound effects and background music
2. Power-ups like speed boosts or shields
3. Difficulty levels (easy/medium/hard)
4. Global leaderboard with persistent scores



📄 License
This project is developed for academic purposes and open for educational contributions. You may fork and experiment with it for learning.

