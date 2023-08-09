# var
MODULE = $(notdir $(CURDIR))

# dir
CWD = $(CURDIR)
BIN = $(CWD)/bin
TMP = $(CWD)/tmp

# src
F += lib/$(MODULE).ini

# all
.PHONY: all
all: $(BIN)/$(MODULE) $(F)
	$^

$(BIN)/$(MODULE): $(S) $(TMP)/$(MODULE)/Makefile
	$(MAKE) -C $(TMP)/$(MODULE)

$(TMP)/$(MODULE)/Makefile: $(S)
	cmake -B $(TMP)/$(MODULE) -S $(CWD) \
		-DAPP=$(MODULE) -DEXECUTABLE_OUTPUT_PATH=$(BIN)

# install
.PHONY: install update
install:
	$(MAKE) update
update:
	sudo apt update
	sudo apt install -yu `cat apt.dev apt.txt`
