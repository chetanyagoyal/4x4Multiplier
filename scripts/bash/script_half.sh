#!/bin/bash

array=()

for i in {0..3}
do
    array+=(half_modded${i}.cir)
    ngspice -o dumphalf_${i}.txt half_modded${i}.cir
done