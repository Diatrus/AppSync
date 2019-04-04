export TARGET = appletv:clang:10.1:10.1
export ARCHS = arm64
export SYSROOT = $(THEOS)/sdks/AppleTVOS10.1.sdk
export THEOS_DEVICE_IP = 192.168.1.138
export FINALPACKAGE=1

# PACKAGE_VERSION = $(THEOS_PACKAGE_BASE_VERSION)
# THEOS_PACKAGE_DIR_NAME = debs

include $(THEOS)/makefiles/common.mk

TOOL_NAME = appinst
appinst_FILES = appinst.m $(wildcard zipzap/*.c) $(wildcard zipzap/*.cpp) $(wildcard zipzap/*.m) $(wildcard zipzap/*.mm)
appinst_CFLAGS += -std=c++11 -stdlib=libc++ -fobjc-arc -include ./zipzap/zipzap-Prefix.pch -I./zipzap -fvisibility=hidden -Wno-unused-property-ivar
appinst_FRAMEWORKS = Foundation ImageIO CoreGraphics
appinst_PRIVATE_FRAMEWORKS = MobileCoreServices
appinst_LIBRARIES = z
appinst_INSTALL_PATH = /usr/bin
appinst_CODESIGN_FLAGS = -Sappinst_entitlements.xml
include $(THEOS_MAKE_PATH)/tool.mk
