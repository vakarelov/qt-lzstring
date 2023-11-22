
# LZString
Qt implementation of LZ-String as an executable

Based on the LZ-String compression algorithm found here:  
http://pieroxy.net/blog/pages/lz-string/index.html

## Installation

### Prerequisites

Before installing lzstring, you need to ensure that Qt5 is installed on your system.
Use the following commands to install Qt5:

#### For Debian/Ubuntu based systems:

```shell
sudo apt-get update
sudo apt-get install qt5-default qtbase5-dev-tools qtchooser qt5-qmake qtbase5-dev
```

#### For Fedora systems:

```shell
sudo dnf install qt5 qt5-qtbase-devel
```

### Compiling lzstring

Once Qt5 is installed, you can compile lzstring with `qmake` and `make`.

Clone the repository and navigate into the directory:

```shell
git clone https://github.com/vakarelov/lzstring.git
cd lzstring
```

Use `qmake` to create the Makefile:

```shell
qmake
```

Now compile the project using `make`:

```shell
make
```

The `lzstring` executable will be generated in the current directory.

## Usage

To use `lzstring`, you can either specify input and output files or use standard input and output to work with pipes.

### Use Cases

_Compress a file to LZ-String format:_

```shell
./lzstring --compress input.txt output.lz
```

_Compress a file to LZ-String format with UTF-16 encoding:_

```shell
./lzstring --compressToUTF16 input.txt output.lz16
```

_Compress a file to Base64 encoded LZ-String format:_

```shell
./lzstring --compressToBase64 input.txt output.lz64
```

_Decompress from LZ-String format to original text:_

```shell
./lzstring --decompress input.lz output.txt
```

_Decompress from UTF-16 encoded LZ-String format:_

```shell
./lzstring --decompressFromUTF16 input.lz16 output.txt
```

_Decompress from Base64 encoded LZ-String format:_

```shell
./lzstring --decompressFromBase64 input.lz64 output.txt
```

_Working with pipes, compress to LZ-String format:_

```shell
cat input.txt | ./lzstring --compress - -
```

_Working with pipes, decompress from LZ-String format:_

```shell
cat input.lz | ./lzstring --decompress - -
```

_Note: Replace `-` with file paths to work with files or use `-` for both input and output to use standard input and output._

## License

This project is licensed under the [WTFPL License](http://www.wtfpl.net/).
```

