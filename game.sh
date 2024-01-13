#!/bin/bash

levels=(
  "-d maps/valid/level_0.ber"
  "-d maps/valid/level_1.ber"
  "-r maps/valid/level_2.ber"
  "-d -r maps/valid/level_3.ber"
  "-l maps/valid/level_4.ber"
  "-b maps/valid/level_5.ber"
  "maps/valid/level_6.ber"
  "maps/valid/level_7.ber"
  "maps/valid/level_8.ber"
  "maps/valid/outstanding_map.ber"
)

for level in "${levels[@]}"; do
  flags=()
  paths=()

  # Split the level string into flags and paths
  for part in $level; do
    if [[ $part == -* ]]; then
      flags+=("$part")
    else
      paths+=("$part")
    fi
  done

  echo "flags: ${flags[@]}"
  echo "paths: ${paths[@]}"

  success=false
  while [ "$success" != true ]; do
    ./so_long "${flags[@]}" "${paths[@]}"
    exit_code=$?
    if [ $exit_code -eq 0 ]; then
      success=true
    else
      read -p "Level failed. Do you want to (R)etry, (C)ontinue to the next level, or (Q)uit? [R/C/Q]: " choice
      if [ "$choice" == "C" ] || [ "$choice" == "c" ]; then
        success=true
      elif [ "$choice" == "R" ] || [ "$choice" == "r" ]; then
        echo "Retrying..."
      elif [ "$choice" == "Q" ] || [ "$choice" == "q" ]; then
        echo "Game Over"
        exit 1
      else
        echo "Invalid choice. Please enter 'R' to retry, 'C' to continue, or 'Q' to quit."
      fi
    fi
  done
done
