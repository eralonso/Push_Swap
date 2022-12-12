ARGS="1 2 4 3"; ./push_swap $ARGS; printf "Número de movimientos: %i\n" $( expr $( ./push_swap $ARGS | wc -l ) - 1)
