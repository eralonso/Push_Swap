#! /bin/bash

if [ $# -gt 0 ] && [ $1 = "-b" ]; then

shift

if [ $# -gt 0 ] && [ $1 = "-r" ]; then

shift
MIN=$1
MAX=$2
NUMS=$(echo `ruby -e "puts ($MIN..$MAX).to_a.shuffle.join(' ')"`)

else

NUMS=$@

fi

ARG=$( ./push_swap $NUMS )
printf "%s\n" $ARG
printf "Número de movimientos: %d\n" $( echo "$ARG" | wc -w )
CHECK_OS=$( ./push_swap $NUMS | ./checker_OS $NUMS )
CHECK=$( ./push_swap $NUMS | ./checker $NUMS )
printf "checker_OS: %s\n" $CHECK_OS
printf "checker: %s\n" $CHECK
case $CHECK_OS in
	$CHECK) printf "\033[1;92mBIEN\033[0m\n" ;;
	*) printf "\033[1;91mMAL\033[0m\n" ;;
esac

else

NUMS=$@
ARG=$( ./push_swap $NUMS )
printf "%s\n" $ARG
printf "Número de movimientos: %d\n" $( echo $ARG | wc -w )
printf "Checker: "
CHECK=$( ./push_swap $NUMS | ./checker_OS $NUMS )
case $CHECK in
	OK|"") printf "\033[1;92mBIEN\033[0m\n" ;;
	KO) printf "\033[1;91mMAL\033[0m\n" ;;
	*) printf "check your input" ;;
esac

fi

: '
if [ $CHECK = "OK" ] ; then
	printf "\033[1;92mBIEN\033[0m\n"
elif [ $CHECK = "KO" ]; then
	printf "\033[1;91mMAL\033[0m\n"
fi '
