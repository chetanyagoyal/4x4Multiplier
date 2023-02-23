#!/bin/bash

array=()

for i in {0..7}
do
    array+=(Full_moo_modded_${i}.cir)
    ngspice -o dump_full_${i}.txt Full_moo_modded_${i}.cir
done
