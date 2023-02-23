#!/bin/bash

array=()

for i in {0..7}
do
    array+=(full_modded_layout${i}.cir)
    ngspice -o dump_full_layout${i}.txt full_modded_layout${i}.cir
done
