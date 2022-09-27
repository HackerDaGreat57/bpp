# Blender++
A *somewhat experimental* C++ application. The project was created in order to let people have the freedom to do whatever they want, with no limitations or restrictions, without having to pay a single penny to anyone. But this will only happen once it gets mature enough to actually make a difference. There's a long, **long** way to go until we reach that checkpoint, but I'm just doing what I can for now.

The above parahgraph basically states that this is a project that will do **anything**.

## Platforms this project supports
### Windows
* **Build method:** [`scripts/build.windows.bat`](https://github.com/HackerDaGreat57/bpp/blob/main/scripts/build.windows.bat)
* **Supported architecture(s):** `x86-64`

### Linux
* **Build method:** [`scripts/build.debian.linux.sh`](https://github.com/HackerDaGreat57/bpp/blob/main/scripts/build.debian.linux.sh)
* **Supported architecture(s):** `x86-64`
* **Supported distro(s):** Ubuntu/Debian

### Apple Macintosh
I currently do not have proper access to a physical Mac device. Please create a [Pull Request](https://github.com/HackerDaGreat57/bpp/pulls) if you can. Until we get proper Mac support, I will be 'blind coding' by using [Apple's Metal-C++ Documentation](https://developer.apple.com/metal/cpp/) without testing it. This might be stupid but it could give us a head start on something.

## Current state of the project/development status
You can view Blender++'s [GitHub Project](https://github.com/users/HackerDaGreat57/projects/2).

I would also like to point out that I will be traveling to a place without Internet connection on September 14, and I will have time to code only after October 19 since I'll have lots of stuff to catch up on in the rest of my life. **There may be low activity during this time**, however I might get some time here and there to pitch in once in a while.

I'm sorry for trying to ditch GitHub, my friends. **The Gitea migration has been canceled.**

## Development
### Process
1. Clone the repository
2. Write code (lol)
3. Compile & test **thoroughly** to make sure your stuff works
4. Add binaries to [`.gitignore`](https://github.com/HackerDaGreat57/bpp/blob/main/.gitignore), if there are new binaries that aren't already ignored
5. Make a [Pull Request](https://github.com/HackerDaGreat57/bpp/pulls). Only trusted Collaborators will have push access to the repository, and everyone else always has Pull Request permissions.

### Map
I use [Visual Studio Code](https://github.com/microsoft/vscode) to edit the source code of the program, mainly because VS Code is the only editor apart from the real Visual Studio that has built-in IntelliSense. There is an [extention](https://github.com/wk-j/vscode-save-and-run) I have installed in VS Code that runs a Task every time my source code file is saved. That Task runs a Windows Batch File that is responsible for setting up the build and calling GCC.

Since all the code of the program is in one file, I used a [bookmarks extention](https://github.com/alefragnani/vscode-bookmarks) as well. It is configured to store bookmarks in [`.vscode/bookmarks.json`](https://github.com/HackerDaGreat57/bpp/blob/main/.vscode/bookmarks.json).

## Why did you create this project?
This application is meant to replace all the overpriced proprietary software out there that doesn't give you any freedom. I believe that computer software was meant to be free and open, and some desperate people from 1969 ([yes, literally](https://en.wikipedia.org/wiki/Proprietary_software#Origin)) decided to unnecessarily close and monetize it. I know we all have to make a buck or two, but I really don't think software is the way to do that.

My stance on proprietary software is exactly the opposite of Bill Gates' opinion, including the hint of anger. Microsoft Windows and Apple's operating systems are the only exceptions, but even that's only because over 60% of the world's personal computers are running them.

## The history of this project
If you look at the 41 repositories I currently have, they are either forks or baseless claims of greatness. These are the products of me not having enough time to work on them properly, but now that summer is over and my teachers are giving less homework I am able to actually get somewhere. I have wanted to build this app since 2019, but I never found enough time to do so until now.
