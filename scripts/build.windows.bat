::Build Blender++ for Windows
setlocal enableextensions enabledelayedexpansion
cd /D %BPP_ROOT%

mkdir bin
cd bin
mkdir x86_64
mkdir x86_64_v2
mkdir x86_64_v3
mkdir x86_64_v4
mkdir pentium
mkdir lakemont
mkdir pentium_mmx
mkdir pentiumpro
mkdir pentium2
mkdir pentium3
mkdir pentium3m
mkdir pentium_m
mkdir pentium4
mkdir pentium4m
mkdir prescott
mkdir nocona
mkdir core2
mkdir nehalem
mkdir westmere
mkdir sandybridge
mkdir ivybridge
mkdir haswell
mkdir broadwell
mkdir skylake
mkdir bonnell
mkdir silvermont
mkdir goldmont
mkdir goldmont_plus
mkdir tremont
mkdir knl
mkdir knm
mkdir skylake_avx512
mkdir cannonlake
mkdir icelake_client
mkdir icelake_server
mkdir cascadelake
mkdir cooperlake
mkdir tigerlake
mkdir sapphirerapids
mkdir alderlake
mkdir rocketlake
mkdir k6
mkdir k6_2
mkdir k6_3
mkdir athlon
mkdir athlon_tbird
mkdir athlon_4
mkdir athlon_xp
mkdir athlon_mp
mkdir k8
mkdir opteron
mkdir athlon64
mkdir athlon_fx
mkdir k8_sse3
mkdir opteron_sse3
mkdir athlon64_sse3
mkdir barcelona
mkdir bdver1
mkdir bdver2
mkdir bdver3
mkdir bdver4
mkdir znver1
mkdir znver2
mkdir znver3
mkdir btver1
mkdir btver2

xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/x86_64/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/x86_64_v2/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/x86_64_v3/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/x86_64_v4/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/pentium/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/lakemont/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/pentium_mmx/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/pentiumpro/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/pentium2/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/pentium3/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/pentium3m/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/pentium_m/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/pentium4/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/pentium4m/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/prescott/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/nocona/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/core2/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/nehalem/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/westmere/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/sandybridge/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/ivybridge/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/haswell/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/broadwell/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/skylake/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/bonnell/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/silvermont/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/goldmont/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/goldmont_plus/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/tremont/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/knl/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/knm/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/skylake_avx512/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/cannonlake/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/icelake_client/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/icelake_server/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/cascadelake/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/cooperlake/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/tigerlake/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/sapphirerapids/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/alderlake/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/rocketlake/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/k6/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/k6_2/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/k6_3/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/athlon/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/athlon_tbird/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/athlon_4/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/athlon_xp/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/athlon_mp/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/k8/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/opteron/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/athlon64/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/athlon_fx/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/k8_sse3/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/opteron_sse3/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/athlon64_sse3/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/barcelona/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/bdver1/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/bdver2/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/bdver3/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/bdver4/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/znver1/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/znver2/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/znver3/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/btver1/" /f /g /y /h /u
xcopy "%BPP_COMPILER%/mingw64/bin/*.dll" "%BPP_ROOT%/bin/btver2/" /f /g /y /h /u

cd %BPP_ROOT%
mkdir obj
cd obj
mkdir x86_64
mkdir x86_64_v2
mkdir x86_64_v3
mkdir x86_64_v4
mkdir pentium
mkdir lakemont
mkdir pentium_mmx
mkdir pentiumpro
mkdir pentium2
mkdir pentium3
mkdir pentium3m
mkdir pentium_m
mkdir pentium4
mkdir pentium4m
mkdir prescott
mkdir nocona
mkdir core2
mkdir nehalem
mkdir westmere
mkdir sandybridge
mkdir ivybridge
mkdir haswell
mkdir broadwell
mkdir skylake
mkdir bonnell
mkdir silvermont
mkdir goldmont
mkdir goldmont_plus
mkdir tremont
mkdir knl
mkdir knm
mkdir skylake_avx512
mkdir cannonlake
mkdir icelake_client
mkdir icelake_server
mkdir cascadelake
mkdir cooperlake
mkdir tigerlake
mkdir sapphirerapids
mkdir alderlake
mkdir rocketlake
mkdir k6
mkdir k6_2
mkdir k6_3
mkdir athlon
mkdir athlon_tbird
mkdir athlon_4
mkdir athlon_xp
mkdir athlon_mp
mkdir k8
mkdir opteron
mkdir athlon64
mkdir athlon_fx
mkdir k8_sse3
mkdir opteron_sse3
mkdir athlon64_sse3
mkdir barcelona
mkdir bdver1
mkdir bdver2
mkdir bdver3
mkdir bdver4
mkdir znver1
mkdir znver2
mkdir znver3
mkdir btver1
mkdir btver2

cd %BPP_COMPILER%/mingw64/bin
if exist libboost_atomic-mt.dll (
  echo Libraries already installed.
) else (
  pacman -S mingw-w64-x86_64-toolchain --noconfirm
  pacman -S mingw-w64-x86_64-glfw --noconfirm
  pacman -S mingw-w64-x86_64-ncurses --noconfirm
  pacman -S mingw-w64-x86_64-boost --noconfirm
  pacman -Syuu
)

cd %BPP_ROOT%

::Number of cores is divided by 2 for keeping the system responsive/preventing Intel Hyperthreading to confuse us
set /A b = %NUMBER_OF_PROCESSORS%/2
echo Building with %b% cores.

::Increment & save the build number
set /p old=<rsrc/buildnumber.txt
set /A content=old+1
(echo %content%)>rsrc/buildnumber2.txt
cd rsrc
del buildnumber.txt
rename buildnumber2.txt buildnumber.txt

cd /D %BPP_ROOT%

::Increment the build number in the source code files
powershell -Command "(gc "%BPP_ROOT%/src/bpp.cpp") -replace 'v0.0.0.%old%', 'v0.0.0.%content%' | Out-File -encoding ASCII "%BPP_ROOT%/src/bpp.cpp""
powershell -Command "(gc "%BPP_ROOT%/rsrc/bpp.rc") -replace '%old%', '%content%' | Out-File -encoding ASCII "%BPP_ROOT%/rsrc/bpp.rc""

::Ok, the build has been set up. Let's actually compile the stuff now.
%BPP_COMPILER%/mingw64/bin/mingw32-make -f makefile.windows -j%b% x86_64 x86_64_v2 x86_64_v3 x86_64_v4 pentium lakemont pentium_mmx pentiumpro pentium2 pentium3 pentium3m pentium_m pentium4 pentium4m prescott nocona core2 nehalem westmere sandybridge ivybridge haswell broadwell skylake bonnell silvermont goldmont goldmont_plus tremont knl knm skylake_avx512 cannonlake icelake_client icelake_server cascadelake cooperlake tigerlake sapphirerapids alderlake rocketlake k6 k6_2 k6_3 athlon athlon_tbird athlon_4 athlon_xp athlon_mp k8 opteron athlon64 athlon_fx k8_sse3 opteron_sse3 athlon64_sse3 barcelona bdver1 bdver2 bdver3 bdver4 znver1 znver2 znver3 btver1 btver2