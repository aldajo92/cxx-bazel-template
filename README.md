# cxx-bazel-template

Bazel test compiling C++ "Hello World" and google test suite

## Initialize

Build the docker image by running the following inside the root dir of the repo:

~~~bash
./scripts/build
~~~

Execute the image

~~~bash
./scripts/run
~~~

Open a new bash terminal (if it is needed):
~~~bash
./scripts/bash
~~~

## Initialize with Docker Compose (alternative)

Build the docker image by running the following inside the root dir of the repo:

~~~bash
docker compose up -d
~~~

Jump into the container by running the following command in a new terminal:

~~~bash
docker exec -it bazel-test bash
~~~

## Building

Compile the hello_world program by running the following command on the /workspace

~~~bash
bazel build //main:hello_world
~~~

Compile the test program by running the following command on the /workspace

~~~bash
bazel build //test:hello_world_test
~~~

or simple use

~~~bash
bazel build //...
~~~

## Running

Run the hello_world program by running the following command on the /workspace

~~~bash
./bazel-bin/main/hello_world
~~~

Run the test program by running the following command on the /workspace

~~~bash
./bazel-bin/test/hello_world_test
~~~

## Utils

The following bazel args can be useful:

~~~bash
# clean de workspace
bazel clean --expunge
#  re-fetch the dependencies
bazel fetch //...
# refresh bazel workspace
bazel sync
~~~


## License

MIT
