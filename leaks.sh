#!/bin/bash
while true
do
	leaks minishell | grep Process | tail -n 2
	printf "\n\n"
	sleep 1
done
