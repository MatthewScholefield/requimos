# Requimos
To move use the WASD keys. You must strategically avoid the orange enemies in this fast-paced game. If two enemies collide, they both die. However, the same applies to your own player, the blue square.

![Screenshot][screenshot]

# Build instructions
Here's an overview of what needs to be done:
 - Install SFML library
 - Install build tools (`make` and `g++`)
 - Build Requimos with `make`

More detailed instructions are below.
## Step one
First download Requimos's source code to a directory. (From the command line: `git clone https://github.com/Wolfgange3311999/requimos.git`)

Continue to the header below according to your OS.
### Linux
 - [Install the latest SFML][sfml-linux]
 - Ensure you have build tools installed (`make` and `g++`) with your package manager (for Ubuntu, `sudo apt-get install build-essential`)
 - Build Requimos by executing `make` in the source directory

Finished! (See the [`Running Requimos`][running-requimos] section below)

### Windows
*If you get confused or something goes wrong you can [contact me][contact] or try applying [this build tutorial][sfml-build-tutorial] to Requimos. If using that link, make sure to only use the `Configuring your SFML build` section and ignore things that don't make sense in the context of Requimos.*

 - [Install the latest SFML][sfml-windows] (Choose the header under `Getting started` that applies to you)
 - Install the MinGW version that matches your SFML download
 - Open up a terminal window with access to bash (included with MinGW) and run `make`
Finished! (See the [`Running Requimos`][running-requimos] section below)

# Running Requimos
After compiling the project, the executable should work as is and resides in the `assets` folder of Requimos's source. Currently, the game will crash if run without the assets in the same directory.

# Problem Compiling?
Try importing Requimos into NetBeans and configuring your project library include directories and linker library directories.

# Contact
Any questions about Requimos?
Contact me at [matthew3311999@gmail.com](mailto://matthew3311999@gmail.com) or file an issue in the issue tracker.

[sfml-linux]:http://www.sfml-dev.org/tutorials/2.3/start-linux.php
[contact]:https://github.com/Wolfgange3311999/requimos#contact
[running-requimos]:https://github.com/Wolfgange3311999/requimos#running-requimos
[sfml-build-tutorial]:http://www.sfml-dev.org/tutorials/2.0/compile-with-cmake.php#configuring-your-sfml-build
[sfml-windows]:http://www.sfml-dev.org/tutorials/2.3/#getting-started
[screenshot]:http://i.imgbox.com/ffSSgomj.jpg
