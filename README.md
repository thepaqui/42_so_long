# 42_so_long

My still unfinished *so_long* project for **42 Nice**, last updated on March 11th 2023, at 16:42.

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

Implement enemies!

- [x] IMPLEMENT THROWING PROJECTILES ACCORDING TO MOUSE POSITION RELATIVE TO PLAYER
- [x] MAKE PROJECTILE TEXTURE
- [x] FIX COIN AND MOVE COUNTERS
- [x] MAKE PROJECTILE BOUNCING (AND MADE IT OPTIONAL)
- [x] MAKE MAX BOUNCES BEFORE BREAKING
- [x] SECRET ;)
- [x] MAKE COINS COLLECTABLE WITH PROJECTILES
- [x] MAKE TEXTURE PACK SYSTEM WITH BASIC REUSABLE NAMES
- [ ] MAKE ENEMIES TEXTURES
- [ ] MAKE ENEMIES MOVEMENT
- [ ] MAKE THE PLAYER DIE ON CONTACT WITH AN ENEMY
- [ ] MAKE ENEMIES KILLABLE WITH PROJECTILES
- [ ] MAKE BONUS TEXTURES
- [ ] TURN CANVAS TEXTURE INTO A SPRITESHEET
- [ ] USE CANVAS SPRITESHEET FOR ENDING
- [ ] ADD MUSIC AND SOUND EFFECTS
- [ ] TEST ALL MAPS WITH NON-BONUS VERSION (COIN AND MOVE COUNTER ESPECIALLY)
- [ ] MEGA NORM CLEANUP
