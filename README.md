FRT
===

FRT is a Godot "platform" targeting single board computers.

## Usage (Raspberry Pi running raspbian)

FRT does not need X11 to run, and should also run on raspbian lite.

Make sure that you have increased the amount of memory for the GPU.
Some demos work with just the default 64M reserved for the GPU, but most
of them will need more.

Download, uncompress, install somewhere in your path one binary from
here:

[https://sourceforge.net/projects/frt/files](https://sourceforge.net/projects/frt/files)

For example:

	$ unzip frt_093_214_pi1.bin.zip
	$ sudo install frt_093_214_pi1.bin /usr/local/bin

Download and uncompress the latest archive from here:

[https://downloads.tuxfamily.org/godotengine/demos/2.1](https://downloads.tuxfamily.org/godotengine/demos/2.1)

Run a demo:

	$ cd Godot-Demos-2.1.4-stable/2d/platformer
	$ frt_093_214_pi1.bin -v

Press *Win+Q* to quit.

This is the list of meta (Win) keys recognized by FRT.

| Meta  | Action |
| :---: | :--- |
| *Q* | *Quit* |
| F | Toggle fullscreen |
| W | Change window gravity |
| K | Grab / ungrab the keyboard |
| M | Grab / ungrab the mouse |
| Return | Mouse Left Button (virtual mouse) |
| Cursor Keys | Mouse Motion (virtual mouse) |

The virtual mouse keys are available only if a keyboard is found, but a
mouse is not.

## More Info

- [Usage](doc/Usage.md)
- [Extensions](doc/Extensions.md)
- [Compile](doc/Compile.md)
- [Porting](doc/Porting.md)
