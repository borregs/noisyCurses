# Este .sh requiere que el equalizar cava este installado mediandte -$ make install
# Depende de gnome-terminal.

# si es root:
# sudo apt install gnome-terminal git && git clone https://github.com/karlstav/cava && cd cava && ./autogen && ./configure --enable-debug && make install
#
# Mas info sobre el equalizzador libre cava: https://github.com/karlstav/cava/blob/master/README.md

gnome-terminal -e "cava" --maximize
gnome-terminal --maximize --command "./noisy" --active
