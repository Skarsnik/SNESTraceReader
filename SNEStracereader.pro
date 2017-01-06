#-------------------------------------------------
#
# Project created by QtCreator 2016-09-13T12:10:48
#
#-------------------------------------------------


TEMPLATE = subdirs

SUBDIRS = snestracergui.pro \
          Dispel/dispel.pro \
          dispelgui.pro


release {
    win32 {
        copyfordeploy.depends = $$IN_PWD/SNESTracer.exe \
                         $$IN_PWD/DispelUi.exe \
                         $$IN_PWD/Dispel/Dispel.exe
        copyfordeploy.commands = $(COPY) $$shell_path($$IN_PWD/*.exe) $$shell_path($$IN_PWD/deploy/)
        copyfordeploy.commands += $(COPY) $$shell_path($$IN_PWD/Dispel/Dispel.exe) $$shell_path($$IN_PWD/deploy/Dispel/)
        deploy.commands = $$shell_path($$IN_PWD/deploystuff.bat)
        deploy.depends = copyfordeploy
        QMAKE_EXTRA_TARGETS += deploy
        POST_TARGETDEPS = deploy
    }
}
