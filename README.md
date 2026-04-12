# Pixelisator
Pixelisator is a homemade handheld game console based on ESP32 and TFT LCD.

## PROJECT STATUS

12.04.2026 UPDATE

(a) State Machine  
&nbsp;&nbsp;&nbsp;&nbsp;• Scene-based architecture is implemented and working  
&nbsp;&nbsp;&nbsp;&nbsp;• SceneManager is decoupled from specific scene implementations  
&nbsp;&nbsp;&nbsp;&nbsp;• No dynamic allocation (new) - all scenes are statically allocated  
&nbsp;&nbsp;&nbsp;&nbsp;• Scene transitions are handled via pointers  
&nbsp;&nbsp;&nbsp;&nbsp;• Scenes do not directily reference each other - that's SceneManager job  
&nbsp;&nbsp;&nbsp;&nbsp;• Scenes do not access hardware directly  
(b) Input System  
&nbsp;&nbsp;&nbsp;&nbsp;• Input handler implemented and working  
&nbsp;&nbsp;&nbsp;&nbsp;• Hardware fully decoupled from scene logic via Context  
&nbsp;&nbsp;&nbsp;&nbsp;• Stable, non-blocking debouncing implemented  
&nbsp;&nbsp;&nbsp;&nbsp;• Event system implemented and working  
&nbsp;&nbsp;&nbsp;&nbsp;• 3 button states introduced as events: pressed, held, released  
&nbsp;&nbsp;&nbsp;&nbsp;• Event system with queue  
(c) Context  
&nbsp;&nbsp;&nbsp;&nbsp;• Implemented Context which is the structure for sharing objects among scenes  
&nbsp;&nbsp;&nbsp;&nbsp;• Context eliminates global dependencies (no extern in code)  
&nbsp;&nbsp;&nbsp;&nbsp;• Context separates logic and hardware  
(d) Renderer  
&nbsp;&nbsp;&nbsp;&nbsp;• Basic rendering layer (I'm still working on it)  
