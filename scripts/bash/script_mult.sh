#!/bin/bash

array=()

for i in {0..255}
do
    array+=(multiplier_modded_${i}.cir)
    ngspice -o dump_${i}.txt multiplier_modded_${i}.cir
done