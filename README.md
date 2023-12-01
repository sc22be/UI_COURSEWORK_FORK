# User Interfaces
The project is to create a beReal spoof, but for videos.

## Running the code:
### Codecs
#### macos:
- install codec

#### Linux: 
Install gstreamer(needs plugins-good to run so can only install that depending on package manager)
```bash
zypper/dnf/pacman/apt install gstreamer
```
#### Windows:
... idk

### Qt
Install Qt Creator with Qt 5.15
When running the code run from the file VideoPlayer.pro

## Contrubuting:
- Kanban link: https://trello.com/b/F56Kiy3C/user-interfaces-board
- Please create a branch for each feature you are working on
- Pull requests are welcome for when you are done with a feature
- Create an issue if you find a bug

### Help with git:
#### Commands to use:
```bash
git init # initialize git
git add remote origin <link> # link with ssh or https
git pull origin <branch> # pull from branch
git checkout <branch> # switch to branch
git checkout -b <branch> # create branch and switch to it
git branch # list branches
git add <file> # add file to commit (can use . to add all files)
git commit -m "message" # commit changes
git push origin <branch> # push to branch
```
### Merging:
- Create a pull request on github and someone else will review it  
- Don't Push to main
