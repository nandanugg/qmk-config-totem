init:
	sudo ln -s $(shell pwd)/totem ~/qmk_firmware/keyboards/
	qmk config user.keyboard=totem
compile:
	qmk compile -km default
flash-l:
	qmk flash -km default -bl uf2-split-left
flash-r:
	qmk flash -km default -bl uf2-split-right
