# 42_so_long

My still unfinished *so_long* project for **42 Nice**, last updated on February 22nd 2023, at 20:35.

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
So if you have 150 or more coins on screen, they won't be animated for performance's sake.  
You can modify this threshold in `srcs/game.h` with the `MAXCOINS` macro.

## Notes

### To-do list

- [x] ADD TEXT TEXTURES
- [x] MAKE `put_str_to_img()` FUNCTION AND ALL ITS DEPENDENCIES
- [x] MAKE `put_nbr_to_img()` FUNCTION
- [x] MAKE WALL LINKING TILESET
- [x] IMPLEMENT WALL LINKING
- [x] FIX MOVE COUNTER REFRESH
- [x] PRINT CURRENT NUMBER OF COINS ON SCREEN
- [x] TURN OFF COIN ANIMATION WHEN COIN COUNT IS OVER A THRESHOLD
- [x] ADD ENDING (BLACK SCREEN WITH RAINBOW CONGRATULATIONS)
- [x] ADD EXITING MESSAGE
- [ ] CLEAN UP WALL LINKING CODE (NORM)
- [ ] CHECK NORM FOR MACROS SHORTER THAN THEIR VALUES
- [ ] REMOVE MACROS FOR SHORTENED NAMES
- [ ] CHECK NORM
