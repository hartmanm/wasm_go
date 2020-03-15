# wasm_go

bash wasm_go <target file> <second parameter to install else install will be skipped>

---


- example: bash wasm_go hello.c

- install example: bash wasm_go hello.c install

- so long as target file is unique and located in a subdirectory below wasm_go, it will be found.

- wasm_go is an emscripten wrapper with mods to make it easier to use with WASM!
- Easily compile and launch a c or cpp program for WASM and launch it in the browser.
- Note: input is not handled correctly, along with many other potential problems.
- OPTIMIZATION_LEVEL is hardcoded in the script to the lowest level, change it to 3 for the highest optimization.
- The html interface has been cleaned up and many of the annoying potential issues are avoided by automation.
- Minor modifications to files to do things like: make chrome the default browser (it can utilize your GPU with WASM).

- a hello WASM example c program (hello.c) and simple example cpp program (out.cpp) are included for testing:

- after running with install then:
- bash wasm_go hello.c
- bash wasm_go out.cpp
- bash wasm_go pal.cpp
