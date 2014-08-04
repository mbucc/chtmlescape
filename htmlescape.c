#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Return the number of times the string needle appears in the string s.
size_t
count(const char *s, const char *needle)
{
	size_t	n = 0;
	size_t	needlesz = 0;

	if (!needle || strlen(needle) == 0)
		return n;

	if (!s || strlen(s) == 0)
		return n;

	if (strlen(needle) == 1)

		/*
		 * I'm guessing this is faster than strstr below.
		 */

		for (; *s; n += ( *s == needle[0] ), s++ );

	else {

		needlesz = strlen(needle);

		while ((s = strstr(s, needle))) {
			s += needlesz;
			n++;
		}
	}

	return n;
}

int
htmlescape(const char *src, char **dst)
{
	char		*p = 0;
	static char	*fromto[] = {
					"&",	"&amp;",
					"<",	"&lt;",
					">",	"&gt;",
					"\\\"",	"&quote;" };
	size_t		dstsz = 0;
	size_t		fromtosz = 0;
	size_t		i = 0;
	int		rval = 0;

	fromtosz = sizeof(fromto) / sizeof(fromto[0]);

	dstsz = strlen(src);

	for (i = 0; i < fromtosz; i += 2) {
		size_t sz0 = strlen(fromto[i]);
		size_t sz1 = strlen(fromto[i + 1]);
		dstsz += count(src, fromto[i]) * (sz1 - sz0);
	}

	if ( (*dst = calloc(dstsz + 1, 1)) == NULL)
		rval = ENOMEM;

	for (p = *dst; *src && !rval; src++) {

	
		for (i = 0; i < fromtosz; i += 2)

			if ( !strncmp(src, fromto[i], strlen(fromto[i] ) ) ) {

				memcpy(p, fromto[i + 1], strlen(fromto[i + 1]));

				p += strlen(p);

				src += strlen(fromto[i]) - 1;

				break;

			}

			if (i == fromtosz)

				*p++ = *src;

	}

	return rval;
}

