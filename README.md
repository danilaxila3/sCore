### This project is incomplete

i'm still working on most commands. more features are to come out later

<h1 align="center">sCore</h1>
<p align="center">a simple coreutils alternative</p>

# About

sCore is a solo project written in C containing commands for basic system manipulation (managing files and dirs, environment variables, etc)\
i mean, it has cool icons and colors, what else do you need to be happy??

# Compiling

requirements: gcc, make

```bash
git clone https://github.com/danilaxila3/sCore.git
cd sCore
make
```

you can also add the `bin` folder to `$PATH` with:

```bash
echo 'export PATH=$PATH:$(pwd)/bin' >> ~/.bashrc
source .bashrc
```

replace .bashrc with whatever shell you use
