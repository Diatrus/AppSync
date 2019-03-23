ARCHS = arm64
TARGET = appletv
export GO_EASY_ON_ME=1
export SDKVERSION=10.1
TARGET = appletv:clang:10.1:10.1
SYSROOT = $(THEOS)/sdks/AppleTVOS10.1.sdk
include $(THEOS)/makefiles/common.mk

TOOL_NAME = asu_inject
asu_inject_FILES = asu_inject.c
asu_inject_CFLAGS += -fvisibility=hidden
asu_inject_INSTALL_PATH = /usr/bin
asu_inject_CODESIGN_FLAGS = -S../entitlements.xml
include $(THEOS_MAKE_PATH)/tool.mk
