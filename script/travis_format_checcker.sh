#!/bin/sh

set -ue
cd -- "$(dirname -- "${0}")"

./codeformatter.sh

if find ../ | grep .orig$; then
	git diff
	echo Needs to run 'make format' locally!!!;
	exit 1
else
	echo Coding style seems fine.;
fi;

if git grep --cached -I $'\r'; then
	echo Do not use CRLF.
	echo Please convert to LF, Unix new line style.
	exit 1
else
	echo New line code seems fine.;
fi;
exit 0
