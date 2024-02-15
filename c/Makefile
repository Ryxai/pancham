TARGET=endian
TARGET_VERSION=1.0

INSTALL_DIR := ../lib
CFLAGS := -Wall $(CFLAGS)
LDFLAGS := $(LDFLAGS)
MACHINE := $(shell $(CC) -dumpmachine)
ifneq (,$(findstring cygwin,$(MACHINE)))
	OS := windows
	SHLIB_SUFFIX := .dll
else ifneq (,$(findstring mingw, $(MACHINE)))
	OS := windows
	SHLIB_SUFFIX := .dll
else ifneq (,$(findstring windows, $(MACHINE)))
	OS := windows
	SHLIB_SUFFIX := .dll
else ifneq (,$(findstring darwin, $(MACHINE)))
	OS := darwin
	SHLIB_SUFFIX := .dylib
else ifneq (,$(findstring bsd, $(MACHINE)))
	OS := bsd
	SHLIB_SUFFIX := .so
else
	OS := linux
	SHLIB_SUFFIX := so
endif

ifneq ($(OS),windows)
	CFLAGS += -fPIC
endif

SUPPORTLIB := endian${SHLIB_SUFFIX}
SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)

ifneq ($(OS),darwin)
	COMPILECMD := $(CC) -dynamiclib -o $(SUPPORTLIB) $(OBJS) $(LDFLAGS)
else
	COMPILECMD := $(CC) -shared -o $(SUPPORTLIB) $(OBJS) $(LDFLAGS)
endif

all: $(TARGET)

$(TARGET): $(OBJS)
	echo "$(VAR)"
	$(COMPILECMD)

.PHONY : clean install

clean:
	rm  -f $(OBJS) $(TARGET) $(SUPPORTLIB)
	rm -rf  $(INSTALL_DIR)

install:
	mkdir -p $(INSTALL_DIR)
	install $(SUPPORTLIB) $(INSTALL_DIR)

