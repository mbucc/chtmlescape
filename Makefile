test:
	(cd regress ; make test)

MANDIR=/usr/share/man/man3

man: ${MANDIR}/htmlescape.3

${MANDIR}/%.3: %.3
	sudo cp $? $@	