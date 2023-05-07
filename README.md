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

### OTHERS
- [ ] Implement my printf and replace all printf by ft_printf
- [ ] Write Comments to functions with the extension doxygen
- [ ] For now, stat_tiles is useless

#### TOOLS
`find . -name '*.c' | xargs wc -l`
`env -i valgrind ./so_long assets/maps/test_map.ber`
