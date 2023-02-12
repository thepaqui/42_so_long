# 42_so_long

My still unfinished *so_long* project for **42 Nice**, last updated on February 12th 2023, at 20:58.

## Presentation

I'm doing this project for **42 Nice**, just after finishing *pipex* with bonuses.

I've loved video games since I was 3 and my mom did the unthinkable and bought me a gray *Nintendo DS* with *New Super Mario Bros.*. It was all downhill from there...  
Since then, I've owned every Nintendo console, a PC, a PSP and a PS4. You can see the extent of my addiction on [my HLTB page].

[my HLTB page]: https://howlongtobeat.com/user/SCOUNDREL

Needless to say, I've been eyeing this project for a while now, and I'm finally doing it!

I already have a good idea of what I'll be doing, I want to make a *Yoshi's Island* (SNES) inspired game. Well, only for the bonuses.  
I'll first make the mandatory part to become familiar with the **MLX**, and then I'll move on to the serious stuff.  
Wish me luck as I embark on this journey!

## To-do list

Implement check_tokens() in palette.c!

- [x] MAKE COLOR KEYWORDS CASE INSENSITIVE
- [x] CHECK PALETTE VALIDITY (double color is fine, double token isn't)
- [x] PARSE XPM SPRITE INTO SPRITESHEET
- [x] CHECK SPRITESHEET VALIDITY (undefined token, wrong size)
- [x] PARSE XPM FILES INTO T_XPM STRUCT (parsing/xpm.c)
- [x] HANDLE STRINGS NOT FULLY COMPOSED OF DIGITS AS ERRORS FOR PALETTE INFO
- [x] STRENGTHEN INVALID XPM DETECTION (especially around `"`, `\n` and `,`)
- [ ] MAKE `put_t_xpm_to_img` FUNCTION (process/xpm.c)
- [ ] USE MLX'S ORIGINAL XPM FUNCTION TO CATCH OTHER UNEXPECTED CASES
- [ ] ADD TEXT TEXTURES
- [ ] MERGE ANIMATIONS IN SPRITESHEETS
- [ ] IMPLEMENT SPRITEHEETS
- [ ] CHECK NORM FOR MACROS SHORTER THAN THEIR VALUES
- [ ] REMOVE MACROS FOR SHORTENED NAMES
- [ ] CHECK NORM
