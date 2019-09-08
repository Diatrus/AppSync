export TARGET = appletv
export ARCHS = arm64


include $(THEOS)/makefiles/common.mk

SUBPROJECTS += AppSyncUnified
SUBPROJECTS += postinst
include $(THEOS_MAKE_PATH)/aggregate.mk

after-install::
	install.exec "ldrestart"

clean::
	@rm -f packages/*.deb
