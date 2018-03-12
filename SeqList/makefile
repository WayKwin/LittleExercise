CLFAGS =-g
.PHONEY:clean
SeqList:test.o SeqList.o
	g++ -g  $^ -o $@ 
.o:.cpp
	g++ -c -g  $^ -o $@ 
clean:
	rm -rf *.o SeqList
