ARCHS = arm64
TARGET = appletv
export GO_EASY_ON_ME=1
export SDKVERSION=10.1
TARGET = appletv:clang:10.1:10.1
SYSROOT = $(THEOS)/sdks/AppleTVOS10.1.sdk
include $(THEOS)/makefiles/common.mk

TWEAK_NAME = AppSyncUnified
AppSyncUnified_FILES = AppSyncUnified.x dump.cpp
AppSyncUnified_CFLAGS += -fvisibility=hidden -Wno-unused-private-field
AppSyncUnified_LIBRARIES = substrate
include $(THEOS_MAKE_PATH)/tweak.mk
