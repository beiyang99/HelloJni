OUT_DIR = ../libs/x86

LOCAL_MODULE = libfone_core.so

CC = gcc

LDFLAGS = -shared 

SRC_DIR = src

INC_DIR = -Iinc_core -Iinc -Iinc_util

SRC_FILES = \
	$(SRC_DIR)/fn_debug.c\
	$(SRC_DIR)/dummy.c\
	$(SRC_DIR)/imyplayer-jni.c\
	$(SRC_DIR)/android_adapter_jni.c\
	$(SRC_DIR)/void_2_object.c\
	$(SRC_DIR)/void_2_object_fullplayer.c\
	$(SRC_DIR)/core_jni.c


$(LOCAL_MODULE): $(SRC_FILES)
	@$(CC) -o $(OUT_DIR)/$@ $(LDFLAGS) $(INC_DIR) $^
