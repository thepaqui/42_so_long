# 42_so_long

My still unfinished *so_long* project for **42 Nice**, last updated on March 24th 2023, at 19:02.

## Presentation 👾

I'm doing this project for **42 Nice**, just after finishing *pipex* with bonuses.

I've loved video games since I was 3 and my mom did the unthinkable and bought me a gray *Nintendo DS* with *New Super Mario Bros.*. It was all downhill from there...  
Since then, I've owned every Nintendo console, a PC, a PSP and a PS4. You can see the extent of my addiction on [my HLTB page].

[my HLTB page]: https://howlongtobeat.com/user/SCOUNDREL

Needless to say, I've been eyeing this project for a while now, and I'm finally doing it!

I already have a good idea of what I'll be doing, I want to make a *Yoshi's Island* (SNES) inspired game. Well, only for the bonuses.  
I'll first make the mandatory part to become familiar with the **MLX**, and then I'll move on to the serious stuff.  
Wish me luck as I embark on this journey!

## Legal disclaimer 🔨

All sprites in the basic texture pack were created by myself with *Aseprite*.  
All sprites in the bonus texture pack were ripped from the original *Super Mario World 2: Yoshi's Island* game on SNES and uploaded to *[The Spriters Resource]* by various rippers. I then edited them myself to be usable in my game with *Aseprite*.  
  
*Super Mario World 2: Yoshi's Island* and all of its assets belong to Nintendo.  
I am using these assets in a learning project for 42 Nice and in no way do I plan on releasing this game comercially, even as a free game.  
This repository only exists to privately share my project to friends, family and fellow 42 Network students.  
If the content of this repository infringes on your or your company's rights, please contact me through [my email address].  
Please note that the 42 Nice project *so_long* does not explicitly ask to reuse other video game's assets. Their use was a decision on my part.  

[The Spriters Resource]: https://www.spriters-resource.com/snes/yoshiisland/
[my email address]: theopaquier2@gmail.com

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
- `font.xpm`.  

For the bonuses, also add:
- `player_bonus.xpm`,
- `cursor.xpm`,
- `projectile.xpm`,
- `end_bg.xpm`,
- `enemy_fly_h.xpm`,
- `enemy_fly_v.xpm`,
- `enemy_ground.xpm`.  

Then, you'll just have to change the macros in `game.h` and `sprites_bonus.h` to use your folder's name instead of *basic* or *bonus*.  
If you're unsure of how to make the spritesheets, check out the two included texture packs (`textures/basic` and `textures/bonus`).  

## To-do list 🗒️ 

✅ MAKE ENEMIES TEXTURES  
✅ MAKE PLAYER GROUNDED IDLE ANIMATION  
✅ IMPLEMENT BASIC ENEMIES CODE  
✅ MAKE ENEMIES DISPLAY  
✅ MAKE ENEMIES MOVEMENT  
✅ MAKE ENEMIES KILLABLE WITH PROJECTILES  
✅ CLEAN UP ENEMY LIST WHEN SOME ARE KILLED  
✅ MAKE THE PLAYER DIE ON CONTACT WITH AN ENEMY  
✅ IMPLEMENT GAME OVER SEQUENCE  
✅ IMPLEMENT ALL PLAYER ANIMATIONS  
✅ TEST GAME OVER WITH FUCKTON OF ENEMIES  
✅ MAKE ENEMIES ANIMATIONS  
✅ MAKE BETTER RANDOMNESS FOR ENEMY SPAWNING  
✅ MAKE BONUS `player.xpm` SPRITESHEET  
✅ TEST ALL MAPS WITH MANDATORY VERSION  
✅ MAKE BASIC `player_bonus.xpm` SPRITESHEET  
⏳ TEST ALL MAPS WITH BONUS VERSION  
❌ ADD MUSIC (?) AND SOUND EFFECTS  
❌ MAKE BONUS2 TEXTURE PACK  
❌ MEGA NORM CLEANUP  
