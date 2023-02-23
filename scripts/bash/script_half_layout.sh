#!/bin/bash

array=()

for i in {0..3}
do
    array+=(half_modded_layout${i}.cir)
    ngspice -o dump_half_layout${i}.txt half_modded_layout${i}.cir
done
