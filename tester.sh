#!/bin/bash

ARG=$(./push_swap $@)
echo $ARG
printf "Número de movimientos: %d\n" $( expr $( echo $ARG | wc -w ) - 4 )
