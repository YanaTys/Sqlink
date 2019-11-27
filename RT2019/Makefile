# this is a minimal makefile for demo purposes, keep it that way...
obj-m:=QMsg.o
QMsg-objs:=qMessage.o
V?=0
KDIR?=/lib/modules/$(shell uname -r)/build
# in an embedded system:
#KDIR:=[where the system maker gave me kernel headers+makefile or the kernel itself which has a makefile]
#ARCH:=arm
#CROSS_COMPILE:=[path+common prefix to where the toolchain is]
# You could also use W=2 and W=3 for more warnings but most kernel headers
# fail those...
W?=1

.PHONY: all
all: modules write read testCode

.PHONY: modules
modules:
	$(MAKE) -C $(KDIR) M=$(CURDIR) V=$(V) W=$(W) modules
.PHONY: clean
clean:
	$(MAKE) -C $(KDIR) M=$(CURDIR) V=$(V) clean
	rm -f *.stamp
	rm -f write read testCode

write: write.c
	gcc -Wall -Werror -ansi -pedantic -O2 -o $@ $<
read: read.c
	gcc -Wall -Werror -ansi -pedantic -O2 -o $@ $<
testCode: testCode.c
	gcc -Wall -Werror -ansi -pedantic -O2 -o $@ $< -lpthread

.PHONY: insmod
insmod:
	sudo insmod ./QMsg.ko
	sleep 1
	sudo chmod 666 /dev/QMsg*

.PHONY: rmmod
rmmod:
	sudo rmmod QMsg

.PHONY: test_insmod_rmmod
test_insmod_rmmod:
	for number in $$(seq 1 1000);\
	do \
	sudo insmod QMsg.ko ;\
	sleep 1 ;\
	sudo chmod 666 /dev/QMsg*;\
	(number=number+1);\
	sudo rmmod QMsg;\
	echo $$number;\
	done
