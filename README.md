# 42_so_long

My still unfinished *so_long* project for **42 Nice**, last updated on March 18th 2023, at 20:50.

## Presentation 👾

I'm doing this project for **42 Nice**, just after finishing *pipex* with bonuses.

I've loved video games since I was 3 and my mom did the unthinkable and bought me a gray *Nintendo DS* with *New Super Mario Bros.*. It was all downhill from there...  
Since then, I've owned every Nintendo console, a PC, a PSP and a PS4. You can see the extent of my addiction on [my HLTB page].

[my HLTB page]: https://howlongtobeat.com/user/SCOUNDREL

Needless to say, I've been eyeing this project for a while now, and I'm finally doing it!

I already have a good idea of what I'll be doing, I want to make a *Yoshi's Island* (SNES) inspired game. Well, only for the bonuses.  
I'll first make the mandatory part to become familiar with the **MLX**, and then I'll move on to the serious stuff.  
Wish me luck as I embark on this journey!

## How to use ❓

### General advice 🧰

Maps shouldn't be any larger than ~60 (width) by ~30 (height) for playability's sake (if the game uses 32x32 textures).  
  
The game will start lagging if you have too many collectibles,  
so the `MAXCOINS` macro sets the number over which collectibles won't be animated anymore.  
You can modify this threshold in `srcs/game.h` or `bonus/srcs/game_bonus.h` with the `MAXCOINS` macro.  
  
You can modify a lot of things in this game.  
Check out my comments in `bonus/srcs/game_bonus.h` and in `bonus/process/process_bonus.h` to know what to change.  
Fiddle around with some stuff and have fun!  

### Texture packs 🎨

You can change texture size by changing the `SPR_DIM` macro in `srcs/game.h` and in `bonus/srcs/game_bonus.h`.  
You can then use your own textures by creating a new folder in the `textures` folder.  
In it, you'll need spritesheets with these names:
- `map.xpm`,
- `bg.xpm` -> will display starting from the window's bottom, tiles horizontally only, fills the window vertically with the first sprite,
- `coin.xpm`,
- `player.xpm`,
- `end_bg.xpm`,
- `font.xpm`.  

If you're doing this to the bonuses, also add:
- `cursor.xpm`,
- `projectile.xpm`,
- `enemy_fly_h.xpm`,
- `enemy_fly_v.xpm`,
- `enemy_ground.xpm`.  

Then, you'll just have to change the macros to use your folder's name instead of *basic* or *bonus*.  

If you're unsure of how to do this, check out the two included texture packs (`textures/basic` and `textures/bonus`).  
All sprites in the basic pack were created by myself with *Aseprite*.  
All sprites in the bonus pack were ripped from the original *Yoshi's Island* on SNES and uploaded to *[The Spriters Resource]* by various rippers. I then edited them myself to be usable with my game with *Aseprite*.  
  
[The Spriters Resource]: https://www.spriters-resource.com/snes/yoshiisland/

## To-do list 🗒️ 

Make enemy movements and display.  

✅ MAKE BASIC AND BONUS BACKGROUND TEXTURES  
✅ IMPLEMENT BACKGROUND TEXTURE TILING  
✅ IMPLEMENT BACKGROUND IN NON-BONUS VERSION  
✅ IMPLEMENT COUNTER BUG FIXES IN NON-BONUS VERSION  
✅ FIX PROJECTILE HIT DETECTION TO AVOID WEIRD BOUNCES  
✅ MAKE BACKGROUND TEXTURE TILING START FROM BOTTOM OF SPRITESHEET  
✅ IMPLEMENT PROJECTILE DESTROYING ANIMATION  
✅ MAKE BONUS TEXTURES  
✅ MAKE GROUNDED DETECTION  
✅ TURN CANVAS TEXTURE INTO A SPRITESHEET  
✅ USE BLACK BOARD SPRITE FROM SMW2:YI FOR ENDING IN BONUS  
✅ USE CANVAS SPRITESHEET FOR ENDING  
✅ MAKE ENEMIES TEXTURES  
✅ MAKE PLAYER GROUNDED IDLE ANIMATION  
✅ IMPLEMENT BASIC ENEMIES CODE  
⏳ MAKE ENEMIES DISPLAY  
⏳ MAKE ENEMIES MOVEMENT  
⏳ MAKE ENEMIES ANIMATIONS  
⏳ IMPLEMENT ALL PLAYER ANIMATIONS  
❌ MAKE BETTER RANDOMNESS FOR ENEMY SPAWNING  
❌ MAKE NEW BASIC PLAYER SPRITESHEET  
❌ MAKE PLAYER SPRITESHEET COMPATIBLE WITH BOTH BONUS AND NON BONUS GAME  
❌ MAKE THE PLAYER DIE ON CONTACT WITH AN ENEMY  
❌ MAKE ENEMIES KILLABLE WITH PROJECTILES  
❌ ADD MUSIC AND SOUND EFFECTS  
❌ TEST ALL MAPS WITH NON-BONUS VERSION (COIN AND MOVE COUNTER ESPECIALLY)  
❌ MEGA NORM CLEANUP  
