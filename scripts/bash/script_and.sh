#!/bin/bash

array=()

for i in {0..3}
do
    array+=(AND_modded${i}.cir)
    ngspice -o dump_and${i}.txt AND_modded${i}.cir
done