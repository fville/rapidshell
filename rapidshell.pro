TEMPLATE = subdirs
CONFIG = ordered
SUBDIRS = \
    rapidshell-svn \
    rapidshell-gui \
    rapidshell-app

rapidshell-app.depends = rapidshell-svn rapidshell-gui
rapidshell-gui.depends = rapidshell-svn
