CC = gcc
CC_FLAGS = -Wall -Wextra -std=c99

# temporary directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin
IMGDIR = img

# generate target name from enclosing folder
TARGET = $(BINDIR)/myprog.exe

C_FILES = $(wildcard $(SRCDIR)/*.c)

all: run

# notdir  	strip directory prefix
# :.c=.o	replace suffix
$(TARGET): $(addprefix $(OBJDIR)/, $(notdir $(C_FILES:.c=.o)))
	mkdir -p $(BINDIR)
	$(CC) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CC_FLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJDIR) $(BINDIR) $(IMGDIR)

run: $(TARGET)
	./$(TARGET)

