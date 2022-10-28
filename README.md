# Blender++
A multi-purpose free and open-source application that aims to (eventually) be a complete software suite which will replace all software on your computer except for your operating system and drivers. It's like a neat little toolbox that you can take apart and tinker with, just like the [Blender](https://www.blender.org/) project.

## Platforms this project plans to support
We plan on world dominance. We **plan** to support Windows, macOS, Linux, Android, iOS, watchOS, tvOS, iPadOS, Java VM, Python, and cloud-based JavaScript (aka Live).

The ports for Windows and Linux are in this branch. The appropriate branch is linked for every other port.

### Windows (branch 'cpp')
* **Build method:** [`scripts/build.windows.bat`](https://github.com/HackerDaGreat57/bpp/blob/main/scripts/build.windows.bat)
* **Supported architecture(s):** `x86-64`, `x86-32`, `arm64`, `IA-64`
* **Supported version(s):** Aiming for compatibility with Windows 2000 Professional (no Service Pack)

### Linux (branch 'cpp')
Currently not supported, but planned. This version will be based on the Windows version codebase with some slight Linux-specific differences. Different versions for DEB/RPM/Generic Linux will be released. We need help!

### Apple Devices (branch 'macos', 'ios', 'ipados', 'watchos', 'tvos')
macOS, iOS, iPadOS, watchOS, and tvOS versions will all be based on Swift/SwiftUI (backend/frontend). No renderer options - only SwiftUI will be supported.

I have no Apple devices other than a 1st-generation iPhone SE and a 1st-generation Apple Watch, so this is mostly blank at the moment. If you want to help set up Apple ports, [go right ahead](https://github.com/HackerDaGreat57/bpp/pulls).

### Java (branch 'java')
This port will work wherever OpenJDK 1.19 works, using JavaFX/Swing/AWT/(OpenGL/Vulkan via `lwjgl3`) for the GUI. Under development.

### Python (branch 'python')
Since Python is relatively slow and memory-intensive this implementation's purpose will mainly just be programming reference for other python-based applications. Will brainstorm user interface methods when we get to making this one.

### Android (branch 'android')
Under development.

### Online (branch 'live')
This version is currently being developed.

*Blender++ Live* is written in JavaScript and React, and will match the feature set of all other versions. This port is meant for giving you a taste of Blender++ before you download, but it can be used as an online replacement (except it will exclude low-level utilities like hardware management etc).

## Update Order
Since it's impossible to develop every version of this application at the same time, different versions of the app will be updated at different times.
1. Cloud-based version will be updated first. We are in the era of people who want easy-to-use cloud-based solutions and services with fast updates.
2. Java VM
3. Apple Devices
4. Android
5. Windows/Linux
6. Python

## Current state of the project/development status
You can view Blender++'s [GitHub Project](https://github.com/users/HackerDaGreat57/projects/2).

I'm sorry for trying to ditch GitHub, my friends. **The Gitea migration has been canceled.**

## Development
### Process
1. Clone the repository
2. Write or improve code
3. Compile (if applicable) & test **thoroughly** to make sure your stuff works
4. Add binaries and residue files (configuration files generated by build systems for example) to the [`.gitignore`](https://github.com/HackerDaGreat57/bpp/blob/main/.gitignore), if there are new binaries and residues that aren't already ignored
5. Make a [Pull Request](https://github.com/HackerDaGreat57/bpp/pulls). Only trusted Collaborators will have push access to the repository, and everyone else always has Pull Request permissions.

### Map
I use [Visual Studio Code](https://github.com/microsoft/vscode) to edit the source code of the program, mainly because VS Code is the only editor apart from the real Visual Studio that has built-in IntelliSense (or some kind of extension for it). There is an [extention](https://github.com/wk-j/vscode-save-and-run) I have installed in VS Code that runs a Task every time my source code file is saved. That Task runs a Windows Batch File or Linux Shell Script that is responsible for setting up the build and calling GCC.

Since all the code of the program is in one file, I used a [bookmarks extention](https://github.com/alefragnani/vscode-bookmarks) as well. It is configured to store bookmarks in [`.vscode/bookmarks.json`](https://github.com/HackerDaGreat57/bpp/blob/main/.vscode/bookmarks.json).

## Why did you create this project?
This application is meant to replace all the overpriced proprietary software out there that doesn't give you any freedom. I believe that computer software was meant to be free and open, and some people from 1969 ([yes, literally](https://en.wikipedia.org/wiki/Proprietary_software#Origin)) decided to unnecessarily make it a standard to close and monetize it. I know we all have to make a buck or two, but I really don't think software is the way to do that. You're telling me I'm supposed to pay $799 for a laptop computer and still have to pay for the software running on it? No way!

My stance on proprietary software is exactly the opposite of Bill Gates' opinion, including the hint of anger. Microsoft Windows and Apple's operating systems are the only exceptions to my hate, but that's only because over 60% of the world's personal computers are running them. And still I feel that there is injustice done to us due to having to pay $130+ for the most popular desktop operating system in the world. So that's why. In the digital world, I don't want you to pay for anything more than your physical computer and maybe its operating system.

## The history of this project
I have wanted to build this app since 2019, but I never found enough time to do so until now.
