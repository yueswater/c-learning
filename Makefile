CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Positional args (make has no native params, parse via MAKECMDGOALS):
#   make 8 19      -> create ch08/prog08_19/prog08_19.c (dir + file, if missing)
#   make run 8 19  -> build (if needed) then run ch08/prog08_19/prog08_19
ARGS  := $(MAKECMDGOALS)
FIRST := $(word 1,$(ARGS))

ifeq ($(FIRST),run)
  A1 := $(word 2,$(ARGS))
  A2 := $(word 3,$(ARGS))
else
  A1 := $(word 1,$(ARGS))
  A2 := $(word 2,$(ARGS))
endif

# zero-pad numbers to 2 digits
CHNUM   := $(shell printf '%02d' $(A1) 2>/dev/null)
PROBNUM := $(shell printf '%02d' $(A2) 2>/dev/null)

CHDIR   := ch$(CHNUM)
NAME    := prog$(CHNUM)_$(PROBNUM)
SRC     := $(CHDIR)/$(NAME)/$(NAME).c
BIN     := $(CHDIR)/$(NAME)/$(NAME)

.PHONY: run clean $(sort $(A1) $(A2))

$(SRC):
	@mkdir -p $(dir $@)
	@[ -f $@ ] || printf '#include <stdio.h>\n\nint main(void)\n{\n    return 0;\n}\n' > $@
	@echo "created: $@"

$(BIN): $(SRC)
	$(CC) $(CFLAGS) -o $@ $<

ifeq ($(FIRST),run)
run: $(BIN)
	@./$(BIN)
$(sort $(A1) $(A2)):
	@:
else
# numeric goals trigger file creation via prerequisite
$(sort $(A1) $(A2)): $(SRC)
	@:
endif

clean:
	find . -type f -perm +111 ! -name '*.*' -path './ch*' -delete
