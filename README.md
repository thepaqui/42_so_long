# 42_so_long

My finished *so_long* project for **42 Nice**, last updated on March 26th 2023, at 18:56.  
This project took me ~210 hours of work, over ~22 days.  
It was validated on March 27th 2023, on first push, with a grade of 125/100 with 3 outstanding flags.  

![Screen Shot 2023-03-27 at 4 00 30 PM](https://user-images.githubusercontent.com/117783405/227961970-a5594405-b873-419b-b64d-352b10742abd.png)

## Start of project 👾 January 29th 2023

I'm doing this project for **42 Nice**, just after finishing *pipex* with bonuses.

I've loved video games since I was 3 and my mom did the unthinkable and bought me a gray *Nintendo DS* with *New Super Mario Bros.*. It was all downhill from there...  
Since then, I've owned every Nintendo console, a PC, a PSP and a PS4. You can see the extent of my addiction on [my HLTB page].

[my HLTB page]: https://howlongtobeat.com/user/SCOUNDREL

Needless to say, I've been eyeing this project for a while now, and I'm finally doing it!

I already have a good idea of what I'll be doing, I want to make a *Yoshi's Island* (SNES) inspired game. Well, only for the bonuses.  
I'll first make the mandatory part to become familiar with the **MLX**, and then I'll move on to the serious stuff.  
Wish me luck as I embark on this journey!

## End of project 😩 March 26th 2023

I'm EXHAUSTED! I'm pooped. I want to go home and eat a sandwich.  

More seriously, I've been so engrossed in this project that it kinda feels like the end of an era.  
You know how when you come out of watching an amazing movie and you don't know what to do with your life anymore?  

But even though I love this project very much and I'm extremely proud of what I've accomplished (I remember the days of my so_long only being a white screen with a black pixel you could move with the keyboard *sniff* 🤧), it's time to let it go and go on to explore new projects (coming for you *Minishell* 👀).

It's been great but anything I'd add to this would be unnecessary fluff. I'm content leaving this project as is.  

I thank my friends and family for the emotional support and the feedback💗.  
And I don't thank *bbourret* for the emotional burden and the dogshit feedback (🤪 guuh duh make koopas FUCK YOU 🖕).  

Good night.  

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
If you're unsure of how to make the spritesheets, check out the three included texture packs (`textures/basic`, `textures/bonus` and `textures/bonus2`).  

## Legal disclaimer 🔨

All sprites in the basic texture pack were created by myself with *Aseprite*.  
All sprites in the bonus texture pack were ripped from the original *Super Mario World 2: Yoshi's Island* game on SNES and uploaded to *[The Spriters Resource]* by various rippers. I then edited them myself to be usable in my game with *Aseprite*.  

Credit goes to the following rippers from *[The Spriters Resource]*:
- Inky
- Drshnaps
- Sonicfan32
- Murphmario
- DogToon64
- Bacon
- David "Tonberry2k" Hurley
- Barack Obama (🤨)
- playgames169vg
- MarioFanGamer
- Nemica
- daemoth
- Romi
- Superjustinbros
- Arima
  
*Super Mario World 2: Yoshi's Island* and all of its assets belong to Nintendo.  
I am using these assets in a learning project for 42 Nice and in no way do I plan on releasing this game commercially, even as a free or opensource game.  
This repository only exists to privately share my project to friends, family and fellow 42 Network students.  
If the contents of this repository infringe on your copyright, please contact me through [my email address].  
Please note that the 42 Nice project *so_long* does not explicitly ask to reuse other video game's assets. Their use was a decision on my part.  

[The Spriters Resource]: https://www.spriters-resource.com/snes/yoshiisland/
[my email address]: theopaquier2@gmail.com
