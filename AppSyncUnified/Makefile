include $(THEOS)/makefiles/common.mk

TWEAK_NAME = AppSyncUnified
AppSyncUnified_FILES = AppSyncUnified.x dump.cpp
AppSyncUnified_CFLAGS += -fvisibility=hidden -Wno-unused-private-field
AppSyncUnified_LIBRARIES = substrate
AppSyncUnified_CODESIGN_FLAGS = -S../entitlements.xml
include $(THEOS_MAKE_PATH)/tweak.mk
