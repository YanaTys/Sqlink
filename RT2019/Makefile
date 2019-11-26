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
.PHONY: modules
modules:
	$(MAKE) -C $(KDIR) M=$(CURDIR) V=$(V) W=$(W) modules
.PHONY: clean
clean:
	$(MAKE) -C $(KDIR) M=$(CURDIR) V=$(V) clean
	rm -f *.stamp

write: write.c
	gcc -ansi -pedantic -O2 -o $@ $<
read: read.c
	gcc -ansi -pedantic -O2 -o $@ $<

.PHONY: insmod
insmod:
	sudo insmod ./QMsg.ko
	sleep 1
	sudo chmod 666 /dev/QMsg*

.PHONY: rmmod
rmmod:
	sudo rmmod QMsg
