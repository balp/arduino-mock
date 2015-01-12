#!/bin/sh

set -ue
cd -- "$(dirname -- "${0}")"

# astyle installed?
if hash astyle 2>/dev/null; then
	if astyle --version 2>&1 | grep 2.03; then
		echo astyle is found.
	else
		echo WARNING: astyle is found but it is not 2.03.
	fi
else
	echo "Please install astyle 2.03"
	echo "ex)"
	echo "  Linux: $ apt-get install astyle"
	echo "  Win: (Download from http://astyle.sourceforge.net )"
	echo "  MacOS:"
	echo "    $ brew tap ikeyasu/myversions"
	echo "    $ brew install astyle"
	exit 1
fi

astyle --mode=c --style=java --indent=spaces=2 --indent-classes --pad-oper ../include/*/*.h ../**/*.cc

if git grep --cached -I $'\r'; then
	echo Do not use CRLF.
	echo Please convert to LF, Unix new line style.
	exit 1
fi
