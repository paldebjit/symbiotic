#!/bin/sh

set -e

cd $(dirname $0)

SUDO=
if [ which sudo &>/dev/null ]; then
	SUDO=sudo
else
	echo "Need root privileges:"
	SUDO="su -c"
fi

if which apt-get &>/dev/null; then
	$SUDO ./install-ubuntu.sh
elif which pacman &>/dev/null; then
	$SUDO ./install-arch.sh
elif which dnf &>/dev/null; then
	$SUDO ./install-fedora.sh
elif which yum &>/dev/null; then
	$SUDO ./install-fedora.sh
fi
