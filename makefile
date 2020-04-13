#Shell-Project Makefile
CC        = gcc
CCFLAGS   = -Wall
TARGET    = main
OBJDIR    = obj
COMMONDIR = common

SOURCE  = $(wildcard *.c ./common/*.c)
_OBJ    = $(notdir $(patsubst %.c, %.o, $(SOURCE)))
OBJ     = $(patsubst %, ${OBJDIR}/%, $(_OBJ))
HEADER  = $(patsubst ./common/%.c, ./common/%.h, $(SOURCE))
INCLUDES = -I./common


$(TARGET) : $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

$(OBJDIR)/$(TARGET).o : $(TARGET).c
	$(CC) $(INCLUDES) $(CCFLAGS) -c $< -o $@

$(OBJDIR)/%.o : $(COMMONDIR)/%.c $(COMMONDIR)/%.h
	$(CC) $(INCLUDES) $(CCFLAGS) -c $< -o $@

.PHONY:clean
clean:
	rm -rf $(TARGET) ${OBJ}
