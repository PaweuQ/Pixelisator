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
&nbsp;&nbsp;&nbsp;&nbsp;• Basic rendering layer added

(e) Map, Player, Maze
&nbsp;&nbsp;&nbsp;&nbsp;• Fixed LCD orientation. Now it's horizontal and [0,0] point is in the left up corner
&nbsp;&nbsp;&nbsp;&nbsp;• Maze stuctures are 2-dimension arrays drawn with double for loop
&nbsp;&nbsp;&nbsp;&nbsp;• Implemented basic cursor logic on the map smoothly controlled with UP, DOWN, LEFT, RIGHT buttons
&nbsp;&nbsp;&nbsp;&nbsp;• Implemented wall collision terms so player can move through aisles between walls 

## Test circuit at 19.04.2026
<p align="left">
  <a href="/software/learning/Learning_11_image.jpg" target="_blank">
    <img src="/software/learning/Learning_11_image.jpg" alt="" width="50%">
  </a>
</p>

