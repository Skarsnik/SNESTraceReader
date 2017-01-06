::change according to your installation
mkdir Dispel
xcopy /y ..\Dispel\Dispel.exe Dispel\
xcopy /y ..\DispelUi.exe .
xcopy /y ..\SNESTracereader.exe .

windeployqt.exe --no-translations --no-system-d3d-compiler --no-opengl --no-svg --no-webkit --no-webkit2 --release SNESTracereader.exe