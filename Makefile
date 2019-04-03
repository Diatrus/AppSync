export ARCHS = arm64
export TARGET = appletv:clang:10.1:10.1
# export GO_EASY_ON_ME = 1
# export SDKVERSION = 10.1
export SYSROOT = $(THEOS)/sdks/AppleTVOS10.1.sdk
export FINALPACKAGE=1

# THEOS_PACKAGE_DIR_NAME = debs
# PACKAGE_VERSION = $(THEOS_PACKAGE_BASE_VERSION)

include $(THEOS)/makefiles/common.mk

SUBPROJECTS += AppSyncUnified
SUBPROJECTS += postinst
SUBPROJECTS += preinst
include $(THEOS_MAKE_PATH)/aggregate.mk

clean::
	@rm -f packages/*.deb
