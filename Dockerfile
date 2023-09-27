FROM ubuntu AS build

RUN apt-get update && \
	apt-get install -y build-essential git cmake autoconf libtool pkg-config

WORKDIR /src

COPY CMakeLists.txt main.cpp ./

RUN cmake . && make

FROM ubuntu

WORKDIR /opt/Test_CPP_docker

COPY --from=build /src/Test_CPP_docker ./

RUN chmod +x ./Test_CPP_docker

CMD ["./Test_CPP_docker"]