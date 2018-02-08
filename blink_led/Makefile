
PROG_NAME = blink_led
ELF 	  = $(PROG_NAME).elf

###############################################################################
# Toolchain

PREFIX     = msp430
CP         = $(PREFIX)-gcc
AS         = $(PREFIX)-as
LD	   = $(PREFIX)-ld	
GDB        = $(PREFIX)-gdb
GDB_SERVER = mspdebug


###############################################################################
# Hardware Variables

MCU = msp430g2553
DEBUG_DEVICE = rf2500


###############################################################################
# Directories and Files Variables

SRC_DIR  = .

SRC_FILES  = $(shell find $(SRC_DIR) -name '*.c')
SRC_OBJ   := $(sort $(patsubst %.c,%.o,$(SRC_FILES)))

INC_DIR  = -I.
INC_DIR += -I/usr/msp430/include/


###############################################################################
# Compiler Variables

CFLAGS=-std=c99
CFLAGS += -ggdb
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -O0


###############################################################################
# Rules

.PHONY: all upload clean debug gdbserver
 

all: $(ELF)

$(ELF): $(SRC_OBJ)  
	$(CP) -mmcu=$(MCU) $(CFLAGS) $(INC_DIR) $(SRC_OBJ) -o $@


%.o: %.c
	$(CP) -mmcu=$(MCU) $(CFLAGS) $(INC_DIR) -c -o $@ $<
 


erase:
	$(GDB_SERVER) $(DEBUG_DEVICE) "erase"

upload: all erase
	$(GDB_SERVER) $(DEBUG_DEVICE) "prog $(ELF)"

gdbserver: upload
	xterm  -e "mspdebug --force-reset $(DEBUG_DEVICE) gdb" &
 
debug: 	gdbserver 
	$(GDB)  -ex="set confirm off" -ex="set remotetimeout 5" -ex="target remote localhost:2000"  -ex="file $(ELF)" 

clean:
	rm -f $(ELF) $(SRC_OBJ) 

