# ========================================================
# libefence.so
# ========================================================

LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := libefence
LOCAL_MODULE_TAGS := eng debug

LOCAL_SRC_FILES := efence.c page.c print.c new.c

LOCAL_CFLAGS := \
	-g \
	-DUSE_SEMAPHORE \
	-DDYNAMIC_LIB \
	-fvisibility=hidden \
	-DANDROID \
	$(libc_common_cflags)

LOCAL_C_INCLUDES := $(libc_common_c_includes) bionic/libc

LOCAL_SHARED_LIBRARIES := libc
LOCAL_WHOLE_STATIC_LIBRARIES := libc_common
LOCAL_SYSTEM_SHARED_LIBRARIES :=
LOCAL_ALLOW_UNDEFINED_SYMBOLS := true


include $(BUILD_SHARED_LIBRARY)
