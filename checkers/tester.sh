#! /bin/bash

ARG=$( ./push_swap $@ )
printf "%s\n" $ARG
printf "Número de movimientos: %d\n" $( echo $ARG | wc -w )
printf "Checker: "
CHECK=$( ./push_swap $@ | checkers/checker_OS $@ )
case $CHECK in
	OK)  printf "\033[1;92mBIEN\033[0m\n" ;;
	KO)	printf "\033[1;91mMAL\033[0m\n" ;;
	*) printf "check your input" ;;
esac

: '
if [ $CHECK = "OK" ] ; then
	printf "\033[1;92mBIEN\033[0m\n"
elif [ $CHECK = "KO" ]; then
	printf "\033[1;91mMAL\033[0m\n"
fi '
