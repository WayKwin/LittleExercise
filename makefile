.PHONEY:shellmy
shellmy: myshell.c
	gcc -g $^ -o  $@
