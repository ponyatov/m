.PHONY: install update
install:
	$(MAKE) update
update:
	sudo apt update
	sudo apt install -yu `cat apt.dev apt.txt`
