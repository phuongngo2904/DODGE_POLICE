# DODGE_POLICE
# A fun game when users need to avoid multiple cars to earn as many score as possible

![Demo](https://user-images.githubusercontent.com/74227710/160935105-010250ff-09fc-4dbe-8608-e53061d491a6.mov)

# 1. Install brew on mac(or you can go to brew.sh to find the instruction)

### If you already installed brew, please ignore this step:
```
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```
### Install sfml
```
brew install sfml
```
* check the version
```
brew info sfml
```
# 2. Clone the project
* Make sure you have git installed by checking its version:
```
git --version 
```
* You can view your default Git configuration options with the following command:
```
git config -h
```
* Clone the project:
```
git clone https://github.com/phuongngo2904/DODGE_POLICE.git
```
* Navigate to this project 
```
cd DODGE_POLICE
```
# 3.  Install CMake
```
brew install cmake
```
# 4. Build the game
```
cmake -DCMAKE_BUILD_TYPE=DODGE_POLICE ./
make
```
# 5.Run the game
```
./DODGE_POLICE
```
