include ../Makefiles/default_var.mk
NAME := libui.a
BLACK_LIST_SRCS +=
TEST_SRCS := src/test.c
CFLAGS += -D_REENTRANT -g -flto -O3

ifeq ($(UNAME), Darwin)
LDLIBS += $(PACKAGE_MANAGER_LIB)/libSDL2.dylib $(PACKAGE_MANAGER_LIB)/libSDL2_ttf.dylib $(PACKAGE_MANAGER_LIB)/libSDL2_mixer.dylib $(PACKAGE_MANAGER_LIB)/libSDL2_image.dylib $(PACKAGE_MANAGER_LIB)/libSDL2_net.dylib
else ifeq ($(UNAME), Linux)
LDLIBS += $(PACKAGE_MANAGER_LIB)/libSDL2.so $(PACKAGE_MANAGER_LIB)/libSDL2_ttf.so $(PACKAGE_MANAGER_LIB)/libSDL2_mixer.so $(PACKAGE_MANAGER_LIB)/libSDL2_image.so $(PACKAGE_MANAGER_LIB)/libSDL2_net.so
endif

include ../Makefiles/lib.mk

ifeq ($(UNAME), Darwin)

$(PACKAGE_MANAGER_LIB)/libSDL2_net.dylib:
	$(PACKAGE_MANAGER) install SDL2_net
	touch $(PACKAGE_MANAGER_LIB)/libSDL2_net.dylib
$(PACKAGE_MANAGER_LIB)/libSDL2.dylib:
	$(PACKAGE_MANAGER) $(PACKAGE_MANAGER_INSTALL_ARGUMENT) $(SDL2_NAME)
	touch $(PACKAGE_MANAGER_LIB)/libSDL2.dylib
$(PACKAGE_MANAGER_LIB)/libSDL2_ttf.dylib:
	$(PACKAGE_MANAGER) $(PACKAGE_MANAGER_INSTALL_ARGUMENT) $(SDL2_TTF_NAME)
	touch $(PACKAGE_MANAGER_LIB)/libSDL2_ttf.dylib
$(PACKAGE_MANAGER_LIB)/libSDL2_mixer.dylib:
	$(PACKAGE_MANAGER) $(PACKAGE_MANAGER_INSTALL_ARGUMENT) $(SDL2_MIXER_NAME)
	touch $(PACKAGE_MANAGER_LIB)/libSDL2_mixer.dylib
$(PACKAGE_MANAGER_LIB)/libSDL2_image.dylib:
	$(PACKAGE_MANAGER) $(PACKAGE_MANAGER_INSTALL_ARGUMENT) $(SDL2_IMAGE_NAME)
	touch $(PACKAGE_MANAGER_LIB)/libSDL2_image.dylib

else ifeq ($(UNAME), Linux)

$(PACKAGE_MANAGER_LIB)/libSDL2.so:
	$(PACKAGE_MANAGER) $(PACKAGE_MANAGER_INSTALL_ARGUMENT) $(SDL2_NAME)

$(PACKAGE_MANAGER_LIB)/libSDL2_ttf.so:
	$(PACKAGE_MANAGER) $(PACKAGE_MANAGER_INSTALL_ARGUMENT) $(SDL2_TTF_NAME)

$(PACKAGE_MANAGER_LIB)/libSDL2_mixer.so:
	$(PACKAGE_MANAGER) $(PACKAGE_MANAGER_INSTALL_ARGUMENT) $(SDL2_MIXER_NAME)

$(PACKAGE_MANAGER_LIB)/libSDL2_image.so:
	$(PACKAGE_MANAGER) $(PACKAGE_MANAGER_INSTALL_ARGUMENT) $(SDL2_IMAGE_NAME)

$(PACKAGE_MANAGER_LIB)/libSDL2_net.so:
	$(PACKAGE_MANAGER) $(PACKAGE_MANAGER_INSTALL_ARGUMENT) $(SDL2_NET_NAME)

else

SDL2-2.0.9/build/libSDL2.dylib:
	echo "non OSX or non linux+pacman are not supported for now"

endif
