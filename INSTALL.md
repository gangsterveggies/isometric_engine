To build and use the demo of the engine you need SDL and CMAKE installed.


## Building on GNU/Linux

Follow these steps to build and run the demo:

```
git clone git@github.com:gangsterveggies/isometric_engine.git
cd isometric_engine
git submodule init
git submodule update
cmake .
make
./isoengine
```

You can run 'make install' with root privileges to install the project
globally, but doing so is not recommended.
