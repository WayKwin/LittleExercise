.PHONEY:clean
ver = bug
ifeq ($(ver),bug)
ALL: philosopher_bug
CFLAGS += -Dbuf_version -g
RM_OBJ = pohilosopher_bug
else
ALL: philosopher 
RM_OBJ = pohilosopher
endif

philosopher : comm.c philosopher.c 
	gcc $^ -o $@  
philosopher_bug : comm.c philosopher.c 
	gcc $^ -o $@ $(CFLAGS)
clean:
	rm -rf $(RM_OBJ)
