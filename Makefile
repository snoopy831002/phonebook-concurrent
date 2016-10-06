CC ?= gcc
CFLAGS_common ?= -Wall -std=gnu99
CFLAGS_orig = -O0
CFLAGS_opt  = -O0 -pthread -g -pg

ifdef THREAD
CFLAGS_opt  += -D THREAD_NUM=${THREAD}
endif

ifeq ($(strip $(DEBUG)),1)
CFLAGS_opt += -DDEBUG -g
endif

EXEC =  phonebook_opt1 phonebook_opt2 phonebook_opt4 phonebook_opt8 phonebook_opt16
all: $(EXEC)

SRCS_common = main.c

file_align: file_align.c
	$(CC) $(CFLAGS_common) $^ -o $@

phonebook_opt1: $(SRCS_common) phonebook_opt.c phonebook_opt.h
	$(CC) $(CFLAGS_common) $(CFLAGS_opt) \
		-DIMPL="\"phonebook_opt.h\"" -o $@ \
		-DTHREAD_NUM=1\
		$(SRCS_common) phonebook_opt.c threadpool.c threadpool.h

phonebook_opt2: $(SRCS_common) phonebook_opt.c phonebook_opt.h
	$(CC) $(CFLAGS_common) $(CFLAGS_opt) \
		-DIMPL="\"phonebook_opt.h\"" -o $@ \
		-DTHREAD_NUM=2\
		$(SRCS_common) phonebook_opt.c threadpool.c threadpool.h

phonebook_opt4: $(SRCS_common) phonebook_opt.c phonebook_opt.h
	$(CC) $(CFLAGS_common) $(CFLAGS_opt) \
		-DIMPL="\"phonebook_opt.h\"" -o $@ \
		-DTHREAD_NUM=4\
		$(SRCS_common) phonebook_opt.c threadpool.c threadpool.h

phonebook_opt8: $(SRCS_common) phonebook_opt.c phonebook_opt.h
	$(CC) $(CFLAGS_common) $(CFLAGS_opt) \
		-DIMPL="\"phonebook_opt.h\"" -o $@ \
		-DTHREAD_NUM=8\
                $(SRCS_common) phonebook_opt.c threadpool.c threadpool.h

phonebook_opt16: $(SRCS_common) phonebook_opt.c phonebook_opt.h
	$(CC) $(CFLAGS_common) $(CFLAGS_opt) \
		-DIMPL="\"phonebook_opt.h\"" -o $@ \
		-DTHREAD_NUM=16\
		$(SRCS_common) phonebook_opt.c threadpool.c threadpool.h

run: $(EXEC)
	echo 3 | sudo tee /proc/sys/vm/drop_caches
	watch -d -t "./phonebook_orig && echo 3 | sudo tee /proc/sys/vm/drop_caches"

cache-test: $(EXEC)
	perf stat --repeat 100 \
		-e cache-misses,cache-references,instructions,cycles \
		./phonebook_opt1
	perf stat --repeat 100 \
		-e cache-misses,cache-references,instructions,cycles \
		./phonebook_opt2
	perf stat --repeat 100 \
		-e cache-misses,cache-references,instructions,cycles \
		./phonebook_opt4
	perf stat --repeat 100 \
		-e cache-misses,cache-references,instructions,cycles \
		./phonebook_opt8
	perf stat --repeat 100 \
		-e cache-misses,cache-references,instructions,cycles \
		./phonebook_opt16


output.txt: cache-test calculate
	./calculate

plot: output.txt
	gnuplot scripts/runtime.gp

calculate: calculate.c
	$(CC) $(CFLAGS_common) $^ -o $@

.PHONY: clean
clean:
	$(RM) $(EXEC) *.o perf.* \
	      	calculate orig.txt opt.txt output.txt runtime.png file_align align.txt
