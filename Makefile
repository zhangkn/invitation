THEOS_DEVICE_IP=iphone150
TARGET = iPhone:latest:8.0
ARCHS = armv7 arm64
SRC = $(wildcard src/include/*.m)

include $(THEOS)/makefiles/common.mk

TWEAK_NAME = invitation
# 
invitation_FILES = Tweak.xm $(wildcard src/include/*.m) $(wildcard src/KNHookClass/*.m)

RedRobert_FRAMEWORKS = UIKit, Foundation
# -Werror -Wformat
invitation_CFLAGS += -Wno-error 
# invitation_CFLAGS += -I./src/include

include $(THEOS_MAKE_PATH)/tweak.mk

after-install::
	install.exec "killall -9 WeChat"
