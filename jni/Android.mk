LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := hello
LOCAL_SRC_FILES := src/imyplayer-jni.c src/core_jni.c

LOCAL_LDLIBS += -llog

LOCAL_C_INCLUDES := $(LOCAL_PATH)/inc_util $(LOCAL_PATH)/inc

include $(BUILD_SHARED_LIBRARY)


