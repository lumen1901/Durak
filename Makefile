CC = gcc
CC_FLAGS = -lbsd -Wall -Wextra -std=c99

# temporary directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin
IMGDIR = img

# generate target name from enclosing folder
TARGET = $(BINDIR)/$(shell basename `readlink -f .`)

C_FILES = $(wildcard $(SRCDIR)/*.c)

all: $(TARGET)

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

