::set VCINSTALLDIR=D:\Visual Studio\VC

mkdir Dispel
xcopy /y ..\Dispel\Dispel.exe Dispel\
xcopy /y ..\DispelUi.exe .
xcopy /y ..\SNESTracereader.exe .

windeployqt.exe --no-translation --no-system-d3-compiler --no-opengl --no-svg --no-webkit --no-webkit2 --release SNESTracereader.exe
