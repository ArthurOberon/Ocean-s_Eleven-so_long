/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gameplay_all_texts.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:41:24 by aoberon           #+#    #+#             */
/*   Updated: 2024/01/14 13:46:20 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Initialize the first part of the texts struct.
 * 
 * @param texts texts struct to initialize.
 */
static void	init_all_texts_part_1(t_text *texts)
{
	texts[e_text_tutorial_1].text = "Welcome, gentlemen. I will be brief. \
Our goal today is to break into the vault of the three largest casinos in \
Las Vegas, the Bellagio, the Mirage and the MGM Grand Las Vegas. There is \
$160 million in that vault. So let's have one last meeting to explain this \
heist. If you already know everything, press X to skip it.";
	texts[e_text_tutorial_2].text = "First, we need to collect letters to get \
the code to the vault. You can use WASD or the arrow keys to move around. \
Then take a look at our team.";
	texts[e_text_tutorial_3].text = "There's Danniel \"Danny\" Ocean, that's \
me. My specialty is that I can be touched by guards 2 times, for everyone \
else be touched once it is Game Over.";
	texts[e_text_tutorial_4].text = "There's Basher Tarr, he's got dynamite. \
Only one can destroy a wall, I don't even know what happens when he drops \
multiple bombs. To drop a bomb press SPACE and to remove it press DELETE.";
	texts[e_text_tutorial_5].text = "There's Linus Caldwell, he can \
pickpocket the guard. I'm sure every guard has a letter with him. Stealing \
it from them might make collecting easier, but be careful not to get caught. \
To start stealing, press SPACE when a guard is in your area, press DELETE \
to stop. And to steal properly, press SPACE when the bar is green.";
	texts[e_text_tutorial_6].text = "There's Robert \"Rusty\" Ryan, \
he's less noticeable to the guards. This can be useful.";
	texts[e_text_tutorial_7].text = "About the guards. If we enter their \
field of vision, they will immediately follow us. And if they touch us, it \
is the end, except for me, who has a second chance. They only see in front \
of us, and they turn on themselves, so do not think you are safe behind them.";
}

/**
 * @brief Initialize the second part of the texts struct.
 * 
 * @param texts texts struct to initialize.
 */
static void	init_all_texts_part_2(t_text *texts)
{
	texts[e_text_tutorial_8].text = "Finally, use the keys 1, 2, 3, 4 to \
change your character. But maybe you will start without the other one, so \
go get it in the casino, they will be somewhere. You can also press P to \
pause, R to restart the heist, ESC or Q to quit and T to read this again.";
	texts[e_text_start_danny].text = "Let's get the code, open the vault, \
and go home!";
	texts[e_text_start_rusty].text = "I love this place! Well, I have to \
open the vault, so let's be discreet and find the code.";
	texts[e_text_start_linus].text = "Okay, I can miss my shot. The code, \
I can easily steal it from the guards.";
	texts[e_text_start_basher].text = "So, so, so... Where are you little \
code?";
	texts[e_text_remain_one_collectible_danny].text = "One more to go!";
	texts[e_text_remain_zero_collectible_danny].text = "Perfect! Let's go to \
the vault and get the $160 million!";
	texts[e_text_remain_one_collectible_rusty].text = "That was the last \
one... No, that was the one before last, so the next one is the last one, \
no time to lose.";
	texts[e_text_remain_zero_collectible_rusty].text = "Great! Where is the \
vault?";
	texts[e_text_remain_one_collectible_linus].text = "The next one is the \
last one! I'm almost there!";
	texts[e_text_remain_zero_collectible_linus].text = "I made it! All that \
remains is the vault.";
}

/**
 * @brief Initialize the third part of the texts struct.
 * 
 * @param texts texts struct to initialize.
 */
static void	init_all_texts_part_3(t_text *texts)
{
	texts[e_text_remain_one_collectible_basher].text = "Oh, the next one \
marks the end of this heist, that was so fast.";
	texts[e_text_remain_zero_collectible_basher].text = "Okay, so the vault. \
I'm sure you're out there, let's go. ";
	texts[e_text_rusty_to_danny_1].text = "Let's keep going.";
	texts[e_text_rusty_to_danny_2].text = "Of course!";
	texts[e_text_linus_to_danny_1].text = "Is it your turn?";
	texts[e_text_linus_to_danny_2].text = "Yes, stay behind and follow me.";
	texts[e_text_basher_to_danny_1].text = "I hope you are right about \
this plan.";
	texts[e_text_basher_to_danny_2].text = "Trust me.";
	texts[e_text_danny_to_rusty_1].text = "Your turn.";
	texts[e_text_danny_to_rusty_2].text = "Okay! Perfect!";
	texts[e_text_linus_to_rusty_1].text = "Are you eating again?";
	texts[e_text_linus_to_rusty_2].text = "Yes. What's wrong?";
	texts[e_text_basher_to_rusty_1].text = "That was fun!";
	texts[e_text_basher_to_rusty_2].text = "And it is not over yet.";
	texts[e_text_danny_to_linus_1].text = "You know, you lose focus in this \
game for one second and somebody gets hurt.";
}

/**
 * @brief Initialize the fourth part of the texts struct.
 * 
 * @param texts texts struct to initialize.
 */
static void	init_all_texts_part_4(t_text *texts)
{
	texts[e_text_danny_to_linus_2].text = "I know, I know.";
	texts[e_text_rusty_to_linus_1].text = "Listen to me. You look down, \
they know you're lying and up, they know you don't know the truth. Don't \
use seven words when four will do. Don't shift your weight, look always at \
your mark but don't stare, be specific but not memorable, be funny but don't \
make him laugh. He's got to like you then forget you the moment you've left \
his side. And for God's sake, whatever you do, don't, under any \
circumstances... *dring dring*";
	texts[e_text_rusty_to_linus_2].text = "Don't what...?";
	texts[e_text_basher_to_linus_1].text = "Don't screw up.";
	texts[e_text_basher_to_linus_2].text = "Yes, you don't need to say that.";
	texts[e_text_danny_to_basher_1].text = "Basher, this is your moment.";
	texts[e_text_danny_to_basher_2].text = "Time to shine!";
	texts[e_text_rusty_to_basher_1].text = "Are you going to use your bomb?";
	texts[e_text_rusty_to_basher_2].text = "Why take it if I'm not going to \
use it?";
	texts[e_text_linus_to_basher_1].text = "Can I help you?";
	texts[e_text_linus_to_basher_2].text = "No! Don't touch anything.";
	texts[e_text_collect_steal_code].text = "We already have that code. \
It has already been stolen.";
}

/**
 * @brief Init all texts of the game.
 * 
 * @param game game struct, used to exit game if a malloc fail.
 * @param gameplay gameplay struct, used to get all_texts to initialize.
 */
void	init_all_texts_of_the_game(t_game *game, t_gameplay *gameplay)
{
	int		i;
	t_text	*texts;

	texts = ft_calloc(sizeof(t_text), e_total_text_number);
	if (!texts)
		exit_game(*game, EXIT_FAILURE, "Error of malloc.\n");
	gameplay->all_texts = texts;
	init_all_texts_part_1(texts);
	init_all_texts_part_2(texts);
	init_all_texts_part_3(texts);
	init_all_texts_part_4(texts);
	texts[e_text_code].text = ft_strdup("Enter this code and get the \
money! Okay, so: <");
	if (!texts[e_text_code].text)
		exit_game(*game, EXIT_FAILURE, "Error of malloc.\n");
	i = 0;
	while (i < e_total_text_number)
	{
		texts[i].has_been_display = false;
		i++;
	}
}
