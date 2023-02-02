# 42_so_long

My *so_long* project for **42 Nice**, last updated on February 2nd 2023, at 11:04.

## Presentation

I'm doing this project for **42 Nice**, just after finishing *pipex* with bonuses.

I've loved video games since I was 3 and my mom did the unthinkable and bought me a gray *Nintendo DS* with *New Super Mario Bros.*. It was all downhill from there...  
Since then, I've owned every Nintendo console, a PC, a PSP and a PS4. You can see the extent of my addiction on [my HLTB page].

[my HLTB page]: https://howlongtobeat.com/user/SCOUNDREL

Needless to say, I've been eyeing this project for a while now, and I'm finally doing it!

I already have a good idea of what I'll be doing, I want to make a *Yoshi's Island* (SNES) inspired game. Well, only for the bonuses.  
I'll first make the mandatory part to become familiar with the **MLX**, and then I'll move on to the serious stuff.  
Wish me luck as I embark on this journey!

I'll keep a diary detailing each day of work just under this. Feel free to read it!  
I'll also toss in some amazing video game music I listened to while working on this project.

## Diary

<details>
<summary>Click here to read</summary>

### February 2nd 2023

I just started this project today, so nothing of note happened. I just setup a basic Makefile, my work tree and my header files.  
I also imported the MLX and skimmed over its documentation (btw, thanks to hsmits and jvan-sni for [42 Docs]!)

[42 Docs]: https://harm-smits.github.io/42docs/libs/minilibx
</details>

## Notes

(This section is for me, akin to a sticky note to remember what I was doing the previous day)

GO BACK TO CHECKING THE MAP

main contains mlx_init.  
mlx_init contains:  
- mlx_new_window
- mlx_loop_hook -> game loop
- mlx_hook -> event handling
- mlx_loop

mlx_hook and mlx_loop_hook initialize what will happen in my game loop.  
Once they're set, I call mlx_loop to start the game loop.
