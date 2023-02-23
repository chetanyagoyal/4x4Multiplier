#!/bin/bash

array=()

for i in {0..3}
do
    array+=(and_layout_modded${i}.cir)
    ngspice -o dump_and_layout${i}.txt and_layout_modded${i}.cir
done
