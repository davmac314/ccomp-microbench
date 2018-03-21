#!/bin/bash
set -euxo pipefail
#set -euo pipefail
# -e exit first err, -u err on unset vars, -x print, -o pipefail: exit on piped errs also

## Usage
# cd ccomp-microbench 
# bash makeAndBench.bash

csv='bm.csv'
printf "wall time in seconds\n" > "$csv" 

declare -a CCs=("gcc" "clang")


for dir in ./bm*/
do
  for CC in "${CCs[@]}"
  do 

    cd "$dir"
    bmNN=$(ls bm*.c)
    
    gcc -c -O3 -Wall -Wextra -Wno-unused-parameter driver.c -o driver.o # driver always with compiler 1
    $CC -g -O3 -Wall -Wextra -Wno-unused-parameter -fomit-frame-pointer -march=native -std=c99 driver.o bm*.c -o "$bmNN-$CC.exe"
    
    printf "$bmNN-$CC\n"                                >> "../$csv" # append only
    # careful, time isnot /usr/bin/time which is $(which time), run several times
    $(which time) -f '%e'  ./"$bmNN-$CC.exe" 2>&1 | tee -a "../$csv"
    $(which time) -f '%e'  ./"$bmNN-$CC.exe" 2>&1 | tee -a "../$csv"
    $(which time) -f '%e'  ./"$bmNN-$CC.exe" 2>&1 | tee -a "../$csv"
    $(which time) -f '%e'  ./"$bmNN-$CC.exe" 2>&1 | tee -a "../$csv"
    $(which time) -f '%e'  ./"$bmNN-$CC.exe" 2>&1 | tee -a "../$csv"
    
    
    cd ..
  done
  printf "\n"  >> "$csv"
done

## You may want to have a look at what the compiler produce
# gdb -tui --readnow ./bm4-gcc.exe 
# layout split
# break bm4
# run
# display/i $pc
# stepi
