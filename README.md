# 42_so_long

My still unfinished *so_long* project for **42 Nice**, last updated on March 7th 2023, at 17:53.

## Presentation

I'm doing this project for **42 Nice**, just after finishing *pipex* with bonuses.

I've loved video games since I was 3 and my mom did the unthinkable and bought me a gray *Nintendo DS* with *New Super Mario Bros.*. It was all downhill from there...  
Since then, I've owned every Nintendo console, a PC, a PSP and a PS4. You can see the extent of my addiction on [my HLTB page].

[my HLTB page]: https://howlongtobeat.com/user/SCOUNDREL

Needless to say, I've been eyeing this project for a while now, and I'm finally doing it!

I already have a good idea of what I'll be doing, I want to make a *Yoshi's Island* (SNES) inspired game. Well, only for the bonuses.  
I'll first make the mandatory part to become familiar with the **MLX**, and then I'll move on to the serious stuff.  
Wish me luck as I embark on this journey!

### Advice

Maps shouldn't be any larger than ~60 (width) by ~30 (height) for playability's sake.  
  
The game will start lagging if you have ~150+ coins (only tested on the 42 Nice computers).  
So if you have 150 or more coins on screen (less with bonuses), they won't be animated for performance's sake.  
You can modify this threshold in `srcs/game.h` with the `MAXCOINS` macro.

## Notes

### To-do list

Finish implementing throwing in `throw()` in `projectile_bonus.c`.

- [x] MAKE WALL LINKING TILESET
- [x] IMPLEMENT WALL LINKING
- [x] FIX MOVE COUNTER REFRESH
- [x] PRINT CURRENT NUMBER OF COINS ON SCREEN
- [x] TURN OFF COIN ANIMATION WHEN COIN COUNT IS OVER A THRESHOLD
- [x] ADD ENDING (BLACK SCREEN WITH RAINBOW CONGRATULATIONS)
- [x] ADD EXITING MESSAGE
- [x] ADD RAINBOW ANIMATION SPEED
- [x] CLEAN UP WALL LINKING CODE (NORM)
- [x] REMOVE MACROS FOR SHORTENED NAMES
- [x] CHECK NORM
- [x] START BONUSES
- [x] CHANGE MOVEMENT CONTROLS TO `WASD` KEYS
- [x] MAKE CURSOR CROSSHAIR TEXTURE
- [x] CLEANLY DISPLAY CUSTOM CROSSHAIR AT CURSOR POSITION
- [ ] FINISH `throw()` FUNCTION (in projectile_bonus.c) (inverse square root from Quake 3 maybe???)
- [ ] IMPLEMENT THROWING PROJECTILES ACCORDING TO MOUSE POSITION RELATIVE TO PLAYER
- [ ] MAKE PROJECTILE TEXTURE
- [ ] MAKE PROJECTILE BOUNCING
- [ ] MAKE COINS COLLECTABLE WITH PROJECTILES
- [ ] MAKE ENEMIES TEXTURES
- [ ] MAKE ENEMIES MOVEMENT
- [ ] MAKE THE PLAYER DIE ON CONTACT WITH AN ENEMY
- [ ] MAKE ENEMIES KILLABLE WITH PROJECTILES
- [ ] MAKE BONUS TEXTURES
- [ ] MAKE TEXTURE PACK SYSTEM WITH BASIC REUSABLE NAMES
