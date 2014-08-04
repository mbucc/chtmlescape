all: README

test:
	(cd regress ; make)


README: htmlescape.3
	groff -Tascii -man $? | sed -e 's/.//g' > t
	mv t README


man: ${MANDIR}/htmlescape.3


MANDIR=/usr/share/man/man3
${MANDIR}/%.3: %.3
	sudo cp $? $@	
