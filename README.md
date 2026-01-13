# 🐬 so_long

## 📝 About

**Libft** is the first graphic project from **École 42** introducing students to

The objective is to 
---
## f

Here's a man I create to explain the simple usage of the mlx lib : [So_Long_Man](https://arthuroberon.notion.site/So_Long_Man-19d70fea9d6548e9aa952cf3a955a9ce).

## ⚙️ Usage

### 🏗️ Compilation

```sh
make				# make the game
make bonus			# make the game
make clean			# remove object files
make fclean			# remove object files + so_long
make re				# rebuild everything
```

###  Play

#### Create a Map


First, you have to create a map file respecting the following rules :
- Having a `.ber` extension on the file.
- constructed with 3 components: walls, collectibles, and free space.
- composed of only these 5 characters:
	- `0` for an empty space.
	- `1` for a wall.
	- `C` for a collectible.
	- `E` for a map exit.
	- `P` for the player’s starting position.
- must contain
	- 1 exit.
	- 1 starting position.
	- at least 1 collectible.
- must be rectangular.
- must be enclosed/surrounded by walls.

Here a example of a minimalist `.ber` map :
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

If you don't want to create your own map, there plenty of valid map in the following folder : `maps/valid/`.

### Launch the Game

Then, to launch the game, simply execute this command :

```sh
./so_long <path_to_your_map>
```

text to send to the "jacket" of the game :

## 💵 Ocean's Eleven

	A smash and grab job?
	-
	Slightly more complicated than that.

Tonight, proceed to the biggest heist that Las Vegas has never see. Steal 160 000 000 $ in the safe of 3 casinos : The ..., ... and ... .


Play as Danny, Rusty, ... and ... to go through casino maze, security guards and code to get access to the safe.

And do not underestimate your team, each has there very own talent.

	There's a 95-pound Chinese man with 160 million dollars behind this door.
	-
	Let's get him out.

In this game, there is plenty of new features enemies, QTE, dialogue, and much more.
To play, execute the following command :
```sh
bash game.sh
```
Between,  participate to the heist of a lifetime.

	You're either in or you out

---


### Man

Here's Danny :
```
W : move up
S : move down
A : move left
D : move right
```

Here's xxx :

```
A : do something
```
Here's xxx :



Here's xxx :




This is a security guard, if your are not afraid of him (or you are equip with dinamite), be ready to run away if his see you (or read to press the detonator).

Go getting all letters containing the code to the safe.

	and for God's sakes whatever you do, don't under any circumstances --