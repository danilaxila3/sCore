### This project is incomplete

i'm still working on most commands. more features are to come out later

<center>
  <h1>sCore</h1>
  a simple coreutils alternative
</center>

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
