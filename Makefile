KEYBOARD_DEST := $$HOME/qmk_firmware/keyboards/totem

init:
	@ln -sfn $(shell pwd)/totem $(KEYBOARD_DEST)
	qmk config user.keyboard=totem
compile:
	qmk compile -km default
flash-l:
	qmk flash -km default -bl uf2-split-left
flash-r:
	qmk flash -km default -bl uf2-split-right
