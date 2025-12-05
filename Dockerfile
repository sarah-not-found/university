FROM gcc:11-bullseye

RUN apt update \
&&  apt install -y gdb \
&&  apt purge -y valgrind \
&&  apt clean
ADD https://sourceware.org/pub/valgrind/valgrind-3.20.0.tar.bz2 /tmp/valgrind-3.20.0.tar.bz2
WORKDIR /src
RUN tar --strip-components=1 -x -f /tmp/valgrind-3.20.0.tar.bz2 \
    && ./configure \
    && make \
    && make install \
    && rm -f /tmp/valgrind-3.20.0.tar.bz2
WORKDIR /
