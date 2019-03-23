ARCHS = arm64
TARGET = appletv
export GO_EASY_ON_ME=1
export SDKVERSION=10.1
TARGET = appletv:clang:10.1:10.1
SYSROOT = $(THEOS)/sdks/AppleTVOS10.1.sdk
include $(THEOS)/makefiles/common.mk

TOOL_NAME = preinst prerm

preinst_FILES = preinst.c
preinst_CFLAGS += -fvisibility=hidden -Dpreinst
preinst_FRAMEWORKS = CoreFoundation
preinst_INSTALL_PATH = /DEBIAN
preinst_CODESIGN_FLAGS = -S../entitlements.xml

prerm_FILES = preinst.c
prerm_CFLAGS += -fvisibility=hidden
prerm_FRAMEWORKS = CoreFoundation
prerm_INSTALL_PATH = /DEBIAN
prerm_CODESIGN_FLAGS = -S../entitlements.xml

include $(THEOS_MAKE_PATH)/tool.mk
