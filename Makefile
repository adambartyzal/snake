
#CC:=ccache $(CC)
CFLAGS+=-O0

OBJS=$(patsubst %.c,%.o,$(wildcard *.c))

CFLAGS+=-std=c99 -pedantic -Wall -g

CFLAGS+=$(shell sdl2-config --cflags)
LDFLAGS+=$(shell sdl2-config --libs)

LDFLAGS += -lcurses

TARGET=snake

bin: $(TARGET)

$(OBJS): %.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@

clean:
	$(RM) $(OBJS) $(TARGET)
	$(RM) -rf *.ppm *.jpg *.img

