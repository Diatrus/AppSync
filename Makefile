ARCHS = arm64
TARGET = appletv
export GO_EASY_ON_ME=1
export SDKVERSION=10.1
TARGET = appletv:clang:10.1:10.1
SYSROOT = $(THEOS)/sdks/AppleTVOS10.1.sdk
DEBUG = 0

THEOS_PACKAGE_DIR_NAME = debs
PACKAGE_VERSION = $(THEOS_PACKAGE_BASE_VERSION)

include $(THEOS)/makefiles/common.mk

SUBPROJECTS += AppSyncUnified
SUBPROJECTS += postinst
SUBPROJECTS += preinst
SUBPROJECTS += asu_inject
include $(THEOS_MAKE_PATH)/aggregate.mk

clean::
	@rm -f debs/*.deb
