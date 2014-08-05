all: README

test:
	(cd regress ; make)


README: htmlescape.3
	echo "     --------------------------------------------------------------------" > t
	echo "     " >> t
	echo "     The man page below defines the interface for semantic versioning." >> t
	echo "     " >> t
	echo "     A participant in the clibs project." >> t
	echo "     See https://github.com/clibs/clib/wiki/Packages for more info." >> t 
	echo "     " >> t
	echo "                                             $$(date)" >> t
	echo "     --------------------------------------------------------------------" >> t
	@# Github won't render this in the browser.
	@# sed zaps any backspace characters (^H)
	@# and the one before it.
	groff -Tascii -man $? | sed -e 's/.//g' >> t
	mv t README


MANDIR=/usr/share/man/man3
man: ${MANDIR}/htmlescape.3

${MANDIR}/%.3: %.3
	sudo cp $? $@	
