# Pixelisator
Pixelisator is a homemade handheld game console based on ESP32 and TFT LCD.

## PROJECT STATUS

12.04.2026 UPDATE

(a) State Machine
    • Scene-based architecture is implemented and working
    • SceneManager is decoupled from specific scene implementations
    • No dynamic allocation (new) - all scenes are statically allocated
    • Scene transitions are handled via pointers
    • Scenes do not directily reference each other - that's SceneManager job
    • Scenes do not access hardware directly
(b) Input System
    • Input handler implemented and working
    • Hardware fully decoupled from scene logic via Context
    • Stable, non-blocking debouncing implemented
    • Event system implemented and working
    • 3 button states introduced as events: pressed, held, released
    • Event system with queue
(c) Context
    • Implemented Context which is the structure for sharing objects among scenes
    • Context eliminates global dependencies (no extern in code)
    • Context separates logic and hardware
(d) Renderer
    • Basic rendering layer (I'm still working on it)
