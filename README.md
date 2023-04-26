![Norminette](https://github.com/ArthurOberon/So_long/actions/workflows/norminette.yml/badge.svg) ![Makefile](https://github.com/ArthurOberon/So_long/actions/workflows/makefile.yml/badge.svg)

# So_long

## Usage

To launch so_long with a map :
```
./so_long map.ber
```

### Example

```
./so_long maps/example.ber
```

### Compiling

```
make all
```

# How My So_long Works ?

---

### Author
* **[Arthur Obéron](https://github.com/ArthurOberon)**

### Thanks to :
* **Alex Cardona**
* **Johanne Vigny**
* **Ulysse Levallois**
* **[Quentin Thierry](https://github.com/QuentinThierry/)**

---

# PROGRESS STATUS

**[Road/MindMap](https://www.figma.com/file/9b6RaE8ybtQWJs5uYydCCP/So_long?node-id=0%3A1&t=GJjjdQKJ2lWbG2y5-0)**

### A_STAR ALGO FOR COLLECTIBLE
- [x] Number of collectibles
- [x] Positions of all collectibles
- [x] a_star with each collectible position
- [x] bzero_path_map struct instead of free/malloc

### OTHERS
- [ ] Implement my printf
- [x] Free t_sprite map_sprites + free map_sprites[i].sprite_img
- [ ] Replace all mallocs by callocs
- [ ] Sort so_long.h by alphabetic
- [ ] Write Comments to functions with extension doxygen
- [ ] Protect init_xpm_file ?
