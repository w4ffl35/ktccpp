set shell := ["bash", "-euo", "pipefail", "-c"]

default:
    @just --list

setup:
    cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug

build:
    cmake --build build --parallel

test:
    @echo "No automated test suite is configured."

lint:
    cmake --build build --parallel

format:
    @echo "No repository formatter is configured."

typecheck:
    @echo "No separate C++ type checker is configured; compiler warnings are the gate."

run:
    test -x build/ktccpp
    build/ktccpp

clean:
    cmake --build build --target clean

docs:
    @echo "See README.md and AGENTS.md"

ci: setup build lint typecheck test
