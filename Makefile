init:
	sudo ln -s $(pwd)/totem ~/qmk_firmware/keyboards/
	qmk config user.keyboard=totem
compile-l:
	qmk compile -km default
compile-r:
	qmk compile -km default
flash-l:
	qmk flash -km default -bl uf2-split-left
flash-r:
	qmk flash -km default -bl uf2-split-right
