
SRCS := $(wildcard *.c)
TARGET := a.out

${TARGET} : ${SRCS}
	gcc $^ -o $@

clean:
	rm ${TARGET}
