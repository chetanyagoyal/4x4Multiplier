#!/bin/bash

array=()

for i in {0..255}
do
    array+=(multiplier_layout_modded_${i}.cir)
    ngspice -o layout_dump_${i}.txt multiplier_layout_modded_${i}.cir
done