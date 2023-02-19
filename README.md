# 42_so_long

My still unfinished *so_long* project for **42 Nice**, last updated on February 19th 2023, at 19:49.

## Presentation

I'm doing this project for **42 Nice**, just after finishing *pipex* with bonuses.

I've loved video games since I was 3 and my mom did the unthinkable and bought me a gray *Nintendo DS* with *New Super Mario Bros.*. It was all downhill from there...  
Since then, I've owned every Nintendo console, a PC, a PSP and a PS4. You can see the extent of my addiction on [my HLTB page].

[my HLTB page]: https://howlongtobeat.com/user/SCOUNDREL

Needless to say, I've been eyeing this project for a while now, and I'm finally doing it!

I already have a good idea of what I'll be doing, I want to make a *Yoshi's Island* (SNES) inspired game. Well, only for the bonuses.  
I'll first make the mandatory part to become familiar with the **MLX**, and then I'll move on to the serious stuff.  
Wish me luck as I embark on this journey!

ADVICE: Maps shouldn't be any larger than 60 (width) by 30 (height) for playability. More than that works but isn't the best.

## Notes

Implement text spritesheet!  
Text spritesheet should have:
- 26 capital letters,
- 10 numbers,
- 13 extra characters: `.`, `,`, `:`, `'`, `"`, `!`, `?`, `(`, `)`, `&`, `$`, `-`, ` `.  

So text spritesheet will have 7x7 sprites for 49 sprites!

### To-do list

- [x] MAKE THE GAME USE 32x32 SPRITES
- [x] TEST `put_t_xpm_to_img` FUNCTION WITH ACTUAL SPRITESHEET
- [x] ADD ANIMATION CODE (`update_player()`)
- [x] MERGE ANIMATIONS IN SPRITESHEETS
- [x] IMPLEMENT SPRITEHEETS
- [x] ACTUALLY DRAW MAP
- [x] IMPLEMENT COLLECTIBLES
- [x] IMPLEMENT DRAWING OPTIMIZATIONS (not redrawing what doesn't need to be)
- [x] CENTRALIZE PLAYER ANIMATION HANDLING IN THE SAME FUNCTION
- [x] ADD PLAYER ANIMATION WHEN COLLECTING A COIN
- [x] IMPLEMENT HITBOXES
- [x] IMPLEMENT WALL COLLISIONS
- [x] IMPLEMENT HITBOXES FOR COINS
- [x] GET COIN LOCATIONS IN A `t_vector` ARRAY TO INCREASE PERFORMANCE IN HUGE MAPS
- [x] ADD TEXT TEXTURES
- [x] MAKE `put_str_to_img()` FUNCTION AND ALL ITS DEPENDENCIES
- [ ] MAKE `put_nbr_to_img()` FUNCTION
- [ ] PRINT CURRENT NUMBER OF MOVES AND COINS ON SCREEN
- [ ] USE MLX'S ORIGINAL XPM FUNCTION TO CATCH OTHER UNEXPECTED CASES
- [ ] DISPLAY COIN AND MOVE COUNTER
- [ ] CHECK NORM FOR MACROS SHORTER THAN THEIR VALUES
- [ ] REMOVE MACROS FOR SHORTENED NAMES
- [ ] CHECK NORM
