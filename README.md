# 42_so_long

My still unfinished *so_long* project for **42 Nice**, last updated on March 9th 2023, at 19:05.

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

Maps shouldn't be any larger than ~60 (width) by ~30 (height) for playability's sake (if the game uses 32x32 textures).

You can change texture size by using your own textures and   
  
The game will start lagging if you have ~150+ coins (only tested on the 42 Nice computers).  
So if you have 150 or more coins on screen (less with bonuses), they won't be animated for performance's sake.  
You can modify this threshold in `srcs/game.h` with the `MAXCOINS` macro.

## Notes

### To-do list

Implement projectile interactions in `update_projectile()` in `projectile_bonus.c`.  
Test `count2.ber` with projectile collecting coins and player not moving (watch counters for bugs).

- [x] CHECK NORM
- [x] START BONUSES
- [x] CHANGE MOVEMENT CONTROLS TO `WASD` KEYS
- [x] MAKE CURSOR CROSSHAIR TEXTURE
- [x] CLEANLY DISPLAY CUSTOM CROSSHAIR AT CURSOR POSITION
- [x] FINISH `throw()` FUNCTION (in projectile_bonus.c) (inverse square root from Quake 3 maybe???)
- [x] IMPLEMENT THROWING PROJECTILES ACCORDING TO MOUSE POSITION RELATIVE TO PLAYER
- [x] MAKE PROJECTILE TEXTURE
- [x] FIX COIN AND MOVE COUNTERS
- [ ] MAKE PROJECTILE BOUNCING (MAKE IT OPTIONAL???)
- [ ] MAKE COINS COLLECTABLE WITH PROJECTILES
- [ ] MAKE ENEMIES TEXTURES
- [ ] MAKE ENEMIES MOVEMENT
- [ ] MAKE THE PLAYER DIE ON CONTACT WITH AN ENEMY
- [ ] MAKE ENEMIES KILLABLE WITH PROJECTILES
- [ ] MAKE BONUS TEXTURES
- [ ] TURN CANVAS TEXTURE INTO A SPRITESHEET
- [ ] USE CANVAS SPRITESHEET FOR ENDING
- [ ] MAKE TEXTURE PACK SYSTEM WITH BASIC REUSABLE NAMES
- [ ] ADD MUSIC AND SOUND EFFECTS
